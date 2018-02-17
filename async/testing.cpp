#include <iostream>
#include <future>

using namespace std;

std::mutex mu;
std::condition_variable cond;

int factorial(std::future<int> n) {
	if (n == 1) return 1;
	else return (n * factorial(n-1));
}

int main() {

	int x;
	std::promise<int> p;
	std::future f = p.get_future();

	std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));
	x = fu.get();

	return 0;
}