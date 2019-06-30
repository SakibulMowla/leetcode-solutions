class Solution {
public:
    bool presentFrom(int buffer, string& haystack, string& needle) {
        for (int i = 0; i < needle.size(); i++) {
            if (needle[i] != haystack[buffer + i]) {
                return false;
            }
        }
        return true;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i + m -1 < n; i++) {
            if (presentFrom(i, haystack, needle)) {
                return i;
            }
        }
        
        return -1;
    }
};
