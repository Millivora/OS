#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<bool> lock(false);

void criticalSection(int threadId) {
    bool expected = false;
    while (!lock.compare_exchange_strong(expected, true)) {
        expected = false;
    }

    std::cout << "Thread " << threadId << " entered critical section." << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));

    lock.store(false);
}

int main() {
    const int numThreads = 4;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(criticalSection, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
