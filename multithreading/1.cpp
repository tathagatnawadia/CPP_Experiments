#include <iostream>
#include <thread>

struct func
{
	int& i;
	func(int& i_) : i(i_){}
	void operator()() {
		for(int j=0; j<1000000000; ++j) {
			i = i + j;
		}
	}
};

class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
        if(!t.joinable())
        	throw std::logic_error("No thread");
    }
	~scoped_thread() {
		t.join();
	}
  	scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};


int main() {
	int some_local_state = 0;
	scoped_thread t(std::thread(func(some_local_state)));
    std::cout << "Hello world !!" << std::endl;
}