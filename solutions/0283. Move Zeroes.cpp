/*
- Time Complexity - O(n)
- Space Complexity - O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, firstZeroPos = 0; i < n; i++) {
            if (nums[i] != 0) {
                while (firstZeroPos != n && nums[firstZeroPos] != 0) {
                    firstZeroPos++;
                }
                if (firstZeroPos != n && firstZeroPos < i) {
                    swap(nums[i], nums[firstZeroPos]);
                }
            }
        }
        return;
    }
};

--------------------------------------------------------------------------
/*
- Time Complexity - O(n)
- Space Complexity - O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        for ( ; r < n; r++) {
            if (nums[r] != 0) {
                nums[l++] = nums[r];
            }
        }
        for ( ; l < n; l++) nums[l] = 0;
    }
};

--------------------------------------------------------------------------
/*
- Time Complexity - O(n)
- Space Complexity - O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, zeroIndex = 0; i < nums.size(); i++) {
            if (nums[i]) {
                swap(nums[i], nums[zeroIndex++]);
            }
        }
        return;
    }
};

--------------------------------------------------------------------------
/*
Input:
[0,1,0,3,12]
[0,0,0,1,1]
[1,1,0,0,0]
[0,1,0,1,0]
[1,0,1,0,1]
[1]
[0]
[]

Output:
[1,3,12,0,0]
[1,1,0,0,0]
[1,1,0,0,0]
[1,1,0,0,0]
[1,1,1,0,0]
[1]
[0]
[]
*/
