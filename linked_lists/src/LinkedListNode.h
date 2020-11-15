#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

namespace practicecpp {

	template <class T>

	class LinkedListNode {
		public:
			LinkedListNode(T& value) : next(nullptr), data(value) {}

			T getData() {return data;}
			LinkedListNode<T> *getNext() {return next;}
			void setData(T& value) {data = value;}
			void setNext(LinkedListNode<T> *nextNode) {next = nextNode;}
		private:
			LinkedListNode<T> *next;
			T data;
	};

}

#endif /* LINKEDLISTNODE_H_ */
