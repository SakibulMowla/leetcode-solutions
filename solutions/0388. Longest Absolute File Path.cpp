// Depth-First Search

class Solution {
private:
    int n;
    int longestPath;
    // contains the last len on each level
    vector<int> lenByLevel;

    void dfs(int index, string& input, int level, int curLen, bool isFile) {
        if (index > n) {
            return;
        }

        // if newline, do the calc and move to next dir
        if ((index == n) || (input[index] == '\n')) {
            int pathLen = curLen + (level != 0 ? 1 + lenByLevel[level - 1] : 0);
            
            while (lenByLevel.size() <= level) {
                lenByLevel.push_back(0);
            }
            
            lenByLevel[level] = pathLen;
            
            if (isFile) {
                longestPath = max(longestPath, pathLen);
            }

            return dfs(index + 1, input, 0, 0, false); 
        }

        // if tab, increase level and go next step
        if (input[index] == '\t') {
            return dfs(index + 1, input, level + 1, 0, false);
        }

        isFile = isFile || (input[index] == '.' );
        return dfs(index + 1, input, level, curLen + 1, isFile); 
    }

public:
    int lengthLongestPath(string input) {
        n = input.size();
        lenByLevel = vector<int>();
        longestPath = 0;

        dfs(0, input, 0, 0, false);

        return longestPath;
    }
};

// ---------------------------------------------------------------------------------

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
