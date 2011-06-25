/*
 * TransactionBaseClientManager.cpp
 *
 *  Created on: 08/06/2011
 *      Author: victor
 */

#include "engine/engine.h"
#include "TransactionalBaseClientManager.h"

#include "engine/service/proto/BasePacket.h"
#include "engine/service/proto/BaseClient.h"

TransactionalBaseClientManager::TransactionalBaseClientManager() : Logger("TransactionalBaseClientManager") {
	setLogging(false);
	setGlobalLogging(false);
}

void TransactionalBaseClientManager::sendPacket(BasePacket* packet, BaseClient* baseClient) {
	//BaseClient* baseClient = packet->getClient()
	packet->setClient(baseClient);

	//VectorMap<BaseClient*, Vector<BasePacket*>*>* packetBuffer = getLocalBufferedPackets();

	Vector<BasePacket*>* buffer =  getLocalBufferedPackets();//packetBuffer->get(baseClient);

	/*if (buffer == NULL) {
		buffer = new Vector<BasePacket*>();
		packetBuffer->put(baseClient, buffer);
	}*/

	buffer->add(packet);
}

Vector<BasePacket*>* TransactionalBaseClientManager::getLocalBufferedPackets() {
	Vector<BasePacket*>* queue = bufferedPackets.get();

	if (queue == NULL) {
		queue = new Vector<BasePacket*>();
		//queue->setNoDuplicateInsertPlan();

		//info("message queue created");
		//queue->setNullValue(NULL);

		bufferedPackets.set(queue);
	}

	return queue;
}

void TransactionalBaseClientManager::execute() {
	//VectorMap<BaseClient*, Vector<BasePacket*>*>* queue = getLocalBufferedPackets();
	Vector<BasePacket*>* packetQueue = getLocalBufferedPackets();

	/*if (queue->size() > 0)
		info("sending " + String::valueOf(queue->size()) + " messages", true);*/

	for (int j = 0; j < packetQueue->size(); ++j) {
		//BasePacket* pack = queue->get(i);
		BasePacket* pack = packetQueue->get(j);

		BaseClient* baseClient = dynamic_cast<BaseClient*>(pack->getClient());

		pack->setClient(NULL);

		Locker locker(baseClient);

		if (!baseClient->isAvailable()) {
			//info("baseClient is not available", true);

			delete pack;

			continue;
		}

		try {
			if (pack->doSequencing()) {
				if (pack->size() >= 490) {
					if (baseClient->getRawBufferedPacket() != NULL) {
						baseClient->sendSequenced(baseClient->getRawBufferedPacket()->getPacket());
						baseClient->setNullBufferedPacket();
						//bufferedPacket = NULL;
					}

					baseClient->sendFragmented(pack);
				} else
					baseClient->bufferMultiPacket(pack);
			} else {
				baseClient->sendSequenceLess(pack);
			}
		} catch (...) {
			error("HUI CATCH (...)");
			baseClient->disconnect("unreported exception on sendPacket()", false);
		}
	}

	packetQueue->removeAll(1000, 100);
}

void TransactionalBaseClientManager::undo() {
	Vector<BasePacket*>* packetQueue = getLocalBufferedPackets();

	for (int j = 0; j < packetQueue->size(); ++j) {
		Message* message = packetQueue->get(j);

		delete message;
	}

	packetQueue->removeAll(1000, 100);
}
