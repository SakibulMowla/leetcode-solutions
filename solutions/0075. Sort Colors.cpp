// Two Iterations

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (auto num: nums) {
            cnt[num]++;
        }

        int pointer = 0;
        for (auto& num: nums) {
            while (cnt[pointer] == 0) {
                pointer++;
            }
            cnt[pointer]--;
            num = pointer;
        }

        return;
    }
};

// -----------------------------------------------------------------------------------------------

// One Iteration

using VI = vector<int>;

class Solution {
public:
    bool swapEngine(int pos, int smallVal, int bigVal, VI& nums, VI& firstOccurrence) {
        if (firstOccurrence[bigVal] < pos) {
            swap(nums[pos], nums[firstOccurrence[bigVal]]);
            firstOccurrence[smallVal] = min(firstOccurrence[smallVal], firstOccurrence[bigVal]);
            firstOccurrence[bigVal]++;
            return true;
        } else {
            return false;
        }
    }

    void sortColors(vector<int>& nums) {
        vector<int> firstOccurrence(3, numeric_limits<int>::max());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (!swapEngine(i, 0, 1, nums, firstOccurrence)) {
                    swapEngine(i, 0, 2, nums, firstOccurrence);
                } else {
                    swapEngine(i, 1, 2, nums, firstOccurrence);;
                }
            } else if (nums[i] == 1) {
                swapEngine(i, 1, 2, nums, firstOccurrence);
            }
            firstOccurrence[nums[i]] = min(i, firstOccurrence[nums[i]]);
        }

        return;
    }
};

// One pass - Dutch National Flag Problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, leftIndex = 0, rightIndex = nums.size() - 1;
        while (i <= rightIndex) {
            if (nums[i] == 0) {
                swap(nums[leftIndex++], nums[i++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[rightIndex--]);
            } else {
                i++;
            }
        }
        return;
    }
};
