class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hash;
        int ans = 0;
    
        for (int l = 0, r = 0, cnt = 0; r < s.size(); r++) {
            if (hash[s[r]] == 0) {
                cnt++;
            }
            hash[s[r]]++;
            
            while (cnt > k) {
                if (hash[s[l]] == 1) {
                    cnt--;
                }
                hash[s[l]]--;
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
