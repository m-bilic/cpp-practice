#include "LinkedList.h"
#include <iostream>

namespace practicecpp {

	template <class T>
	int LinkedList<T>::getSize() {
		int size = 0;

		LinkedListNode<T> *node = head;
		while(node) {
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
		LinkedListNode<T> *node = head;
		int currentIndex = 0;

		while(node) {
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
		LinkedListNode<T> *newHead = new LinkedListNode<T>(value);

		newHead->setNext(head);
		head = newHead;
	}

	template <class T>
	T LinkedList<T>::popFront() {

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		LinkedListNode<T> *node = head;
		head = node->getNext();
		T ret = node->getData();

		delete node;

		return ret;
	}

	template <class T>
	void LinkedList<T>::pushBack(T value) {
		LinkedListNode<T> *newNode = new LinkedListNode<T>(value);
		LinkedListNode<T> *node = head;

		while(node->getNext()) {
			node = node->getNext();
		}

		node->setNext(newNode);
	}

	template <class T>
	T LinkedList<T>::popBack() {
		LinkedListNode<T> *node = head;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		while(node->getNext()->getNext()) {
			node = node->getNext();
		}

		T ret = node->getNext()->getData();
		delete node->getNext();
		node->setNext(nullptr);

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
		LinkedListNode<T> *node = head;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		while(node->getNext()) {
			node = node->getNext();
		}

		return node->getData();
	}

	template <class T>
	void LinkedList<T>::insert(int index, T value) {
		LinkedListNode<T> *node = head;
		int i = 0;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}

		while(i < index - 1 && node->getNext() != nullptr) {
			node = node->getNext();
			i++;
		}

		LinkedListNode<T> *oldNext = node->getNext();
		LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

		if(index == 0) {
			oldNext = head->getNext();
			head = newNode;
			newNode->setNext(oldNext);
		} else {
			if (i != index) {
				std::cout << "ERROR: Index is out of bounds!" << std::endl;
				exit(EXIT_FAILURE);
			}

			node->setNext(newNode);
			newNode->setNext(oldNext);
		}
	}

	template <class T>
	void LinkedList<T>::erase(int index) {
		LinkedListNode<T> *node = head;
		int currentIndex = 0;

		if (head == nullptr) {
			std::cout << "ERROR: List is empty!" << std::endl;
			return;
		}

		if(index == 0) {
			head = node->getNext();
			delete node;
			return;
		}

		while(node->getNext()) {
			if (currentIndex == index - 1) {
				LinkedListNode<T> *newNext = node->getNext()->getNext();
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
		LinkedListNode<T> *node = head;

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

		LinkedListNode<T> *retNode = head;
		while (node->getNext()) {
			node = node->getNext();
			retNode = retNode->getNext();
		}

		return retNode->getData();
	}

	template <class T>
	void LinkedList<T>::reverse() {
		LinkedListNode<T> *tmp, *prev, *next;

		if (head == nullptr)	return;

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
		LinkedListNode<T> *node = head;
		LinkedListNode<T> *prev = nullptr;

		while(node) {
			if (node->getData() == value) {
				if (prev == nullptr) {
					head = node->getNext();
				} else {
					prev->setNext(node->getNext());
				}
				delete node;
				break;
			}
			prev = node;
			node = node->getNext();
		}
	}
}
