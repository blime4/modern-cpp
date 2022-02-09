#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

int main(){
    std::queue<int> productrd_nums;
    std::mutex mtx;
    std::condition_variable cv;
    bool notified = false;

    auto producer = [&](){
        for(int i=0;;i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "Producing " << i << std::endl;
            
        }
    }
}