#include <string>
#include <iostream>
#include <type_traits>
#include <vector>

namespace CPP14LanguageFeatures {
	auto func0()
	{
		return 0;
	}
	static_assert(std::is_same<decltype(func0()), int>(), "");
	auto func1()
	{
		std::string hello{"hello!"};
		return hello;
	}
	static_assert(std::is_same<decltype(func1()), std::string>(), "");






 	template<typename T>
 	struct SomeContainerWrapper
 	{
 		std::vector<const T*> vec;

 		typename std::vector<const T*>::iterator beginCPP03() const
 		{
 			return std::begin(vec)
 		}
 		auto beginCPP11() const -> decltype(std::begin(vec))
 		{
 			return std::begin(vec);
 		}
 		auto beginCPP14() const 
 		{ 
 			return std::begin(vec); 
 		}
 	};





 	template<typename T1, typename T2, typename T3>
 	auto complicatedFuncCPP11(T1 x, T2 y, T3 z) -> decltype((x*y)-(y*z))
 	{
 		return ((x*y)-(y*z));
 	}
 	template<typename T1, typename T2, typename T3>
 	auto complicatedFuncCPP14(T1 x, T2 y, T3 z)
 	{
 		return ((x*y)-(y*z));
 	}



 	
}


int main(){
	std::cout << "Testing c++14 an c++11 this sunday :)" << std::endl;
}