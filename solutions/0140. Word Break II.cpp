class Solution {
private:
    unordered_set<string> wordDictMap;
    vector<string> ans;

    void addToAns(vector<string>& sentence) {
        string plainSentence = "";
        for (int i = 0; i < sentence.size(); i++) {
            plainSentence += (i ? " " : "") + sentence[i];
        }
        ans.push_back(plainSentence);
        return;
    }

    void backtrack(string& s, int index, int len, string& cur, vector<string>& sentence) {
        if (index == len) {
            if (wordDictMap.find(cur) != wordDictMap.end()) {
                sentence.push_back(cur);
                addToAns(sentence);
                sentence.pop_back();
            }
            return;
        }

        // keep adding
        cur.push_back(s[index]);
        backtrack(s, index + 1, len, cur, sentence);
        cur.pop_back();

        // check for word
        if (wordDictMap.find(cur) != wordDictMap.end()) {
            sentence.push_back(cur);
            string newCur = "";
            newCur.push_back(s[index]);
            backtrack(s, index + 1, len, newCur, sentence);
            newCur.pop_back();
            sentence.pop_back();
        }

        return;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string& word: wordDict) {
            wordDictMap.insert(word);
        }    

        string cur = "";
        int len = s.size();
        vector<string> sentence;

        backtrack(s, 0, len, cur, sentence);

        return ans;
    }
};
