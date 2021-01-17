#include <iostream>
#include <assert.h>
#include "LinkedListTest.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

namespace practicecpp {
	void LinkedListTest::performTests() const {
		std::cout << "Tests start!";
		testGetSize();
		std::cout << "GetSize test successful!";
		testIsEmpty();
		std::cout << "IsEmpty test successful!";
		testGetValueByIndex();
		testGetFirst();
		testGetLast();
		testInsert();
		testErase();
		testGetFromBack();
		testReverse();
		testRemoveValue();
	}

	void LinkedListTest::testGetSize() const {
		practicecpp::LinkedList<int> list;

		assert(list.getSize() == 0);

		list.pushBack(1);

		assert(list.getSize() == 1);

		list.pushFront(2);

		assert(list.getSize() == 2);

		list.popBack();

		assert(list.getSize() == 1);

		list.popFront();

		assert(list.getSize() == 0);
	}

	void LinkedListTest::testIsEmpty() const {
		practicecpp::LinkedList<int> list;

		assert(list.isEmpty());

		list.pushBack(1);

		assert(!list.isEmpty());

		list.popFront();

		assert(list.isEmpty());
	}

	void LinkedListTest::testGetValueByIndex() const {
		practicecpp::LinkedList<int> list;

		list.pushBack(1 + 4);
		list.pushBack(2 + 4);
		list.pushBack(3 + 4);
		list.pushBack(4 + 4);

		assert(list.getValueByIndex(0) == 1 + 4);
		assert(list.getValueByIndex(1) == 2 + 4);
		assert(list.getValueByIndex(2) == 3 + 4);
		assert(list.getValueByIndex(3) == 4 + 4);

		list.pushFront(1);
		list.pushFront(2);
		list.pushFront(3);
		list.pushFront(4);

		assert(list.getValueByIndex(0) == 4);
		assert(list.getValueByIndex(1) == 3);
		assert(list.getValueByIndex(2) == 2);
		assert(list.getValueByIndex(3) == 1);
		assert(list.getValueByIndex(4) == 1 + 4);
		assert(list.getValueByIndex(5) == 2 + 4);
		assert(list.getValueByIndex(6) == 3 + 4);
		assert(list.getValueByIndex(7) == 4 + 4);
	}

	void LinkedListTest::testGetFirst() const {
		practicecpp::LinkedList<int> list;

		list.pushFront(1);
		assert(list.getFirst() == 1);
		list.pushFront(2);
		assert(list.getFirst() == 2);
		list.pushFront(3);
		assert(list.getFirst() == 3);
		list.pushBack(4);
		assert(list.getFirst() == 3);
		list.popFront();
		assert(list.getFirst() == 2);
		list.popFront();
		assert(list.getFirst() == 1);
		list.popFront();
		assert(list.getFirst() == 4);
	}

	void LinkedListTest::testGetLast() const {
		practicecpp::LinkedList<int> list;

		list.pushFront(1);
		assert(list.getLast() == 1);
		list.pushBack(2);
		assert(list.getLast() == 2);
		list.pushBack(3);
		assert(list.getLast() == 3);
		list.pushFront(4);
		assert(list.getLast() == 3);
		list.popBack();
		assert(list.getLast() == 2);
		list.popBack();
		assert(list.getLast() == 1);
		list.popBack();
		assert(list.getLast() == 4);
	}

	void LinkedListTest::testInsert() const {
		practicecpp::LinkedList<int> list;

		list.pushFront(1);
		list.pushFront(2);
		list.pushFront(3);
		list.pushFront(4);
		list.insert(2, 8);
		assert(list.getValueByIndex(2) == 8);
		assert(list.getSize() == 5);
		list.insert(0, 9);
		assert(list.getValueByIndex(0) == 9);
		assert(list.getSize() == 6);
		list.insert(2, 10);
		assert(list.getValueByIndex(0) == 10);
		assert(list.getSize() == 7);
	}

	void LinkedListTest::testErase() const {
		practicecpp::LinkedList<int> list;

		list.pushFront(1);
		list.pushFront(2);
		list.pushFront(3);
		list.pushFront(4);
		list.erase(2);
		assert(list.getValueByIndex(2) == 4);
		assert(list.getSize() == 3);

		list.erase(0);
		assert(list.getValueByIndex(0) == 2);
		assert(list.getSize() == 2);
	}

	void LinkedListTest::testGetFromBack() const {
		practicecpp::LinkedList<int> list;

		list.pushBack(1 + 4);
		list.pushBack(2 + 4);
		list.pushBack(3 + 4);
		list.pushBack(4 + 4);

		assert(list.getFromBack(3) == 1 + 4);
		assert(list.getFromBack(2) == 2 + 4);
		assert(list.getFromBack(1) == 3 + 4);
		assert(list.getFromBack(0) == 4 + 4);

		list.pushFront(1);
		list.pushFront(2);
		list.pushFront(3);
		list.pushFront(4);

		assert(list.getFromBack(7) == 4);
		assert(list.getFromBack(6) == 3);
		assert(list.getFromBack(5) == 2);
		assert(list.getFromBack(4) == 1);
		assert(list.getFromBack(3) == 1 + 4);
		assert(list.getFromBack(2) == 2 + 4);
		assert(list.getFromBack(1) == 3 + 4);
		assert(list.getFromBack(0) == 4 + 4);
	}

	void LinkedListTest::testReverse() const {
		practicecpp::LinkedList<int> list;

		list.pushBack(1 + 4);
		list.pushBack(2 + 4);
		list.pushBack(3 + 4);
		list.pushBack(4 + 4);

		list.reverse();

		assert(list.getValueByIndex(3) == 1 + 4);
		assert(list.getValueByIndex(2) == 2 + 4);
		assert(list.getValueByIndex(1) == 3 + 4);
		assert(list.getValueByIndex(0) == 4 + 4);
	}

	void LinkedListTest::testRemoveValue() const {
		practicecpp::LinkedList<int> list;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			list.pushBack(i + 5);
		}

		list.removeValue(2);
		assert(list.getSize() == noOfItems);

		list.removeValue(2 + 5);
		assert(list.getSize() == noOfItems - 1);
		for (int i = 0; i < list.getSize(); i++) {
			assert(list.getValueByIndex(i) != 2 + 5);
		}

		practicecpp::LinkedList<int> list2;
		for (int i = 0; i < noOfItems; i++) {
			list2.pushBack(2);
		}

		list2.removeValue(2);
		assert(list2.getSize() == 0);
	}
}
