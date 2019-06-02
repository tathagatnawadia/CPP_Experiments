#include "../includes/boilerplate.hpp"

template <class F, class... Args>
void for_each_argument(F f, Args&&... args) {
	[](...){}((f(std::forward<Args>(args)), 0)...);
}

// Creating templates to check for a pointer

int main()
{
	// Prints "hello123"
	for_each_argument (
		//Creating a lambda function "f" which takes all the arguments "args"
		[](const auto& x){
			if(x != 0)
				std::cout << *x << std::endl;
			else
				std::cout << x << std::endl;
		},

		"hello",
		1,
		2,
		3,
		new Person("Tathagat", "3888282882", "***asdf@gmail.com")
	);
	return 0;
}
