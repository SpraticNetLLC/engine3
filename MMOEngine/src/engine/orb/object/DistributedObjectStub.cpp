/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#include "engine/core/Core.h"

#include "engine/orb/DistributedObjectBroker.h"

#include "DistributedObjectStub.h"

DistributedObjectStub::DistributedObjectStub() : DistributedObject() {
	//_setImplementation(NULL);
		
	deployed = false;

	_classHelper = NULL;

	destroyed = false;

	#ifdef TRACE_REFERENCING
		finalizedTrace = NULL;
	#endif
}

DistributedObjectStub::~DistributedObjectStub() {
	if (!destroyed)
		undeploy();
	
	#ifdef TRACE_REFERENCING
		for (int i = 0; i < traces.size(); ++i) {
			StackTrace* trace = traces.get(i);
			delete trace;
		}
	
		delete finalizedTrace;
		finalizedTrace = NULL;
	#endif
}

/*DistributedObjectStub* DistributedObjectStub::clone() {
	return new DistributedObjectStub(*this);
}*/

void DistributedObjectStub::deploy() {
	if (_getImplementation() == NULL)
		throw Exception("unable to deploy object");
	
	Core::getObjectBroker()->deploy(this);
	
	deployed = true;

	destroyed = false;
}

void DistributedObjectStub::deploy(const char* name) {
	if (_getImplementation() == NULL)
		throw Exception("unable to deploy object");

	Core::getObjectBroker()->deploy(name, this);

	deployed = true;

	destroyed = false;
}

void DistributedObjectStub::deploy(const String& name) {
	if (_getImplementation() == NULL)
		throw Exception("unable to deploy object");
	
	Core::getObjectBroker()->deploy(name, this);

	deployed = true;

	destroyed = false;
}

void DistributedObjectStub::deploy(const String& name, uint64 nid) {
	StringBuffer nameid;
	nameid << name << nid;
	
	deploy(nameid.toString());

	destroyed = false;
}

bool DistributedObjectStub::undeploy() {
	/*if (destroyed)
		assert(0 && "destroying again a destroyed object");*/

	if (deployed) {
		/*ObjectBroker* broker = Core::getObjectBroker();

		if (broker != NULL)
			broker->undeploy(_name);*/

		//this is called when the object is deleted from RAM (MemoryManager deletes it)
		//so object broker is long gone as command
		DistributedObjectBroker::instance()->undeploy(_name);

		deployed = false; 
	} else {
		//if (_getImplementation() == NULL)
			//throw ObjectNotLocalException(this);
		
		//ObjectBroker::instance()->info("deleting undeployed implementation");
		
#ifndef WITH_STM
		_setImplementation(NULL);
#endif
		//_setImplementation(NULL);
	}
	
	destroyed = true;

	return true;
}

void DistributedObjectStub::finalize() {
	#ifdef TRACE_REFERENCING
		if (finalizedTrace != NULL) {
			System::out << "ERROR - object already finalized at\n";
		
			StackTrace::printStackTrace();
		
			System::out << "finalized by\n";
		
			finalizedTrace->print();
	
			raise(SIGSEGV);		
		}

		finalizedTrace = new StackTrace();
	#endif

	Object::finalize();
}
/*
void DistributedObjectStub::acquire() {
	#ifdef TRACE_REFERENCING
		traces.add(new StackTrace());
	#endif
		
	Object::acquire();
		
*/	/*StringBuffer msg;
	msg << "[" << _getName() << "] acquired (" << getReferenceCount() << ")";
	Logger::console.info(msg);*//*
}
	
void DistributedObjectStub::release() {
	#ifdef TRACE_REFERENCING
		traces.add(new StackTrace());

		if (getReferenceCount() < 1) {
			printReferenceTrace();

			raise(SIGSEGV);
		}
	#endif

*/	/*StringBuffer msg;
	msg << "[" << _getName() << "] released (" << getReferenceCount() - 1 << ")";
	Logger::console.info(msg);*//*

	Object::release();
}
	*/
void DistributedObjectStub::printReferenceTrace() const {
	System::out << "ERROR - reference count getting under zero\n";

	#ifdef TRACE_REFERENCING
		for (int i = 0; i < traces.size(); ++i) {
			StackTrace* trace = traces.get(i);
		
			Logger::console.info("--------------------------------------------------------------------------", true);
		
			trace->print();
			/*String traceoutput;
			trace->getStackTrace(traceoutput);
		
			Logger::console.info(traceoutput, true);*/
		}
	#endif
}
