#include "LinkedList.h"
#include <iostream>

namespace practicecpp {

	template <class T>
	int LinkedList<T>::getSize() {
		int size = 0;

		if (head == nullptr)
			return 0;

		size++;

		LinkedListNode<T>* node = head;
		while (node != tail) {
			node = node->getNext();
			size++;
		}

		return size;
	}

	template <class T>
	bool LinkedList<T>::isEmpty() {
		return (head == nullptr);
	}

	template <class T>
	T LinkedList<T>::getValueByIndex(int index) {
		LinkedListNode<T>* node = head;
		int currentIndex = 0;

		while (node != nullptr) {
			if (currentIndex == index) {
				return node->getData();
			}
			node = node->getNext();
			currentIndex++;
		}

		std::cout << "ERROR: Index is out of bounds!" << std::endl;
		exit(EXIT_FAILURE);
	}

	template <class T>
	void LinkedList<T>::pushFront(T value) {
		LinkedListNode<T>* newHead = new LinkedListNode<T>(value);

		if (head == nullptr) {
			tail = newHead;
		}

		newHead->setNext(head);
		head = newHead;
	}

	template <class T>
	T LinkedList<T>::popFront() {

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		LinkedListNode<T>* node = head;
		head = node->getNext();
		T ret = node->getData();

		delete node;

		if (head == nullptr) {
			tail = nullptr;
		}

		return ret;
	}

	template <class T>
	void LinkedList<T>::pushBack(T value) {
		LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
		LinkedListNode<T>* node = tail;

		if (node == nullptr) {
			head = newNode;
			tail = newNode;
			return;
		}

		node->setNext(newNode);
		tail = newNode;
	}

	template <class T>
	T LinkedList<T>::popBack() {
		LinkedListNode<T>* node = head;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		if (node->getNext() == nullptr) {
			T ret = node->getData();
			head = nullptr;
			tail = nullptr;
			delete node;
			return ret;
		}
		else {
			while (node->getNext()->getNext()) {
				node = node->getNext();
			}
		}

		T ret = node->getNext()->getData();
		delete node->getNext();
		node->setNext(nullptr);
		tail = node;

		return ret;
	}

	template <class T>
	T LinkedList<T>::getFirst() {
		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return head->getData();
	}

	template <class T>
	T LinkedList<T>::getLast() {
		LinkedListNode<T>* node = head;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		while (node->getNext()) {
			node = node->getNext();
		}

		return node->getData();
	}

	template <class T>
	void LinkedList<T>::insert(int index, T value) {
		LinkedListNode<T>* node = head;
		int i = 0;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		while (i < index - 1 && node != tail) {
			node = node->getNext();
			i++;
		}

		LinkedListNode<T>* oldNext = node->getNext();
		LinkedListNode<T>* newNode = new LinkedListNode<T>(value);

		if (index == 0) {
			oldNext = head;
			head = newNode;
			newNode->setNext(oldNext);
		}
		else {
			if (i != index - 1) {
				std::cout << "ERROR: Index is out of bounds!" << std::endl;
				exit(EXIT_FAILURE);
			}

			if (node == tail) {
				tail = newNode;
			}

			node->setNext(newNode);
			newNode->setNext(oldNext);
		}
	}

	template <class T>
	void LinkedList<T>::erase(int index) {
		LinkedListNode<T>* node = head;
		int currentIndex = 0;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			return;
		}

		if (index == 0) {
			if (tail == head) {
				tail = nullptr;
			}
			head = node->getNext();
			delete node;
			return;
		}

		while (node != tail) {
			if (currentIndex == index - 1) {
				LinkedListNode<T>* newNext = node->getNext()->getNext();

				if (node->getNext() == tail) {
					tail = node;
				}

				delete node->getNext();
				node->setNext(newNext);
				return;
			}
			node = node->getNext();
			currentIndex++;
		}

		std::cout << "ERROR: Index is out of bounds!" << std::endl;
	}

	template <class T>
	T LinkedList<T>::getFromBack(int offset) {
		LinkedListNode<T>* node = head;

		for (int i = 0; i < offset; i++) {
			if (node == nullptr) {
				std::cout << "ERROR: Offset out of bounds!" << std::endl;
				exit(EXIT_FAILURE);
			}
			node = node->getNext();
		}

		if (node == nullptr) {
			std::cout << "ERROR: Offset out of bounds!" << std::endl;
			exit(EXIT_FAILURE);
		}

		LinkedListNode<T>* retNode = head;
		while (node->getNext()) {
			node = node->getNext();
			retNode = retNode->getNext();
		}

		return retNode->getData();
	}

	template <class T>
	void LinkedList<T>::reverse() {
		LinkedListNode<T>* tmp, * prev, * next;

		if (head == nullptr)	return;

		tail = head;

		prev = nullptr;
		next = head;

		do {
			tmp = next->getNext();
			next->setNext(prev);
			prev = next;
			next = tmp;
		} while (next);

		head = prev;
	}

	template <class T>
	void LinkedList<T>::removeValue(T value) {
		LinkedListNode<T>* node = head;
		LinkedListNode<T>* prev = nullptr;

		while (node) {
			tail = node;
			if (node->getData() == value) {
				LinkedListNode<T>* toRemove = node;
				node = node->getNext();
				if (prev == nullptr) {
					head = toRemove->getNext();
				}
				else {
					prev->setNext(toRemove->getNext());
				}
				delete toRemove;
				continue;
			}
			prev = node;
			node = node->getNext();
		}
	}
}
