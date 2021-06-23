class Solution {
private:
    bool isPredessor(string& wordA, string& wordB) {
        int n = wordA.size();
        int m = wordB.size();
        int mismatches = 0;
        
        int i = 0;
        int j = 0;
        
        while (i < n) {
            if (wordA[i] == wordB[j]) {
                i++;
                j++;
            } else {
                j++;
                mismatches++;
            }
            
            if (mismatches > 1) {
                return false;
            }
        }
        
        return true;
    }
    
    int traverse(string& word, unordered_map<string, int>& maxPath, unordered_map<string, vector<string>>& adj) {
        if (maxPath.find(word) != maxPath.end()) {
            return maxPath[word];
        }
        
        int ret = 1;
        for (string nextWord: adj[word]) {
            ret = max(ret, 1 + traverse(nextWord, maxPath, adj));
        }
        
        return maxPath[word] = ret;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> sizeToWords(17, vector<string> ());
        
        for (string word: words) {
            sizeToWords[word.size()].push_back(word);
        }
        
        unordered_map<string, vector<string>> adj;
        
        for (int i = 2; i <= 16; i++) {
            for (string wordA: sizeToWords[i - 1]) {
                for (string wordB: sizeToWords[i]) {
                    if (isPredessor(wordA, wordB)) {
                        adj[wordA].push_back(wordB);
                    }
                }
            }
        }
        
        unordered_map<string, int> maxPath;
        int ans = 0;

        for (string word: words) {
            if (maxPath.find(word) == maxPath.end()) {
                ans = max(ans, traverse(word, maxPath, adj));
            }
        }
        
        return ans;
    }
};
