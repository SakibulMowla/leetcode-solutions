class Solution {
public:
    bool compare(string& a, string& b, unordered_map<char, int>& precedence) {
        int aLen = a.size(), bLen = b.size();
        int pointer;
        
        for (pointer = 0; pointer < min(aLen, bLen); pointer++) {
            if (precedence[a[pointer]] > precedence[b[pointer]]) {
                return false;
            } else if (precedence[a[pointer]] < precedence[b[pointer]]) {
                return true;
            }
        }
        
        return pointer == aLen;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> precedence;

        int cnt = 0;
        for (auto& ch: order) {
            precedence[ch] = cnt++;
        }
        
        for (int i = 1; i < words.size(); i++) {
            if (!compare(words[i - 1], words[i], precedence)) {
                return false;
            }
        }
        
        return true;
    }
};
