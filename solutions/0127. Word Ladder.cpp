class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash;
        for (string word: wordList) {
            hash.insert(word);
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            if (front.first == endWord) {
                return front.second;
            }
            
            for (int i = 0; i < front.first.size(); i++) {
                string temp = front.first;
                for (int j = 0; j < 26; j++) {
                    temp[i] = j + 'a';
                    if (hash.find(temp) != hash.end()) {
                        q.push({temp, front.second + 1});
                        hash.erase(hash.find(temp));
                    }
                }
            }
        }
        
        return 0;
    }
};
