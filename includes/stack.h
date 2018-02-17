namespace common {
	const int defaultSize = 1024;
	template <typename T>
	class Stack {
		public:
			Stack(int size = defaultSize) 
				: _capacity {capacity}, _size{0}, _elements { new T[_capacity]}
			{
			}
			Stack(const Stack & ss)
				: _capacity {ss._capacity}, _size{ ss._size}, _elements {new T[_capacity]}
			{
				for (int i = 0; i < _capacity; ++i) {
					_elements[i] = st._elements[i];
				}
			}
			~Stack()
			{
				delete[] _elements;
			}

			bool empty()
			{
				return (_size == 0);
			}

			void pop() 
			{
				if(empty())
					return;
				_size--;
			}

			void push( const T & obj)
			{
				if (_size == _capacity)
					return;
				_elements[_size++] = obj;
			}

			const T& top()
			{
				if(empty())
					return;
				return _elements[_size - 1];
			}

			int size()
			{
				return _size;
			}

			void print(std::ostream & out = std::cout)
			{
				for (int i = _size-1; i >=0 ; --i)
					out << _elements[i] << " ";
				out << std::endl;
			}
		private:
			int _size;
			int _capacity;
			T * _elements;
			Stack& operator=(const Stack & st);

			
	};	
}


