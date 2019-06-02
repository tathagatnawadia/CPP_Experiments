#include <string>
#include <iostream>
#include <type_traits>
#include <vector>

namespace CPP14LanguageFeatures {
	constexpr int computeSomething(int mX)
	{
		int result{mX};
		for (int i{0}; i < 10; i++)
			result += i;
		if(result > 5) result += 10;
		return result;
	}

	template<int TValue>
	struct Test
	{
		
	};
	Test<computeSomething(10)> instance;
}


int main(){
	std::cout << "Testing c++14 an c++11 this sunday :)" << std::endl;
}