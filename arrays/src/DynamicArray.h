#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

namespace practicecpp {

	class DynamicArray {
		public:
			DynamicArray();

			int 	GetSize();
			int 	GetCapacity();
			bool 	IsEmpty();
			int 	GetByIndex(int index);
			void 	Push(int item);
			void 	Insert(int index, int item);
			void 	Prepend(int item);
			int 	Pop();
			void 	Delete(int index);
			void 	Remove(int item);
			int		Find(int item);
		private:
			int		size = 0;
			int 	capacity = 16;
			int		storage[];

			void 	Resize(int capacity);

	}; /* class DynamicArray */

} /* namespace practicecpp */


#endif /* DYNAMICARRAY_H_ */