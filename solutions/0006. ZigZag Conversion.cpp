class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string> row(numRows + 1, "");
    
        for (int j = 0; j < n; ) {
            for (int i = 1; i <= numRows && j < n; i++, j++) {
                row[i] += s[j];
            }
            for (int i = numRows - 1; i > 1 && j < n; i--, j++) {
                row[i] += s[j];
            }
        }
        
        string ans = "";
        for (int i = 1; i <= numRows; i++) {
            ans += row[i];
        }
        
        return ans;
    }
};
