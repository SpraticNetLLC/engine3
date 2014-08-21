/*
 *	engine/util/Observable.cpp generated by engine3 IDL compiler 0.60
 */

#include "Observable.h"

#include "engine/log/Logger.h"

/*
 *	ObservableStub
 */

enum {RPC_NOTIFYOBSERVERS__INT_MANAGEDOBJECT_LONG_ = 6,RPC_REGISTEROBSERVER__INT_OBSERVER_,RPC_DROPOBSERVER__INT_OBSERVER_,RPC_GETOBSERVERCOUNT__INT_,RPC_ADDOBSERVABLECHILD__OBSERVABLE_,RPC_DROPOBSERVEABLECHILD__OBSERVABLE_};

Observable::Observable() : ManagedObject(DummyConstructorParameter::instance()) {
	ObservableImplementation* _implementation = new ObservableImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Observable");
}

Observable::Observable(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("Observable");
}

Observable::~Observable() {
}



void Observable::notifyObservers(unsigned int eventType, ManagedObject* arg1, long long arg2) {
	ObservableImplementation* _implementation = static_cast<ObservableImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVERS__INT_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyObservers(eventType, arg1, arg2);
}

void Observable::registerObserver(unsigned int eventType, Observer* observer) {
	ObservableImplementation* _implementation = static_cast<ObservableImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REGISTEROBSERVER__INT_OBSERVER_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observer);

		method.executeWithVoidReturn();
	} else
		_implementation->registerObserver(eventType, observer);
}

void Observable::dropObserver(unsigned int eventType, Observer* observer) {
	ObservableImplementation* _implementation = static_cast<ObservableImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DROPOBSERVER__INT_OBSERVER_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observer);

		method.executeWithVoidReturn();
	} else
		_implementation->dropObserver(eventType, observer);
}

int Observable::getObserverCount(unsigned int eventType) const {
	ObservableImplementation* _implementation = static_cast<ObservableImplementation*>(_getImplementationForRead());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETOBSERVERCOUNT__INT_);
		method.addUnsignedIntParameter(eventType);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getObserverCount(eventType);
}

void Observable::addObservableChild(Observable* observable) {
	ObservableImplementation* _implementation = static_cast<ObservableImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDOBSERVABLECHILD__OBSERVABLE_);
		method.addObjectParameter(observable);

		method.executeWithVoidReturn();
	} else
		_implementation->addObservableChild(observable);
}

void Observable::dropObserveableChild(Observable* observable) {
	ObservableImplementation* _implementation = static_cast<ObservableImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DROPOBSERVEABLECHILD__OBSERVABLE_);
		method.addObjectParameter(observable);

		method.executeWithVoidReturn();
	} else
		_implementation->dropObserveableChild(observable);
}

DistributedObjectServant* Observable::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* Observable::_getImplementationForRead() const {
	return _impl;
}

void Observable::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ObservableImplementation
 */

ObservableImplementation::ObservableImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


ObservableImplementation::~ObservableImplementation() {
}


void ObservableImplementation::finalize() {
}

void ObservableImplementation::_initializeImplementation() {
	_setClassHelper(ObservableHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ObservableImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Observable*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ObservableImplementation::_getStub() {
	return _this.get();
}

ObservableImplementation::operator const Observable*() {
	return _this.get();
}

void ObservableImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void ObservableImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void ObservableImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void ObservableImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void ObservableImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void ObservableImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void ObservableImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void ObservableImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Observable");

}

void ObservableImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ObservableImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ObservableImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedObjectImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0xe6687dd1: //Observable.observerEventMap
		TypeInfo<ObserverEventMap >::parseFromBinaryStream(&observerEventMap, stream);
		return true;

	case 0xc23a7ce7: //Observable.observableChildren
		TypeInfo<SortedVector<ManagedReference<Observable* > > >::parseFromBinaryStream(&observableChildren, stream);
		return true;

	}

	return false;
}

void ObservableImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ObservableImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ObservableImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0xe6687dd1; //Observable.observerEventMap
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ObserverEventMap >::toBinaryStream(&observerEventMap, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0xc23a7ce7; //Observable.observableChildren
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<SortedVector<ManagedReference<Observable* > > >::toBinaryStream(&observableChildren, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 2;
}

ObservableImplementation::ObservableImplementation() {
	_initializeImplementation();
	// engine/util/Observable.idl():  		observableChildren.setNoDuplicateInsertPlan();
	(&observableChildren)->setNoDuplicateInsertPlan();
}

void ObservableImplementation::notifyObservers(unsigned int eventType, ManagedObject* arg1, long long arg2) {
	// engine/util/Observable.idl():  		observerEventMap.notifyObservers(eventType, this, arg1, arg2);
	(&observerEventMap)->notifyObservers(eventType, _this.get(), arg1, arg2);
	// engine/util/Observable.idl():  		}
	for (	// engine/util/Observable.idl():  		for (int i = 0;
	int i = 0;
	i < (&observableChildren)->size();
 ++i) {
	// engine/util/Observable.idl():  			observableChildren.get(i).notifyObservers(eventType, arg1, arg2);
	(&observableChildren)->get(i)->notifyObservers(eventType, arg1, arg2);
}
}

void ObservableImplementation::registerObserver(unsigned int eventType, Observer* observer) {
	// engine/util/Observable.idl():  		observerEventMap.registerObserver(eventType, observer);
	(&observerEventMap)->registerObserver(eventType, observer);
}

void ObservableImplementation::dropObserver(unsigned int eventType, Observer* observer) {
	// engine/util/Observable.idl():  		observerEventMap.dropObserver(eventType, observer);
	(&observerEventMap)->dropObserver(eventType, observer);
}

int ObservableImplementation::getObserverCount(unsigned int eventType) const{
	// engine/util/Observable.idl():  		return observerEventMap.getObserverCount(eventType);
	return (&observerEventMap)->getObserverCount(eventType);
}

void ObservableImplementation::addObservableChild(Observable* observable) {
	// engine/util/Observable.idl():  		observableChildren.put(observable);
	(&observableChildren)->put(observable);
}

void ObservableImplementation::dropObserveableChild(Observable* observable) {
	// engine/util/Observable.idl():  		observableChildren.drop(observable);
	(&observableChildren)->drop(observable);
}

/*
 *	ObservableAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


ObservableAdapter::ObservableAdapter(Observable* obj) : ManagedObjectAdapter(obj) {
}

void ObservableAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_NOTIFYOBSERVERS__INT_MANAGEDOBJECT_LONG_:
		{
			notifyObservers(inv->getUnsignedIntParameter(), static_cast<ManagedObject*>(inv->getObjectParameter()), inv->getSignedLongParameter());
		}
		break;
	case RPC_REGISTEROBSERVER__INT_OBSERVER_:
		{
			registerObserver(inv->getUnsignedIntParameter(), static_cast<Observer*>(inv->getObjectParameter()));
		}
		break;
	case RPC_DROPOBSERVER__INT_OBSERVER_:
		{
			dropObserver(inv->getUnsignedIntParameter(), static_cast<Observer*>(inv->getObjectParameter()));
		}
		break;
	case RPC_GETOBSERVERCOUNT__INT_:
		{
			resp->insertSignedInt(getObserverCount(inv->getUnsignedIntParameter()));
		}
		break;
	case RPC_ADDOBSERVABLECHILD__OBSERVABLE_:
		{
			addObservableChild(static_cast<Observable*>(inv->getObjectParameter()));
		}
		break;
	case RPC_DROPOBSERVEABLECHILD__OBSERVABLE_:
		{
			dropObserveableChild(static_cast<Observable*>(inv->getObjectParameter()));
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void ObservableAdapter::notifyObservers(unsigned int eventType, ManagedObject* arg1, long long arg2) {
	(static_cast<Observable*>(stub))->notifyObservers(eventType, arg1, arg2);
}

void ObservableAdapter::registerObserver(unsigned int eventType, Observer* observer) {
	(static_cast<Observable*>(stub))->registerObserver(eventType, observer);
}

void ObservableAdapter::dropObserver(unsigned int eventType, Observer* observer) {
	(static_cast<Observable*>(stub))->dropObserver(eventType, observer);
}

int ObservableAdapter::getObserverCount(unsigned int eventType) const {
	return (static_cast<Observable*>(stub))->getObserverCount(eventType);
}

void ObservableAdapter::addObservableChild(Observable* observable) {
	(static_cast<Observable*>(stub))->addObservableChild(observable);
}

void ObservableAdapter::dropObserveableChild(Observable* observable) {
	(static_cast<Observable*>(stub))->dropObserveableChild(observable);
}

/*
 *	ObservableHelper
 */

ObservableHelper* ObservableHelper::staticInitializer = ObservableHelper::instance();

ObservableHelper::ObservableHelper() {
	className = "Observable";

	Core::getObjectBroker()->registerClass(className, this);
}

void ObservableHelper::finalizeHelper() {
	ObservableHelper::finalize();
}

DistributedObject* ObservableHelper::instantiateObject() {
	return new Observable(DummyConstructorParameter::instance());
}

DistributedObjectServant* ObservableHelper::instantiateServant() {
	return new ObservableImplementation();
}

DistributedObjectAdapter* ObservableHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ObservableAdapter(static_cast<Observable*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

