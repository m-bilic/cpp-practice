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
		return size == 0;
	}

	int DynamicArray::getByIndex (int index) {
		//TODO: error handling
		return arrayData[index];
	}

	void DynamicArray::push(int item) {
		assessCapacity();
		arrayData[size] = item;
		size++;
	}

	void DynamicArray::insert(int index, int item) {
		//TODO: error handling
		assessCapacity();
		for (int i = size - 1; i <= index; i--) {
			arrayData[i+1] = arrayData[i];
		}
		arrayData[index] = item;
		size++;
	}

	void DynamicArray::prepend(int item) {
		insert(0, item);
	}

	int DynamicArray::pop() {
		int ret = arrayData[size - 1];
		size--;
		assessCapacity();
		return ret;
	}

	void DynamicArray::deleteByIndex(int index) {
		for (int i = index; i < size - 1; i++) {
			arrayData[i] = arrayData[i+1];
		}
		size--;
		assessCapacity();
	}

	void DynamicArray::remove(int item) {
		for (int i = 0; i < size; i++) {
			if (arrayData[i] == item)
				deleteByIndex(i);
		}
	}

	int DynamicArray::find(int item) {
		for (int i = 0; i < size; i++) {
			if (arrayData[i] == item)
				return i;
		}
		return -1;
	}

	void DynamicArray::resize(int newCapacity) {
		capacity = newCapacity;
		std::unique_ptr<int[] > newArrayData(new int[newCapacity]);
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
