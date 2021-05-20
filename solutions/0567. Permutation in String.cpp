class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        unordered_map<char, int> target;
        
        for (int i = 0; i < n; i++) {
            target[s1[i]]++;
        }
        
        int totalUniques = target.size();
        unordered_map<char, int> current;
        int uniques = 0;

        for (int i = 0; i < m; i++) {
            if (target.find(s2[i]) != target.end()) {
                current[s2[i]]++;
                if (current[s2[i]] == target[s2[i]]) {
                    uniques++;
                } else if (current[s2[i]] == target[s2[i]] + 1) {
                    uniques--;
                }
            }
            
            if (i >= n && target.find(s2[i - n]) != target.end()) {
                current[s2[i - n]]--;
                if (current[s2[i - n]] == target[s2[i - n]] - 1) {
                    uniques--;
                } else if (current[s2[i - n]] == target[s2[i - n]]) {
                    uniques++;
                }
            }
            
            if (uniques == totalUniques) {
                return true;
            }
        }
        
        return false;
    }
};
