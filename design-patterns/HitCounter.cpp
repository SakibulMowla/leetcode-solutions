// Question: https://codezym.com/question/6

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>
#include <thread>

using namespace std;

class Solution {
    // atomic to make thread safe
    vector<atomic<int>> pageVisits;

public:
    Solution(int totalPages) : pageVisits(totalPages) {
    }    

    void incrementVisitCount(int pageIndex) {
        if (pageIndex < 0 || pageIndex >= pageVisits.size()) {
            return;
        }

        pageVisits[pageIndex]++;
    }

    int getVisitCount(int pageIndex) {
        if (pageIndex < 0 || pageIndex >= pageVisits.size()) {
            return 0;
        }

        return pageVisits[pageIndex];
    }
};

void incrementWorker(Solution& sol, size_t pageIndex, int times) {
    for (int i = 0; i < times; ++i) {
        sol.incrementVisitCount(pageIndex);
    }
}

void runTest() {
    int totalPages = 2;
    int numThreads = 4;
    int incrementsPerThread = 100000;

    Solution solution(totalPages);

    vector<thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementWorker, ref(solution), i % totalPages, incrementsPerThread);
    }
    for (auto& t : threads) t.join();

    int expectedPage0 = (numThreads / 2) * incrementsPerThread;
    int expectedPage1 = (numThreads / 2) * incrementsPerThread;

    assert(solution.getVisitCount(0) == expectedPage0 && "Page 0 count incorrect");
    assert(solution.getVisitCount(1) == expectedPage1 && "Page 1 count incorrect");

    cout << "Test passed: visit counts are correct." << endl;
}

int main() {
    // Test cases to validate the solution
    runTest();

    return 0;
}
