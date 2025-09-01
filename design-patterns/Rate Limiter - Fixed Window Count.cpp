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
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Fixed Window
class RateLimiter {
private:
    int windowSize; // window size in seconds
    int maxRequests; // max number of requests allowed per window
    int currentWindowStart;
    int requestCount; // number of requests already made in current window

    int getCurrentTime() {
        auto now = system_clock::now();
        auto epoch = duration_cast<seconds>(now.time_since_epoch()).count();
        return epoch;
    }

public:
    RateLimiter(int windowSize, int maxRequests) {
        this->windowSize = windowSize;
        this->maxRequests = maxRequests;
        this->currentWindowStart = getCurrentTime();
        this->requestCount = 0;
    }

    bool allowRequest() {
        int currentTime = getCurrentTime();
        
        if (currentTime >= this->currentWindowStart + windowSize) {
            this->currentWindowStart = currentTime;
            this->requestCount = 0;
        }

        if (this->requestCount < this->maxRequests) {
            this->requestCount++;
            return true;
        }

        return false;
    }
};

void testAllowWithinLimit() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(2, 3); // 2s window, 3 requests max
    
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false); // 4th request rejected in same window
    cout << __func__ << " passed" << endl;
}

void testResetAfterWindow() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(2, 2); // 2s window, 2 requests max
    
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);

    this_thread::sleep_for(3s); // wait past window
    assert(rl.allowRequest() == true); // window reset
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);
    cout << __func__ << " passed" << endl;
}

void testBurstRequests() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(5, 5); // 5s window, 5 requests
    
    for (int i = 0; i < 5; i++) {
        assert(rl.allowRequest() == true);
    }
    assert(rl.allowRequest() == false); // 6th rejected
    cout << __func__ << " passed" << endl;
}

void testFailLargeBurst() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(10, 3); // 10s window, 3 requests
    
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false); // too many in same window
    cout << __func__ << " passed" << endl;
}

void runAllTests() {
    testAllowWithinLimit();
    testResetAfterWindow();
    testBurstRequests();
    testFailLargeBurst();

    cout << "All tests passed!" << endl;
}

int main() {
    runAllTests();
}
