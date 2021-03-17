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
