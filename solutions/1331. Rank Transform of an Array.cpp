class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> elemToRank;
        for (int elem: arr) {
            elemToRank[elem] = 0;
        }
        
        int rank = 0;
        for (auto it: elemToRank) {
            elemToRank[it.first] = ++rank;
        }
        
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = elemToRank[arr[i]];
        }
        
        return ans;
    }
};
