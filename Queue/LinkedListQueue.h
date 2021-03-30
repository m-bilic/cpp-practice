#pragma once
#ifndef LINKEDLISTQUEUE_H_
#define LINKEDLISTQUEUE_H_

#include "../LinkedList/LinkedList.h"

namespace practicecpp {

	template <class T>
	class LinkedListQueue {
	public:
		LinkedListQueue() : list(new LinkedList<T>()) {}
		
		void enqueue(T value);
		T dequeue();
		void empty();
		
	private:
		LinkedList<T>* list;
	};

}

#endif /* LINKEDLISTQUEUE_H_ */