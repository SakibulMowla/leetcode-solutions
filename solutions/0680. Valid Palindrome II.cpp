// =======================================================
// Time - O(n) Memory - O(n)
// =======================================================

class Solution {
public:
    bool isPalindrome(string& s, vector<int>& positions) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                positions = {i, n - i - 1};
                return false;
            }
        }
        return true;
    }
    
    bool eraseAndCheck(string s, int pos) {
        s.erase(pos, 1);
        vector<int> _tmp;
        return isPalindrome(s, _tmp);
    }
    
    bool validPalindrome(string s) {
        vector<int> positions;
        bool flag = isPalindrome(s, positions);
        
        if (!flag) {
            flag = eraseAndCheck(s, positions[0]) || eraseAndCheck(s, positions[1]);
        }

        return flag;
    }
};

// =======================================================
// Time - O(n) Memory - O(1)
// =======================================================

class Solution {
private:
    bool isPalindrome(string& s, int skipIndex) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            if (l == skipIndex) {
                l++;
            } else if (r == skipIndex) {
                r--;
            } else {
                if (s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
        }
        
        return true;
    }

public:
    bool validPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return isPalindrome(s, i) || isPalindrome(s, n - i - 1);
            }
        }
        return true;
    }
};
