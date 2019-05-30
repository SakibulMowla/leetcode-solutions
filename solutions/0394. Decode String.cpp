class Solution {
public:
    
    string dfs(int& buffer, int ending, string& s) {
        cout << buffer << endl;
        string ans;
        
        string str;
        int num = 0;

        while (buffer < ending) {
            if (isalpha(s[buffer])){
                str += s[buffer];
            } else if (isdigit(s[buffer])) {
                num = num * 10 + s[buffer] - '0';
                ans += str;
                str = "";
            } else if (s[buffer] == '[') {
                buffer++;
                string now = dfs(buffer, ending, s);
                while (num) {
                    ans += now;
                    --num;
                }
            } else {
                ans += str;
                return ans;
            }
            buffer++;
        }

        return ans + str;
    }
    
    string decodeString(string s) {
        int buffer = 0, ending = s.size();
        return dfs(buffer, ending, s);
    }
};
