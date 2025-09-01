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
#include <stdexcept>
#include <iomanip>
#include <deque>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

// Sliding Window Log
class RateLimiter {
private:
    int windowSize; // size of the window in seconds
    int maxRequests; // max number of requests allowed during window
    deque<int> timestamps; // list of allowed requests' timestamps

    int getCurrentTime() {
        auto now = system_clock::now();
        auto epoch = duration_cast<seconds>(now.time_since_epoch()).count();
        return epoch;
    }

public:
    RateLimiter(int windowSize, int maxRequests) {
        this->windowSize = windowSize;
        this->maxRequests = maxRequests;
        this->timestamps.clear();
    }

    bool allowRequest() {
        int currentTime = getCurrentTime();

        while (!timestamps.empty() && currentTime - windowSize >= timestamps.front()) {
            timestamps.pop_front();
        }

        if (timestamps.size() < maxRequests) {
            timestamps.push_back(currentTime);
            return true;
        }

        return false;
    }
};

void testAllowWithinLimit() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(3, 3); // 3s window, max 3 requests

    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false); // 4th rejected
    cout << __func__ << " passed" << endl;
}

void testSlidingExpiry() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(2, 2); // 2s window, max 2 requests

    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);

    this_thread::sleep_for(3s); // old requests expire
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);
    cout << __func__ << " passed" << endl;
}

void testBurstRejection() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(5, 5); // 5s window, 5 allowed

    for (int i = 0; i < 5; i++) {
        assert(rl.allowRequest() == true);
    }
    assert(rl.allowRequest() == false); // 6th rejected
    cout << __func__ << " passed" << endl;
}

void testBoundaryBehavior() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(2, 2);

    assert(rl.allowRequest() == true);
    this_thread::sleep_for(2s); // first request falls out
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);
    cout << __func__ << " passed" << endl;
}


void runAllTests() {
    testAllowWithinLimit();
    testSlidingExpiry();
    testBurstRejection();
    testBoundaryBehavior();

    cout << "All tests passed!" << endl;
}

int main() {
    runAllTests();
}
