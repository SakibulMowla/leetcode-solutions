class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<stack<int>> store(2, stack<int>());
        for (int num: nums) {
            store[num % 2].push(num);
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(store[i % 2].top());
            store[i % 2].pop();
        }
        
        return ans;
    }
};
