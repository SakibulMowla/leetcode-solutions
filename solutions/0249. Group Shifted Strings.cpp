class Solution {
public:
    string createGroupId(string& s) {
        string id = "";
        for (int i = 1; i < s.size(); i++) {
            id += to_string(s[i] > s[i - 1] ? s[i] - s[i - 1] : 26 + s[i] - s[i - 1]) + "#";
        }
        return id;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> idToNum;
        vector<vector<string>> ans;

        for (string s: strings) {
            string curGroupId = createGroupId(s);
            if (idToNum.find(curGroupId) == idToNum.end()) {
                idToNum[curGroupId] = idToNum.size();
            }
            int num = idToNum[curGroupId];
            if (ans.size() == num) {
                ans.push_back(vector<string>());
            }
            ans[num].push_back(s);
        }
        
        return ans;
    }
};
