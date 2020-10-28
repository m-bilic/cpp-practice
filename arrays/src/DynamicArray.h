#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

namespace practicecpp {

	class DynamicArray {
		public:
			DynamicArray();

			int 	getSize();
			int 	getCapacity();
			bool 	isEmpty();
			int 	getByIndex(int index);
			void 	push(int item);
			void 	insert(int index, int item);
			void 	prepend(int item);
			int 	pop();
			void 	deleteByIndex(int index);
			void 	remove(int item);
			int 	find(int item);

		private:
			int 	size{0};
			int 	capacity{16};
			int 	storage[];

			void 	resize(int capacity);

	}; /* class DynamicArray */

} /* namespace practicecpp */


#endif /* DYNAMICARRAY_H_ */
