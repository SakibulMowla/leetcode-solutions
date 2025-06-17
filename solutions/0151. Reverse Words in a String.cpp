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
    void removeExtraSpaces(string& s) {
        int len = 0;
        char prev = ' ';

        for (char ch: s) {
            if (ch != ' ') {
                s[len++] = ch;
            } else {
                if (prev != ' ') {
                    s[len++] = ch;
                }
            }
            prev = ch;
        }

        if (len && s[len - 1] == ' ') 
            len--;

        s.erase(len);
    }

    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

public:
    string reverseWords(string s) {
        removeExtraSpaces(s);

        int len = s.size();
        reverse(s, 0, len - 1);

        for (int i = 0; i < len; i++) {
            int j = i;
            while (j + 1 < len && s[j + 1] != ' ') 
                j++;
            
            reverse(s, i, j);
            i = j + 1;
        }

        return s;
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
