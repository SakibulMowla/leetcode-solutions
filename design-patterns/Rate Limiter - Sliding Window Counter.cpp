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

// Sliding Window Counter
class RateLimiter {
private:
    int windowSize;
    int maxRequests;
    int currentWindowCount;
    int prevWindowCount;
    int currentWindowStart;

    int getCurrentTime() {
        auto now = system_clock::now();
        auto epoch = duration_cast<seconds>(now.time_since_epoch()).count();
        return epoch;
    }

public:
    RateLimiter(int windowSize, int maxRequests) {
        this->windowSize = windowSize;
        this->maxRequests = maxRequests;
        this->prevWindowCount = 0;
        this->currentWindowCount = 0;
        this->currentWindowStart = getCurrentTime();
    }

    bool allowRequest() {
        int currentTime = getCurrentTime();
        int currentWindowSize = currentTime - currentWindowStart;

        if (currentWindowSize >= windowSize) {
            prevWindowCount = currentWindowCount;
            currentWindowCount = 0;
            currentWindowStart = currentTime;
            currentWindowSize = 0;
        }

        double weighted = 1.0 * prevWindowCount * (windowSize - currentWindowSize) / windowSize +
                          currentWindowCount;
        if (1.0 + weighted <= maxRequests) {
            currentWindowCount++;
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
    assert(rl.allowRequest() == false); // should reject 4th immediately
    cout << __func__ << " passed" << endl;
}

void testWindowReset() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(2, 2);

    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);

    this_thread::sleep_for(chrono::seconds(3)); // let old window fully expire
    assert(rl.allowRequest() == false); // still blocked because prevWindowCount=2

    this_thread::sleep_for(chrono::seconds(2)); // wait another window
    assert(rl.allowRequest() == true); // now allowed
    cout << __func__ << " passed" << endl;
}

void testSlidingEffect() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(4, 4); // window=4s, limit=4 requests

    assert(rl.allowRequest() == true);  // request 1 at t=0
    this_thread::sleep_for(chrono::seconds(2));
    assert(rl.allowRequest() == true);  // request 2 at t≈2
    assert(rl.allowRequest() == true);  // request 3 at t≈2
    assert(rl.allowRequest() == true);  // request 4 at t≈2
    assert(rl.allowRequest() == false); // request 5 blocked at t≈2

    this_thread::sleep_for(chrono::seconds(2)); // move to next window (t≈4)
    assert(rl.allowRequest() == false); // still blocked because prevWindowCount=4

    this_thread::sleep_for(chrono::seconds(4)); // let prev window fully decay
    assert(rl.allowRequest() == true); // finally allowed
    cout << __func__ << " passed" << endl;
}

void testMultipleWindows() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(3, 2);

    assert(rl.allowRequest() == true);   // 1st
    assert(rl.allowRequest() == true);   // 2nd
    assert(rl.allowRequest() == false);  // 3rd blocked

    this_thread::sleep_for(chrono::seconds(3));
    assert(rl.allowRequest() == false);  // still blocked at start of next window

    this_thread::sleep_for(chrono::seconds(3));
    assert(rl.allowRequest() == true);   // allowed once prev window decays
    cout << __func__ << " passed" << endl;
}

void testBurstRejection() {
    cout << __func__ << " running..." << endl;
    RateLimiter rl(5, 3);

    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);

    this_thread::sleep_for(chrono::seconds(5));
    assert(rl.allowRequest() == false); // still blocked at rollover

    this_thread::sleep_for(chrono::seconds(5));
    assert(rl.allowRequest() == true);  // finally allowed
    cout << __func__ << " passed" << endl;
}

void runAllTests() {
    testAllowWithinLimit();
    testWindowReset();
    testSlidingEffect();
    testMultipleWindows();
    testBurstRejection();

    cout << "All tests passed!" << endl;
}

int main() {
    runAllTests();
}
