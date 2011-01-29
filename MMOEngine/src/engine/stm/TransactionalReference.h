/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef ENGINE_STM_TRANSACTIONALREFERENCE_H_
#define ENGINE_STM_TRANSACTIONALREFERENCE_H_

#include "Transaction.h"

namespace engine {
  namespace stm {

  	template<class O> class TransactionalReference {
		TransactionalObjectHeader<O>* header;

	public:
		TransactionalReference() {
			header = NULL;
		}

		TransactionalReference(O object) {
			setObject(object);
		}

		TransactionalReference(const TransactionalReference& ref) {
			header = ref.header;
		}

		TransactionalReference& operator=(const TransactionalReference& ref) {
			if (this == &ref)
				return *this;

			header = ref.header;

			return *this;
		}

		O operator=(O obj) {
			setObject(obj);

			return obj;
		}

		bool operator==(O obj) {
			return header == getHeader(obj);
		}

		bool operator!=(O obj) {
			return header != getHeader(obj);
		}

		O operator->() {
			return getForUpdate();
		}

		operator O() {
			return getForUpdate();
		}

		O get() {
			if (header != NULL)
				return header->get();
			else
				return NULL;
		}

		O getForUpdate() {
			if (header != NULL)
				return header->getForUpdate();
			else
				return NULL;
		}

		bool toBinaryStream(ObjectOutputStream* stream) {
			return get()->toBinaryStream(stream);
		}

		bool parseFromBinaryStream(ObjectInputStream* stream) {
			return getForUpdate()->parseFromBinaryStream(stream);
		}

	protected:
		TransactionalObjectHeader<O>* getHeader(O object) {
			if (object == NULL)
				return NULL;

			return Transaction::currentTransaction()->getHeader(object);
		}

		void setObject(O object) {
			header = getHeader(object);
		}
	};


  } // namespace stm
} // namespace engine

#endif /* ENGINE_STM_TRANSACTIONALREFERENCE_H_ */