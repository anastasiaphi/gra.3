
#include <iostream>
#include <syncstream>
#include <vector>
#include <thread>

#include "operations.h"
using namespace std;
int main()
{ 
    cout << "calculation started\n";
    
    vector<jthread> threads;
    threads.reserve(NT);

    for (int threads_id = 0; threads_id < NT; ++threads_id)
        threads.emplace_back(worker, threads_id);

    cout << "calculation finished\n";
    
    return 0;
}
