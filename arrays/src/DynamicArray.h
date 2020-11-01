#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <memory>

namespace defaults {
	const int capacity = 16;
	const int growth_coefficient = 2;
}

namespace practicecpp {

	class DynamicArray {
		public:
			DynamicArray();

			int 	getSize();  						//size of current array
			int 	getCapacity();						//current capacity(length) of the underlying array object
			bool 	isEmpty();  						//does the array have any elements?
			int 	getByIndex(int index);				//returns the item at the index position
			void 	push(int item); 					//adds the item to the end of the array
			void 	insert(int index, int item);		//adds the item to the array at index position
			void 	prepend(int item);  				//inserts item at the start of the array
			int 	pop();  							//removed the last item from the array and returns it
			void 	deleteByIndex(int index);			//deletes the item at a given index
			void 	remove(int item);					//removes all occurrences of the item in an array
			int 	find(int item); 					//return the index of the first occurrence of a given item

		private:
			std::unique_ptr<int[]> arrayData;			//unique pointer to the underlying data array

			int 	size{0};							//size of the array (number of items)
			int 	capacity{defaults::capacity};		//capacity of the array (length of underlying array)

			void 	resize(int capacity);				//puts the data into an underlying array of the given length (capacity)
			void	assessCapacity();

	}; /* class DynamicArray */

} /* namespace practicecpp */


#endif /* DYNAMICARRAY_H_ */
