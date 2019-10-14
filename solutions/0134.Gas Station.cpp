// O(n^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = -1;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int sum_gas = 0;
            int sum_cost = 0;
            for (int j = 0; j < n; j++) {
                sum_gas += gas[(i + j) % n];
                sum_cost += cost[(i + j) % n];
                if (sum_cost > sum_gas) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        vector<int> delta(2 * n);
        for (int i = 0; i < n; i++) {
            delta[i] = delta[i + n] = gas[i] - cost[i];
        }
    
        int ans = -1;
        for (int start = 0, finish = 0, sum = 0; finish < 2 * n; finish++) {
            sum += delta[finish];
            while (sum < 0 && start <= finish) {
                sum -= delta[start];
                start++;
            }
            if (finish - start + 1 == n) {
                ans = start;
                break;
            }
        }
        
        return ans;
    }
};
