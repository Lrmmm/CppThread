#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

// 线程函数
void myThreadFunction(int param) {
    std::cout << "Thread param: " << param << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {
    const int numThreads = 3000;
    std::vector<std::thread> threads;

    // 创建100个线程
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(myThreadFunction, i));
    }

    // 等待所有线程结束
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "All threads have finished." << std::endl;

    return 0;
}
