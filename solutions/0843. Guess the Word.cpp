/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    vector<string> reduceWordList(string guess, int match, vector<string>& wordlist) {
        vector<string> ans;
        for (string word: wordlist) {
            if (word == guess) {
                continue;
            }
            int similarCount = 0;
            for (int i = 0; i < word.size(); i++) {
                similarCount += guess[i] == word[i];
            }
            if (similarCount == match) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
        
    string getCommonWord(vector<string>& wordlist) {
        unordered_map<int, unordered_map<char, int>> freq;
        for (string word: wordlist) {
            for (int i = 0; i < word.size(); i++) {
                freq[i][word[i]]++;
            }
        }
        
        string commonWord;
        int maxScore = 0;
        
        for (string word: wordlist) {
            int score = 0;
            for (int i = 0; i < word.size(); i++) {
                score += freq[i][word[i]];
            }
            if (score > maxScore) {
                maxScore = score;
                commonWord = word;
            }
        }
        
        return commonWord;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while (wordlist.size()) {
            string word = getCommonWord(wordlist);
            int match = master.guess(word);
            if (match == 6) {
                break;
            }
            wordlist = reduceWordList(word, match, wordlist);
        }
        return;
    }
};
