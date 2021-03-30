#include "LinkedListQueue.h"

namespace practicecpp {
	template <class T>
	void LinkedListQueue<T>::enqueue(T value) {
		list->pushBack(value);
	}

	template <class T>
	T LinkedListQueue<T>::dequeue() {
		return list->popFront();
	}

	template <class T>
	void LinkedListQueue<T>::empty() {
		return list->isEmpty();
	}
}