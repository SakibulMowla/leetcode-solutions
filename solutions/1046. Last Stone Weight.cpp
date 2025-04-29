// Time - O(n log n)
// Memory - O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxQueue;
        for (int stone: stones) {
            maxQueue.push(stone);
        }

        while (maxQueue.size() > 1) {
            int y = maxQueue.top();
            maxQueue.pop();
            int x = maxQueue.top();
            maxQueue.pop();
            if (x != y) {
                maxQueue.push(y - x);
            }
        }

        return maxQueue.size() ? maxQueue.top() : 0;
    }
};
