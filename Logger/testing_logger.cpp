#define LOGGING_LEVEL_1
#include "logger.hpp"
#include <vector>
 
int main() 
{
	LOG_DEBUG("Starting the application !!");
	std::vector<int> myarray{ 3, 1, 4 };
	int sum = 0;
	try {
		int i = 0;
		auto it = myarray.begin();
		LOG_WARN("You are trying to trigger a unending while loop.");
		while(true){
			sum = sum + myarray.at(i++);
			LOG_DEBUG("Reading", *it);
			it = std::next(it, 1);
		}
	}
	catch(...){
		LOG_ERR("Array out of bounds !!");
	}
	LOG_DEBUG("SUM=",sum);
    return 0;
}