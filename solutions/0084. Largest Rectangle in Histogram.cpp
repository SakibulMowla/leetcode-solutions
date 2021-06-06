class Solution {
private:
    int popAndCalculate(stack<int>& positions, vector<int>& heights, int nextPos) {
        int top = positions.top();
        positions.pop();
        int area = heights[top] * (positions.empty() ? nextPos : nextPos - positions.top() - 1);
        return area;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> positions;
    
        for (int i = 0; i < n; i++) {
            while (!positions.empty() && heights[i] < heights[positions.top()]) {
                maxArea = max(maxArea, popAndCalculate(positions, heights, i));
            }
            positions.push(i);
        }
        
        while (!positions.empty()) {
            maxArea = max(maxArea, popAndCalculate(positions, heights, n));
        }
        
        return maxArea;
    }
};
