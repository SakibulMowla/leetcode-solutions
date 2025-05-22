class Solution {
private:
    int findFallingIndex(vector<int>& heights, int index, int direction) {
        int target = index;
        int n = heights.size();

        while (index + direction >= 0 && index + direction < n && 
               heights[index + direction] <= heights[index]) {
            index += direction;
            if (heights[index] < heights[target]) {
                target = index;
            }
        }

        return target;
    }

public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        while (volume--) {
            int leftIndex = findFallingIndex(heights, k, -1);
            if (leftIndex != k) {
                heights[leftIndex]++;
                continue;
            }

            int rightIndex = findFallingIndex(heights, k, 1);
            if (rightIndex != k) {
                heights[rightIndex]++;
                continue;
            }

            heights[k]++;
        }

        return heights;
    }
};
