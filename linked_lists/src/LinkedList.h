#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkedListNode.h"

namespace practicecpp {

	template <class T>
	class LinkedList {
		public:
			LinkedList() : head(nullptr) {}

			int getSize();
			bool isEmpty();
			T getValueByIndex(int index);
			void pushFront(T value);
			T popFront();
			void pushBack(T value);
			T popBack();
			T getFirst();
			T getLast();
			void insert(int index, T value);
			void erase(int index);
			T getFromBack(int offset);
			void reverse();
			void removeValue(T value);

		private:
			LinkedListNode<T> *head;
	};

}

#endif /* LINKEDLIST_H_ */
