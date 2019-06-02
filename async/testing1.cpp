#include <iostream>
#include <thread>
#include <vector>

using namespace std;

struct Person {
	std::string name;
	std::string mobile;
	std::string email;
	Person(){}
	Person(std::string name, std::string email, std::string mobile) : name(name), mobile(mobile), email(email) {}
};
std::vector<Person> person;
void function_1() {
	
}

int main() {
	std::thread t1(function_1);
	t1.detach();

	return 0;
}