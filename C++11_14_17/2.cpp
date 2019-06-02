#include <string>
#include <iostream>
#include <type_traits>
#include <vector>

namespace CPP14LanguageFeatures {

	auto func3()
	{
		static std::string test{"test"};
		auto& result(test);
		return result;
	}
	static_assert(std::is_same<decltype(func3()), std::string>(), "");

	decltype(auto) func4()
	{
		static std::string testagain{"testagain"};
		auto& result(testagain);
		return result;
	}
	static_assert(std::is_same<decltype(func4()), std::string&>(), "");

	decltype(auto) func5()
	{
		std::string test{"testing"};
		return std::move(test);
	}
	static_assert(std::is_same<decltype(func5()), std::string&&>(), "");
 	
}


int main(){
	std::cout << "Testing c++14 an c++11 this sunday :)" << std::endl;
}