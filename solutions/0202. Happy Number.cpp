// Time - O(log n)
// Memory - O(1)

class Solution {
private:
    int squareSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (seen.find(n) == seen.end()) {
            if (n == 1) {
                return true;
            }
            seen.insert(n);
            n = squareSum(n);
        }

        return false;
    }
};

// ------------------------------------------------------

// Time - O(log n)
// Memory - O(1)

class Solution {
private:
    int squareSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
public:
    bool isHappy(int n) {
        int slow = n, fast = squareSum(n);
        while (slow != fast) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }

        return fast == 1;
    }
};
