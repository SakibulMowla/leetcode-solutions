class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> time(n, -1);
        stack<int> carIndex;
        for (int i = n - 1; i >= 0; i--) {
            while (!carIndex.empty() && cars[carIndex.top()][1] >= cars[i][1]) {
                carIndex.pop();
            }

            while (!carIndex.empty()) {
                int index= carIndex.top();
                time[i] = 1.0 * (cars[index][0] - cars[i][0]) / (cars[i][1] - cars[index][1]);
                if (time[index] != -1 && time[i] > time[index]) {
                    carIndex.pop();
                } else {
                    break;
                }
            }
            
            carIndex.push(i);
        }
        
        return time;
    }
};
