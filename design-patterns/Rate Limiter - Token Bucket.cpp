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

// Token Bucket
class RateLimiter {
private:
    int capacity; // max tokens bucket can hold
    double fillRate; // rate at which tokens are added to bucket (tokens per sec)
    double tokens; // cureent num of available tokens
    long long lastRefillTime; // last time bucket was refilled

    long long getCurrentTime() {
        auto now = system_clock::now();
        auto epoch = duration_cast<milliseconds>(now.time_since_epoch()).count();
        return epoch;
    }

    void refill() {
        auto currentTime = getCurrentTime();
        double tokensToAdd = (currentTime - lastRefillTime) * fillRate;
        this->tokens = min((double)this->capacity, this->tokens + tokensToAdd);
        this->lastRefillTime = currentTime;
    }

public:
    RateLimiter(int capacity, double fillRate) {
        this->capacity = capacity;
        this->fillRate = fillRate;
        this->tokens = capacity;
        this->lastRefillTime = getCurrentTime();
    }

    bool allowRequest(int tokens = 1) {
        refill();

        if (this->tokens >= tokens) {
            this->tokens -= tokens;
            return true;
        }

        return false;
    }
};

void testInitialCapacity() {
    RateLimiter rl(5, 1);
    for (int i = 0; i < 5; i++) {
        assert(rl.allowRequest() == true);
    }
    assert(rl.allowRequest() == false);
    cout << __func__ << " passed" << endl;
}

void testRefillOverTime() {
    RateLimiter rl(5, 1);
    for (int i = 0; i < 5; i++) rl.allowRequest();
    assert(rl.allowRequest() == false);

    this_thread::sleep_for(2s);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == true);
    assert(rl.allowRequest() == false);
    cout << __func__ << " passed" << endl;
}

void testBucketCapacity() {
    RateLimiter rl(3, 10);
    for (int i = 0; i < 3; i++) rl.allowRequest();
    assert(rl.allowRequest() == false);

    this_thread::sleep_for(5s);
    int success = 0;
    for (int i = 0; i < 10; i++) {
        if (rl.allowRequest()) success++;
    }
    assert(success == 3); // cannot exceed capacity
    cout << __func__ << " passed" << endl;
}

void testPartialRequests() {
    RateLimiter rl(10, 2);
    assert(rl.allowRequest(5) == true);
    assert(rl.allowRequest(6) == false);

    this_thread::sleep_for(3s); // refill 6 tokens
    assert(rl.allowRequest(6) == true);
    cout << __func__ << " passed" << endl;
}

void runAllTests() {
    testInitialCapacity();
    testRefillOverTime();
    testBucketCapacity();
    testPartialRequests();

    cout << __func__ << " passed!" << endl;
}

int main() {
    runAllTests();
}
