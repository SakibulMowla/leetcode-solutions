class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        
        queue<int> boxes;
        vector<bool> reachableClosedBoxes(n, false);
        for (int box: initialBoxes) {
            if (status[box] == 1) {
                boxes.push(box);
            } else {
                reachableClosedBoxes[box] = true;
            }
        }

        int ans = 0;
        vector<bool> visited(n, false);

        while (!boxes.empty()) {
            int box = boxes.front();
            boxes.pop();

            if (visited[box]) {
                continue;
            }

            visited[box] = true;
            ans += candies[box];

            for (int key: keys[box]) {
                if (status[key] == 0 && reachableClosedBoxes[key]) {
                    boxes.push(key);
                }
                status[key] = 1;
            }

            for (int nextBox: containedBoxes[box]) {
                if (status[nextBox] == 1) {
                    boxes.push(nextBox);
                } else {
                    reachableClosedBoxes[nextBox] = true;
                }
            }
        }

        return ans;
    }
};
