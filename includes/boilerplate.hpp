#include <iostream>
#include <map>

class Person{
private:
	std::string _name;
	std::string _mobile;
	std::string _email;
	std::map<std::string, Person*> _relations;
public:
	Person(){};
	Person(std::string name, std::string mobile, std::string email) : _name(name), _mobile(mobile), _email(email) {}
	~Person(){};
	friend std::ostream& operator<<(std::ostream &os, Person const &person);
	void changeEmail(std::string);
	void addRelation(std::string, Person*);
};

std::ostream& operator<<(std::ostream &os, Person const &person)
{
	std::cout << "name : " << person._name << ", mobile : " << person._mobile << ", email : " << person._email << std::endl;
	std::cout << "relations" << std::endl; 
	for(auto const &relation : person._relations)
		std::cout << "name : " << relation.second->_name << ", relationship : " << relation.first << std::endl;
	return os;
}

void Person::changeEmail(std::string email) {
	_email = email;
}

void Person::addRelation(std::string relationName, Person* person){
	_relations[relationName] = person;
}