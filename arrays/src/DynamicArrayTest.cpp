#include "DynamicArrayTest.h"
#include "DynamicArray.h"
#include <iostream>
#include <assert.h>

namespace practicecpp {
	void DynamicArrayTest::performTests() const {
		testGetSize();
		testPop();
		testCapacity();
		testIsEmpty();
		testGetByIndex();
		testInsert();
		testPrepend();
		testDeleteByIndex();
		testRemove();
		testFind();
	}

	void DynamicArrayTest::testGetSize() const {
		practicecpp::DynamicArray testArray;
		assert(testArray.getSize() == 0);

		int noOfItems = 45;

		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i);
		}

		assert(testArray.getSize() == noOfItems);
	}

	void DynamicArrayTest::testCapacity() const {
		practicecpp::DynamicArray testArray;
		//initial capacity
		assert(testArray.getCapacity() == defaults::capacity);

		//up to initial capacity, but not over
		int noOfItems = defaults::capacity;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i);
		}
		assert(testArray.getCapacity() == defaults::capacity);

		//over initial capacity
		noOfItems = defaults::capacity + 1;
		for (int i = testArray.getSize(); i < noOfItems; i++) {
			testArray.push(i);
		}
		assert(testArray.getCapacity() == defaults::capacity * defaults::growth_coefficient);

		//over next capacity threshold
		noOfItems = defaults::capacity * defaults::growth_coefficient + 1;
		for (int i = testArray.getSize(); i < noOfItems; i++) {
			testArray.push(i);
		}
		assert(testArray.getCapacity() == defaults::capacity * defaults::growth_coefficient * defaults::growth_coefficient);

		//down to lower threshold, but not over
		noOfItems = defaults::capacity + 1;
		for (int i = testArray.getSize() - 1; i >= noOfItems; i--) {
			testArray.pop();
		}
		assert(testArray.getCapacity() == defaults::capacity * defaults::growth_coefficient * defaults::growth_coefficient);

		//over lower threshold
		testArray.pop();
		assert(testArray.getCapacity() == defaults::capacity * defaults::growth_coefficient);

		//down to lower threshold, but not over
		noOfItems = defaults::capacity / 2 + 1;
		for (int i = testArray.getSize() - 1; i >= noOfItems; i--) {
			testArray.pop();
		}
		assert(testArray.getCapacity() == defaults::capacity * defaults::growth_coefficient);

		//over lower threshold
		testArray.pop();
		assert(testArray.getCapacity() == defaults::capacity);

		//down to zero
		for (int i = testArray.getSize() - 1; i >= 0; i--) {
			testArray.pop();
		}
		assert(testArray.getCapacity() == defaults::capacity);
	}

	void DynamicArrayTest::testIsEmpty() const {
		practicecpp::DynamicArray testArray;
		assert(testArray.isEmpty());

		testArray.push(1);
		assert(!testArray.isEmpty());

		testArray.pop();
		assert(testArray.isEmpty());
	}

	void DynamicArrayTest::testGetByIndex() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;

		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		assert(testArray.getByIndex(0) == 5);
		assert(testArray.getByIndex(1) == 1 + 5);
		assert(testArray.getByIndex(2) == 2 + 5);
		assert(testArray.getByIndex(3) == 3 + 5);
		assert(testArray.getByIndex(4) == 4 + 5);
	}

	void DynamicArrayTest::testPop() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		int item = testArray.pop();
		assert(item == noOfItems - 1 + 5);
		assert(testArray.getSize() == noOfItems - 1);

		item = testArray.pop();
		assert(item == noOfItems - 2 + 5);
		assert(testArray.getSize() == noOfItems - 2);

		item = testArray.pop();
		assert(item == noOfItems - 3 + 5);
		assert(testArray.getSize() == noOfItems - 3);

		item = testArray.pop();
		assert(item == noOfItems - 4 + 5);
		assert(testArray.getSize() == noOfItems - 4);

		item = testArray.pop();
		assert(item == noOfItems - 5 + 5);
		assert(testArray.getSize() == noOfItems - 5);
	}

	void DynamicArrayTest::testDeleteByIndex() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		testArray.deleteByIndex(2);
		assert(testArray.getByIndex(2) == 3 + 5);
		assert(testArray.getSize() == noOfItems - 1);

		testArray.deleteByIndex(2);
		assert(testArray.getByIndex(2) == 4 + 5);
		assert(testArray.getSize() == noOfItems - 2);

		testArray.deleteByIndex(2);
		assert(testArray.getSize() == noOfItems - 3);

		testArray.deleteByIndex(0);
		assert(testArray.getByIndex(0) == 1 + 5);
		assert(testArray.getSize() == noOfItems - 4);

		testArray.deleteByIndex(0);
		assert(testArray.getSize() == noOfItems - 5);
	}

	void DynamicArrayTest::testRemove() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		testArray.remove(2);
		assert(testArray.getSize() == noOfItems);

		testArray.remove(2 + 5);
		assert(testArray.getSize() == noOfItems - 1);
		for (int i = 0; i < testArray.getSize(); i++) {
			assert(testArray.getByIndex(i) != 2 + 5);
		}

		practicecpp::DynamicArray testArray2;
		for (int i = 0; i < noOfItems; i++) {
			testArray2.push(2);
		}

		testArray2.remove(2);
		assert(testArray2.getSize() == 0);
	}

	void DynamicArrayTest::testFind() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		int result = testArray.find(2);
		assert(result == -1);

		result = testArray.find(2 + 5);
		assert(result == 2);
	}

	void DynamicArrayTest::testInsert() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		testArray.insert(2, 2);
		assert(testArray.getByIndex(2) == 2);
		assert(testArray.getSize() == noOfItems + 1);
	}

	void DynamicArrayTest::testPrepend() const {
		practicecpp::DynamicArray testArray;

		int noOfItems = 5;
		for (int i = 0; i < noOfItems; i++) {
			testArray.push(i + 5);
		}

		testArray.prepend(2);
		assert(testArray.getByIndex(0) == 2);
		assert(testArray.getSize() == noOfItems + 1);
	}
}
