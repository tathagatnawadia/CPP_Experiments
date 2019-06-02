#include <iostream>
#include <vector>
#include <future>
#include <numeric> 
#include <algorithm>  // g++ -std=c++14 -pthread parallel_sum.cpp

 
using namespace std;
 
// generic
template <typename TYPE>
int parallel_sum(TYPE beg, TYPE end) {
    // block size
    auto len = end - beg;
    if (len < 500) {
        // if block is small enough, it is faster to just sum them up.
        return std::accumulate(beg, end, 0);
    }
    // (beg + end) / 2 may overflow
    auto mid = beg + len / 2;
    // sum the left part asynchronously 
    auto handle_left = std::async(launch::async, parallel_sum<TYPE>, beg, mid);
    // sum the right part asynchronously 
    auto handle_right = std::async(launch::async, parallel_sum<TYPE>, mid, end);
    // put them together
    return handle_left.get() + handle_right.get();
}
 
int main() {
    vector<int> v(10000000000, 1);
    cout << "Sum: " << parallel_sum(v.begin(), v.end()) << endl;
}
