#include "DynamicArray.h"

namespace practicecpp {

	//constructor
	DynamicArray::DynamicArray()  {

	}

	int DynamicArray::GetSize() {
		return size;
	}

	int DynamicArray::GetCapacity() {
		return capacity;
	}

	bool DynamicArray::IsEmpty() {
		if (size == 0)
			return true;
		else
			return false;
	}

	int DynamicArray::GetByIndex (int index) {
		return storage[index];
	}

	void DynamicArray::Push(int item) {

	}

	void DynamicArray::Insert(int index, int item) {

	}

	void DynamicArray::Prepend(int item) {

	}

	int DynamicArray::Pop() {
		int ret = storage[size - 1];
		size--;
		return ret;
	}

	void DynamicArray::Delete(int index) {

	}

	void DynamicArray::Remove(int item) {

	}

	int DynamicArray::Find(int item) {
		for (int i = 0; i++; ) {
			if (storage[i] == item)
				return i;
		}
		return -1;
	}

	void DynamicArray::Resize(int capacity) {

	}

}
