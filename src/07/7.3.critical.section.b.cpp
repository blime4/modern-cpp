


#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section(int change_v){
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);

    // do something operations
    v = change_v;
    std::cout<< v << std::endl;
    // release the lock
    lock.unlock();

    // duriing this period
    // others are allowed to acquire v

    // start another group of contention operations
    // lock again
    lock.lock();
    v += 1;
    std::cout << v << std::endl;
    // mtx will be destructed when exit this region
}

int main(){
    std::thread t1(critical_section,2), t2(critical_section,3);
    t1.join();
    t2.join();

    std::cout << v << std::endl;
    return 0;
}