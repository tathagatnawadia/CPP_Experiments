#include <fstream>
#include <iostream>
#include "../includes/boilerplate.hpp"

void write(const std::string& file_name, Person& data) // Writes the given OBJECT data to the given file name.
{
    std::ofstream out;
    out.open(file_name,std::ios::binary);
    out.write(reinterpret_cast<char*>(&data), sizeof(Person));
    out.close();
};

void read(const std::string& file_name, Person& data) // Reads the given file and assigns the data to the given OBJECT.
{
    std::ifstream in;
    in.open(file_name,std::ios::binary);
    in.read(reinterpret_cast<char*>(&data), sizeof(Person));
    in.close();
};

int main() {
    Person *son = new Person("Ben", "**********", "**********@icloud.com");
    son->addRelation("father", new Person("Ross Geller", "**********", "********@gmail.com") );
    write("son.bak", *son);

    Person backuprecovery;
    read("son.bak", backuprecovery);
    std::cout << backuprecovery << std::endl;

    return 0;
}

