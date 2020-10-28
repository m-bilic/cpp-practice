#include "DynamicArray.h"

namespace practicecpp {

	//constructor
	DynamicArray::DynamicArray()  {

	}

	int DynamicArray::getSize() {
		return size;
	}

	int DynamicArray::getCapacity() {
		return capacity;
	}

	bool DynamicArray::isEmpty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	int DynamicArray::getByIndex (int index) {
		return storage[index];
	}

	void DynamicArray::push(int item) {

	}

	void DynamicArray::insert(int index, int item) {

	}

	void DynamicArray::prepend(int item) {

	}

	int DynamicArray::pop() {
		int ret = storage[size - 1];
		size--;
		return ret;
	}

	void DynamicArray::deleteByIndex(int index) {

	}

	void DynamicArray::remove(int item) {

	}

	int DynamicArray::find(int item) {
		for (int i = 0; i++; ) {
			if (storage[i] == item)
				return i;
		}
		return -1;
	}

	void DynamicArray::resize(int capacity) {

	}

}
