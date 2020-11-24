#include "LinkedList.h"

namespace practicecpp {

	//TODO: empty list cases
	//TODO: out of bounds cases

	template <class T>
	int LinkedList<T>::getSize() {
		int size = 0;

		LinkedListNode<T> node = *head;
		while(node) {
			node = *node.getNext();
			size++;
		}

		return size;
	}

	template <class T>
	bool LinkedList<T>::isEmpty() {
		return head == nullptr;
	}

	template <class T>
	T LinkedList<T>::getValueByIndex(int index) {
		LinkedListNode<T> node = *head;
		int currentIndex = 0;

		while(node) {
			if (currentIndex == index) {
				return node.getData();
			}
			node = *node.getNext();
			currentIndex++;
		}

		return nullptr;
	}

	template <class T>
	void LinkedList<T>::pushFront(T value) {
		LinkedListNode<T> newHead = new LinkedListNode<T>(value);

		newHead.setNext(head);
		head = &newHead;
	}

	template <class T>
	T LinkedList<T>::popFront() {
		LinkedListNode<T> ret = *head;
		head = ret.getNext();

		return ret.getData();
	}

	template <class T>
	void LinkedList<T>::pushBack(T value) {
		LinkedListNode<T> newNode = new LinkedListNode<T>(value);
		LinkedListNode<T> node = *head;

		while(node.next()) {
			node = *node.getNext();
		}

		node.setNext(newNode);
	}

	template <class T>
	T LinkedList<T>::popBack() {
		LinkedListNode<T> node = *head;

		while(node.getNext().getNext() != nullptr) {
			node = *node.getNext();
		}

		T ret = node.getNext()->getData();

		node.setNext(nullptr);

		return ret;
	}

	template <class T>
	T LinkedList<T>::getFirst() {
		return head->getData();
	}

	template <class T>
	T LinkedList<T>::getLast() {
		LinkedListNode<T> node = *head;

		while(node.getNext()) {
			node = *node.getNext();
		}

		return node.getData();
	}

	template <class T>
	void LinkedList<T>::insert(int index, T value) {
		LinkedListNode<T> newNode = LinkedListNode<T>(value);
		LinkedListNode<T> node = *head;
		int i = 0;

		while(i < index && node.getNext()) {
			node = *node.getNext();
			i++;
		}

		LinkedListNode<T> oldNext = *node.getNext();
		node.setNext(newNode);
		newNode.setNext(oldNext);
	}

	template <class T>
	void LinkedList<T>::erase(int index) {
		LinkedListNode<T> node = *head;
		int currentIndex = 0;

		while(node) {
			if (currentIndex == index - 1) {
				node.setNext(node.getNext()->getNext());
			}
			node = node.getNext();
			currentIndex++;
		}
	}

	template <class T>
	T LinkedList<T>::getFromBack(int offset) {
		//TODO: better implementation
		LinkedListNode<T> node = *head;
		int size = this->getSize();
		return this->getValueByIndex(size - offset - 1);
	}

	template <class T>
	void LinkedList<T>::reverse() {

	}

	template <class T>
	void LinkedList<T>::removeValue(T value) {

	}
}

