class Solution {
private:
    string prepareCountString(const string& str) {
        vector<int> cnt(26, 0);
        for (char ch: str) {
            cnt[ch - 'a']++;
        }
        
        string ans;
        for (int i = 0; i < 26; i++) {
            ans += to_string(cnt[i]) + "#";
        }
        
        return ans;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyToGroup;
        
        for (string str: strs) {
            string key = prepareCountString(str);
            if (keyToGroup.find(key) == keyToGroup.end()) {
                keyToGroup[key] = vector<string> ();
            }
            keyToGroup[key].push_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto it: keyToGroup) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
