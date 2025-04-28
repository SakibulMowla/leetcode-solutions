// Time - O(n)
// Memory - O(26)

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

// ---------------------------------------------------------------

// Time - O(n)
// Memory - O(26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;
        for (char ch: s1) {
            count1[ch]++;
        }

        unordered_map<char, int> count2;
        for (int l = 0, r = 0; r < s2.size(); r++) {
            count2[s2[r]]++;
            while (count2[s2[r]] > count1[s2[r]]) {
                count2[s2[l]]--;
                l++;
            }

            if (r - l + 1 == s1.size()) {
                return true;
            }
        }

        return false;
    }
};
