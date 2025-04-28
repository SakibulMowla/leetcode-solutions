// Time - O(n * 26)
// Memory - O(26)

class Solution {
private:
    int findMaxFreq(unordered_map<char, int>& count) {
        int maxValue = std::numeric_limits<int>::min();
        for (const auto& [key, value] : count) {
            if (value > maxValue) {
                maxValue = value;
            }
        }
        return maxValue;
    }

public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int ans = 0;
    
        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r]]++;

            while ((r - l + 1) - findMaxFreq(count) > k) {
                count[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// ----------------------------------------------------------------

// Time - O(n)
// Memory - O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int ans = 0, maxFreq = 0;
    
        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
