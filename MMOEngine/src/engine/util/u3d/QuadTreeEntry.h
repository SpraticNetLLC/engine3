/*
 *	engine/util/u3d/QuadTreeEntry.h generated by engine3 IDL compiler 0.60
 */

#ifndef QUADTREEENTRY_H_
#define QUADTREEENTRY_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "system/lang/ref/Reference.h"

#include "system/lang/Math.h"

#include "system/util/SortedVector.h"

#include "engine/stm/TransactionalReference.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Vector3.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/util/u3d/QuadTreeNode.h"

namespace engine {
namespace util {
namespace u3d {

class QuadTreeEntry : public Observable {
public:
	QuadTreeEntry(QuadTreeNode* n = NULL);

	void notifyAddedToCloseObjects();

	void notifyRemovedFromCloseObjects();

	void addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate = true);

	QuadTreeEntry* getInRangeObject(int index);

	void removeInRangeObject(QuadTreeEntry* obj);

	void removeInRangeObject(int index);

	void removeInRangeObjects();

	bool containsInRangeObject(QuadTreeEntry* obj);

	bool isInRange(QuadTreeEntry* obj, float range);

	bool isInRange(float x, float y, float range);

	float getDistanceTo(QuadTreeEntry* obj);

	bool isInSWArea(QuadTreeNode* node);

	bool isInSEArea(QuadTreeNode* node);

	bool isInNWArea(QuadTreeNode* node);

	bool isInArea(QuadTreeNode* node);

	void notifyInsert(QuadTreeEntry* obj);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	void notifyDissapear(QuadTreeEntry* obj);

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	float getPreviousPositionX();

	float getPreviousPositionZ();

	float getPreviousPositionY();

	Vector3 getPosition();

	void setPosition(float x, float z, float y);

	void initializePosition(float x, float z, float y);

	int compareTo(QuadTreeEntry* obj);

	bool isInQuadTree();

	int inRangeObjectCount();

	TransactionalReference<QuadTreeNode*> getNode();

	unsigned long long getObjectID();

	float getRadius();

	bool isBounding();

	void setNode(QuadTreeNode* n);

	void setBounding();

	void setRadius(float rad);

	void clearBounding();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	QuadTreeEntry(DummyConstructorParameter* param);

	virtual ~QuadTreeEntry();

	friend class QuadTreeEntryHelper;
};

} // namespace u3d
} // namespace util
} // namespace engine

using namespace engine::util::u3d;

namespace engine {
namespace util {
namespace u3d {

class QuadTreeEntryImplementation : public ObservableImplementation {
protected:
	Coordinate coordinates;

	TransactionalReference<QuadTreeNode* > node;

	bool bounding;

	SortedVector<ManagedReference<QuadTreeEntry* > > closeobjects;

	float radius;

public:
	QuadTreeEntryImplementation(QuadTreeNode* n = NULL);

	QuadTreeEntryImplementation(DummyConstructorParameter* param);

	virtual void notifyAddedToCloseObjects();

	virtual void notifyRemovedFromCloseObjects();

	void addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate = true);

	QuadTreeEntry* getInRangeObject(int index);

	void removeInRangeObject(QuadTreeEntry* obj);

	void removeInRangeObject(int index);

	void removeInRangeObjects();

	bool containsInRangeObject(QuadTreeEntry* obj);

	virtual bool isInRange(QuadTreeEntry* obj, float range);

	bool isInRange(float x, float y, float range);

	float getDistanceTo(QuadTreeEntry* obj);

	bool isInSWArea(QuadTreeNode* node);

	bool isInSEArea(QuadTreeNode* node);

	bool isInNWArea(QuadTreeNode* node);

	bool isInArea(QuadTreeNode* node);

	virtual void notifyInsert(QuadTreeEntry* obj);

	virtual void notifyPositionUpdate(QuadTreeEntry* obj);

	virtual void notifyDissapear(QuadTreeEntry* obj);

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	float getPreviousPositionX();

	float getPreviousPositionZ();

	float getPreviousPositionY();

	Vector3 getPosition();

	void setPosition(float x, float z, float y);

	void initializePosition(float x, float z, float y);

	virtual int compareTo(QuadTreeEntry* obj);

	bool isInQuadTree();

	int inRangeObjectCount();

	TransactionalReference<QuadTreeNode*> getNode();

	virtual unsigned long long getObjectID();

	float getRadius();

	bool isBounding();

	void setNode(QuadTreeNode* n);

	void setBounding();

	void setRadius(float rad);

	void clearBounding();

	WeakReference<QuadTreeEntry*> _this;

	operator const QuadTreeEntry*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~QuadTreeEntryImplementation();

	Object* clone();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class QuadTreeEntry;
	friend class TransactionalObjectHandle<QuadTreeEntryImplementation*>;
};

class QuadTreeEntryAdapter : public ObservableAdapter {
public:
	QuadTreeEntryAdapter(QuadTreeEntryImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void notifyAddedToCloseObjects();

	void notifyRemovedFromCloseObjects();

	void addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate);

	QuadTreeEntry* getInRangeObject(int index);

	void removeInRangeObject(QuadTreeEntry* obj);

	void removeInRangeObject(int index);

	void removeInRangeObjects();

	bool containsInRangeObject(QuadTreeEntry* obj);

	bool isInRange(QuadTreeEntry* obj, float range);

	bool isInRange(float x, float y, float range);

	float getDistanceTo(QuadTreeEntry* obj);

	void notifyInsert(QuadTreeEntry* obj);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	void notifyDissapear(QuadTreeEntry* obj);

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	float getPreviousPositionX();

	float getPreviousPositionZ();

	float getPreviousPositionY();

	void setPosition(float x, float z, float y);

	void initializePosition(float x, float z, float y);

	int compareTo(QuadTreeEntry* obj);

	bool isInQuadTree();

	int inRangeObjectCount();

	unsigned long long getObjectID();

	float getRadius();

	bool isBounding();

	void setBounding();

	void setRadius(float rad);

	void clearBounding();

};

class QuadTreeEntryHelper : public DistributedObjectClassHelper, public Singleton<QuadTreeEntryHelper> {
	static QuadTreeEntryHelper* staticInitializer;

public:
	QuadTreeEntryHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<QuadTreeEntryHelper>;
};

} // namespace u3d
} // namespace util
} // namespace engine

using namespace engine::util::u3d;

#endif /*QUADTREEENTRY_H_*/
