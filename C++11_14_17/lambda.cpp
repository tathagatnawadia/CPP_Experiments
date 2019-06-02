#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

//Always use -pedantic while compiling

class Person{
private:
	std::string _name;
	std::string _mobile;
	std::string _email;
public:
	Person(){};
	Person(std::string name, std::string mobile, std::string email) : _name(name), _mobile(mobile), _email(email) {}
	~Person(){};
	friend std::ostream& operator<<(std::ostream &os, Person const &person);
};

std::ostream& operator<<(std::ostream &os, Person const &person)
{
	std::cout << "name : " << person._name << ", mobile : " << person._mobile << ", email : " << person._email;
	return os;
}

void run_within_for_each(std::function<void (int)> func, std::vector<int> myarray)
{
	for_each(myarray.begin(), myarray.end(), func);
}

auto func3 = [](auto input) { return input * input; };

int main()
{
	std::vector<int> myarray{1,2,3,4,5,6};
	std::vector<Person> myPersonArray;
	myPersonArray.push_back(Person("Tathagat Nawadia", "**********", "**********@gmail.com"));

    for (std::vector <Person>::iterator it = myPersonArray.begin(); it != myPersonArray.end(); ++it) {
         std::cout << (*it) << std::endl;
    }

	auto func1 = [](int y)
	{
		std::cout << y << std::endl;
	};

	auto func2 = [](int y)
	{
		std::cout << y * 2 << std::endl;
	};

	run_within_for_each(func1, myarray);
	run_within_for_each(func2, myarray);
	std::cout << "Square of 11 : " << func3(11) << std::endl;
	return 0;
}