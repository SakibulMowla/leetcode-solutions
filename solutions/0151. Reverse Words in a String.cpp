// ===============================
// Time - O(n) Memory - O(n)
// ===============================

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        string word;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (word != "") {
                words.push_back(word);
                word = "";
            }
        }
        
        if (word != "") {
            words.push_back(word);
        }
        
        string ans;
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i] + (i ? " ": "");
        }
        
        return ans;
    }
};

// ===============================
// Time - O(n) Memory - O(n)
// ===============================

class Solution {
private:
    void removeLeadingSpaces(string& s) {
        while (s[0] == ' ') {
            s.erase(0, 1);
        }
        return;
    }
    
    void removeTrailingSpaces(string& s) {
        while (s[s.size() - 1] == ' ') {
            s.erase(s.size() - 1);
        }
        return;
    }
    
    void removeExtraSpaces(string& s) {
        int n = s.size();
        for (int i = n - 1; i >= 1; i--) {
            if (s[i] == ' ' && s[i - 1] == ' ') {
                s.erase(i, 1);
            }
        }
        return;
    }
    
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int begin = n;
        int end;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (begin == n) {
                    begin = i;
                }
            } else {
                if (begin < i) {
                    end = i - 1;
                    reverse(s.begin() + begin, s.begin() + end + 1);
                    begin = n;
                }
            }
        }
        
        if (begin != n) {
            end = n - 1;
            reverse(s.begin() + begin, s.begin() + end + 1);
        }
        
        removeLeadingSpaces(s);
        removeTrailingSpaces(s);
        removeExtraSpaces(s);
        
        return s;
    }
};
