class Solution {
public:
    
    int findDepth(int& buffer, string& input, int len) {
        int d = 0;
        while (buffer < len && input[buffer] == '\t') {
            buffer++;
            d++;
        }
        return d;
    }
    
    string findNext(int& buffer, string& input, int len) {
        string ans = "";
        while (buffer < len) {
            if (input[buffer] == '\n') {
                buffer++;
                break;
            }
            ans += input[buffer];
            buffer++;
        }
        return ans;
    }
    
    bool isFile(string& input) {
        int len = input.size();
        bool dotExist = false;
        for (int i = 0; i < len; i++) {
            if (input[i] == '.') {
                dotExist = true;
            } else {
                if (dotExist) {
                    return true;
                }
            }
        }
        return false;
    }

    int lengthLongestPath(string input) {
        int len = input.size();
        int buffer = 0;
        
        vector<int> depth;
        int ans = 0;
        
        while (buffer < len) {
            int d = findDepth(buffer, input, len);
            string curString = findNext(buffer, input, len);
            
            if (d == depth.size()) {
                depth.push_back(curString.size());
            } else if (d > depth.size()) {
                return 0;
            } else {
                depth[d] = curString.size();
            }

            if (isFile(curString)) {
                int now = 0;
                for (int i = 0; i <= d; i++) {
                    now += bool(i) + depth[i];
                }
                ans = max(ans, now);
            }
        }
        
        return ans;
    }
};
