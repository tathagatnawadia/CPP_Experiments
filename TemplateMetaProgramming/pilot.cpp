// Template Metaprogramming (Compile Time)
// Refletion (Runtime)

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

/* Approx implementation of the vector class and fixed vector class */
/*

template <typename T>
class vector
{
public:
	void push_back(T);
	T& operator[] (size_t);
private:
	T* a;
	size_t = count;
};

template <typename T, int I>
class fixed_vector
{
public:
	void push_back(T);
	T& operator[] (size_t);
private:
	T a[I];
	size_t count;
};

*/

template <typename T>
T max(T a, T b) { return a > b ? a: b; }

void t_max()
{
	std::cout << max('a', 'b') << std::endl;
	std::cout << max(1.222, 1.) << std::endl;
	std::cout << max("apple", "oranges") << std::endl;
}


template <int I>
struct multiplyAndPrint
{
	multiplyAndPrint(int i){
		std::cout << I * i << std::endl;
	}
};

void t_multiplyAndPrint()
{
	multiplyAndPrint<3> map(4);
}

/* Template Specialization without using typenames in the template*/
template <typename T>
struct floatsAreSpecial
{
	floatsAreSpecial(T a) {
		std::cout << "Generic Constructor " << a << std::endl;
	}
};

template<>
struct floatsAreSpecial<float>
{
	floatsAreSpecial(float a) {
		std::cout << "Specialization for float " << a << std::endl;
	}
};

void t_floatsAreSpecial()
{
	floatsAreSpecial<int> a(199);
	floatsAreSpecial<float> b(1.2);
	floatsAreSpecial<std::string> c("hello world");
}

/* Partial Specialization */
template <typename To, typename From>
struct castAndPrint
{
	castAndPrint(From f) {
		std::cout << (To)f << std::endl;
	}
};

template<typename To>
struct castAndPrint<To, const char*>
{
	castAndPrint(const char* s){
		std::cout << (To)atoi(s) << std::endl;
	}
};

void t_castAndPrint()
{
	castAndPrint<int, float> a(1.33);
	castAndPrint<float, int> b(1.33);
	castAndPrint<char, int> c(68);
	castAndPrint<bool, int> d(0);
	castAndPrint<int, const char*> e("67");
	castAndPrint<char, const char*> f("67");
}

/* Base case of the starCounter and the recursive definition */
template <typename T>
struct starCounter
{
	static const int Value = 0;
};

template <typename U>
struct starCounter<U*>
{
	static const int Value = 1 + starCounter<U>::Value;
};

void t_starCounter()
{
	std::cout << starCounter<int>::Value << std::endl;
	std::cout << starCounter<int**>::Value << std::endl;
	std::cout << starCounter<int******>::Value << std::endl;
}

/* Normal factorial */
template <int T>
struct factorial
{
	static const int Value = T * factorial<T - 1>::Value;
};

template <>
struct factorial<1>
{
	static const int Value = 1;
};

void t_factorial()
{
	std::cout << factorial<10>::Value << std::endl;
}

/* Lnked list implementation */
struct Null {};

template <int Value_, typename Next_>
struct Node 
{
	static const int Value = Value_;
	typedef Next_ Next;
};

#define LIST1(I1) Node<I1, Null>
#define LIST2(I1, I2) Node<I1, LIST1(I2)>
#define LIST3(I1, I2, I3) Node<I1, LIST2(I2, I3)>
#define LIST4(I1, I2, I3, I4) Node<I1, LIST3(I2, I3, I4)>

template<typename List>
struct sum
{
	static const int Value = List::Value + sum<typename List::Next>::Value;
};

template<>
struct sum<Null>
{
	static const int Value = 0;
};

void t_LinkedList(){
	std::cout << sum< LIST4(1, 2, 3, 4) >::Value << std::endl;
}

/* Implementing static assert */
template <bool>
struct StaticAssert;

template<>
struct StaticAssert<true>{};

#define STATIC_ASSERT(e) StaticAssert<(e)>()

void t_staticAssert()
{
	STATIC_ASSERT(true);
	//STATIC_ASSERT(false);
}

/* Reflection */

// template<typename T> const type_info& typeid(T);

// class type_info
// {
// public:
// 	bool operator == (const type_info& rhs) const;
// 	bool operator != (const type_info& rhs) const;
// 	bool before(const type_info& rhs) const;
// 	const char* name() const;
// };

#include <typeinfo>

struct MyStruct {} myStruct;
void Foo(int, MyStruct) {}
int anInt;

struct MetaType
{
	virtual const char* Name() const = 0;
	virtual size_t SizeOf() const = 0;

	// virtual void* New() const = 0;
	// virtual void Delete(void* v) const = 0;
};

class Robot {
public:
	Robot() {}
	~Robot() {}
private:
	std::string farmName;
	bool isActive;
	int betallion;
};

struct IntMetaType : public MetaType
{
	virtual const char* Name() const { return "int"; }
	virtual size_t SizeOf() const { return sizeof(int); }
}int_MetaType;

struct CharMetaType : public MetaType
{
	virtual const char* Name() const { return "char*"; }
	virtual size_t SizeOf() const { return sizeof(char*); }
}char_MetaType;

struct RobotMetaType : public MetaType 
{
	virtual const char* Name() const { return "Robot"; }
	virtual size_t SizeOf() const { return sizeof(Robot); }
}robot_MetaType;

const MetaType& GetMetaType(int) { return int_MetaType; }
const MetaType& GetMetaType(const char*) { return char_MetaType; }
const MetaType& GetMetaType(const Robot) { return robot_MetaType; }
const MetaType& GetMetaType(const Robot*) { return robot_MetaType; }

void t_typeInfo()
{
	std::cout << typeid(anInt).name() << std::endl;
	std::cout << typeid(myStruct).name() << std::endl;
	std::cout << typeid(Foo).name() << std::endl;

	int a = 2;
	const char* b = "Nawadia";
	Robot* c;
	Robot d;

	std::cout << "name : " << GetMetaType(a).Name() << "\t size : " << GetMetaType(a).SizeOf() << std::endl;
	std::cout << "name : " << GetMetaType(b).Name() << "\t size : " << GetMetaType(b).SizeOf() << std::endl;
	std::cout << "name : " << GetMetaType(c).Name() << "\t size : " << GetMetaType(c).SizeOf() << std::endl;
	std::cout << "name : " << GetMetaType(d).Name() << "\t size : " << GetMetaType(d).SizeOf() << std::endl;

}


int main()
{
	//t_max();
	//t_multiplyAndPrint();
	//t_floatsAreSpecial();
	//t_castAndPrint();
	//t_starCounter();
	//t_factorial();
	//t_LinkedList();
	//t_staticAssert();
	t_typeInfo();
	return 0; 
}