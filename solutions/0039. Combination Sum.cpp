// Sakib
class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int index, int n, vector<int>& combination, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        if (target < 0 || index == n) {
            return;
        }

        backtrack(candidates, target, index + 1, n, combination, combinations);

        combination.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index, n, combination, combinations);
        combination.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> combination;
        vector<vector<int>> combinations;

        backtrack(candidates, target, 0, n, combination, combinations);

        return combinations;
    }
};
