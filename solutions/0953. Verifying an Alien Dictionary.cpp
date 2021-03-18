class Solution {
public:
    int charToInt(char ch) {
        return ch - 'a';
    }
    
    bool compare(string a, string b, vector<int>& rank) {
        int sz = min(a.size(), b.size());
        for (int i = 0; i < sz; i++) {
            int rankA = rank[charToInt(a[i])];
            int rankB = rank[charToInt(b[i])];
            if (rankA < rankB) {
                return true;
            } else if (rankA > rankB) {
                return false;
            }
        }
        
        return a.size() <= b.size();
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for (int i = 0; i < 26; i++) {
            rank[charToInt(order[i])] = i;
        }
        
        int n = words.size();
        bool isSorted = true;

        for (int i = 1; i < n; i++) {
            if (!compare(words[i - 1], words[i], rank)) {
                isSorted = false;
                break;
            }
        }
        
        return isSorted;
    }
};
