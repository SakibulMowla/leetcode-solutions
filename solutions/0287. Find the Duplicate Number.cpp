// Time - O(NlogN)
// Memory - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int num: nums) {
                if (num <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

// ---------------------------------------------------------------

// Time - O(32 * N)
// Memory - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << bit)) {
                    x++;
                }
                if (i > 0 && (i & (1 << bit))) {
                    y++;
                }
            }

            if (x > y) {
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};

// ---------------------------------------------------------------

// Time - O(N)
// Memory - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
