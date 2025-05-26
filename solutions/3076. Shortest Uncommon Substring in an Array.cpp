class Solution {
private:
    vector<string> findAllSubstrings(string& str) {
        int len = str.size();
        vector<string> substrings;
        for (int k = 1; k <= len; k++) {
            for (int i = 0; i < len && i + k <= len; i++) {
                substrings.push_back(str.substr(i, k));
            }
        }
        return substrings;
    }

    void updateSubstringCount(string& str, unordered_map<string, int>& substringToIndex, int val) {
        vector<string> substrings = findAllSubstrings(str);
        for (string& str: substrings) {
            substringToIndex[str] = val;
        }
        return;
    }

    bool isBetterAnswer(string& substring, string& smallest, int len) {
        return substring.size() < len || 
               (substring.size() == len && substring < smallest);
    }

public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, int> substringToIndex;

        for (int i = 0; i < n; i++) {
            updateSubstringCount(arr[i], substringToIndex, i);
        }

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            vector<string> substrings = findAllSubstrings(arr[i]);
            string smallest = "";
            int len = INT_MAX;

            for (string& substring: substrings) {
                if (substringToIndex[substring] == 1 && isBetterAnswer(substring, smallest, len)) {
                    smallest = substring;
                    len = substring.size();
                }
            }

            ans.push_back(smallest);
        }

        return ans;
    }
};
