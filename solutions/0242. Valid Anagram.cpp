class Solution {
public:    
    void process(string s, map<char, int>& hash, int change) {
        for (auto ch: s) {
            hash[ch] += change;
        }
    }

    bool isAnagram(string s, string t) {
        map<char, int> hash;

        process(s, hash, 1);
        process(t, hash, -1);

        for (auto it: hash) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};

// ==============================================

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> freq(26, 0);
        
        for (char ch: s) {
            freq[ch - 'a']++;
        }
        
        for (char ch: t) {
            freq[ch - 'a']--;
            if (freq[ch - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
