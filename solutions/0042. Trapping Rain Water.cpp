// 2 Pass
// Time - O(N)
// Memory - O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        int ans = 0;
        for (int i = n - 1, rightMax = 0; i >= 1; i--) {
            ans += max(0, min(leftMax[i - 1], rightMax) - height[i]);
            rightMax = max(height[i], rightMax);
        }

        return ans;
    }
};

// --------------------------------------------------------

// 1 Pass
// Time - O(N)
// Memory - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftIndex = 0, rightIndex = n - 1;
        int leftMax = height[leftIndex], rightMax = height[rightIndex];
        int ans = 0;

        while (leftIndex < rightIndex) {
            if (leftMax < rightMax) {
                leftIndex++;
                leftMax = max(leftMax, height[leftIndex]);
                ans += leftMax - height[leftIndex];
            } else {
                rightIndex--;
                rightMax = max(rightMax, height[rightIndex]);
                ans += rightMax - height[rightIndex];
            }
        }

        return ans;
    }
};
