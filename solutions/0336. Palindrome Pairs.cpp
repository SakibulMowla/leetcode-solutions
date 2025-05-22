class Solution {
private:
    vector<string> findAllValidSuffix(string& word) {
        vector<string> validSuffix;
        for (int i = 0; i < word.size(); i++) {
            if (isPalindromeBetween(word, 0, i)) {
                validSuffix.push_back(word.substr(i + 1));
            }
        }
        return validSuffix;
    }

    vector<string> findAllValidPrefix(string& word) {
        vector<string> validPrefix;
        for (int i = 0; i < word.size(); i++) {
            if (isPalindromeBetween(word, i, word.size() - 1)) {
                validPrefix.push_back(word.substr(0, i));
            }
        }
        return validPrefix;
    }

    bool isPalindromeBetween(string& word, int start, int end) {
        while (start < end) {
            if (word[start] != word[end]) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        
        unordered_map<string, int> wordMap;
        for (int i = 0; i < n; i++) {
            wordMap[words[i]] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // current word is same size as suffix
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            if (wordMap.find(reversed) != wordMap.end() &&
                wordMap[reversed] != i) {
                ans.push_back({i, wordMap[reversed]});
            }

            // current word is in the end
            vector<string> allValidSuffix = findAllValidSuffix(words[i]);
            for (string suffix: allValidSuffix) {
                reverse(suffix.begin(), suffix.end());
                if (wordMap.find(suffix) != wordMap.end()) {
                    ans.push_back({wordMap[suffix], i});
                }
            }

            // current word is at the beginiing
            vector<string> allValidPrefix = findAllValidPrefix(words[i]);
            for (string prefix: allValidPrefix) {
                reverse(prefix.begin(), prefix.end());
                if (wordMap.find(prefix) != wordMap.end()) {
                    ans.push_back({i, wordMap[prefix]});
                }
            }
        }

        return ans;
    }
};
