// ==============================================
// Time - O(n^2) Memory - O(n^2)
// ==============================================

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n + 1, false));
        int ansStartIndex = 0;
        int ansLength = 0;
        
        for (int length = 1; length <= n; length++) {
            for (int startIndex = 0; startIndex + length - 1 < n; startIndex++) {
                if ((s[startIndex] == s[startIndex + length - 1]) &&
                    (length < 3 ? true : isPalindrome[startIndex + 1][length - 2])) {
                    isPalindrome[startIndex][length] = true;
                    ansStartIndex = startIndex;
                    ansLength = length;
                }
            }
        }
        
        return s.substr(ansStartIndex, ansLength);
    }
};

// ==============================================
// Time - O(n^2) Memory - O(1)
// ==============================================
class Solution {
private:
    pair<int, int> longestFromCenter(string& s, int l, int r, int n) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return {l + 1, r - 1};
    }

    void setMax(int& best, int& start, pair<int, int> current) {
        int l = current.first;
        int r = current.second;
        if (r - l + 1 > best) {
            best = r - l + 1;
            start = l;
        }
        return;
    }
    
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int best = 0;
        int start;

        for (int i = 0; i < n; i++) {
            setMax(best, start, longestFromCenter(s, i, i, n));
            setMax(best, start, longestFromCenter(s, i, i + 1, n));
        }
        
        return s.substr(start, best);
    }
};
