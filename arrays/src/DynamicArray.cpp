#include "DynamicArray.h"

namespace practicecpp {

	//constructor
	DynamicArray::DynamicArray()  {
		arrayData = std::unique_ptr<int[]>(new int[capacity]);
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
		return arrayData[index];
	}

	void DynamicArray::push(int item) {
		assessCapacity();
	}

	void DynamicArray::insert(int index, int item) {
		assessCapacity();
	}

	void DynamicArray::prepend(int item) {
		assessCapacity();
	}

	int DynamicArray::pop() {
		int ret = arrayData[size - 1];
		size--;
		return ret;
	}

	void DynamicArray::deleteByIndex(int index) {
		assessCapacity();
	}

	void DynamicArray::remove(int item) {
		assessCapacity();
	}

	int DynamicArray::find(int item) {
		for (int i = 0; i < size; i++) {
			if (arrayData[i] == item)
				return i;
		}
		return -1;
	}

	void DynamicArray::resize(int capacity) {
		int newArrayData[] = new int[capacity]();
		for (int i = 0; i < size; i++) {
			newArrayData[i] = arrayData[i];
		}
		arrayData = std::move(newArrayData);
	}

	void DynamicArray::assessCapacity() {
		if (size == capacity) {
			resize(capacity * defaults::growth_coefficient);
		}

		if (size * defaults::growth_coefficient * defaults::growth_coefficient <= capacity) {
			resize(capacity / defaults::growth_coefficient);
		}
	}
}
