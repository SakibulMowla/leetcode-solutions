class Solution {
private:
    bool containsChar(string& word, char x) {
        for (char ch: word) {
            if (ch == x) {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (containsChar(words[i], x)) {
                ans.push_back(i);
            }
        }    
        return ans;
    }
};
