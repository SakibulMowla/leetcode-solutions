class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cur, count;
        for (char ch: p) {
            count[ch]++;
        }

        vector<int> ans;
        
        for (int left = 0, right = 0; right < s.size(); right++) {
            char ch = s[right];
            cur[ch]++;

            while (left <= right && cur[ch] > count[ch]) {
                cur[s[left]]--;
                left++;
            }

            if (right - left + 1 == p.size()) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};

// -----------------------------------------------------------------------------

class Solution {
public:
    void update(unordered_map<char, int>& freq, int& cnt, char key, int value) {
        if (freq.find(key) == freq.end()) {
            freq[key] = 0;
        }
        freq[key] += value;
        if (value > 0) {
            if (freq[key] == 0) {
                cnt--;
            } else if (freq[key] == 1) {
                cnt++;
            }
        } else {
            if (freq[key] == 0) {
                cnt--;
            } else if (freq[key] == -1) {
                cnt++;
            }
        }
        return;
    }

    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> freq;
    
        int cnt = 0;
        for (char ch: p) {
            update(freq, cnt, ch, 1);
        }

        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            update(freq, cnt, s[i], -1);
            if (i >= p.size()) {
                update(freq, cnt, s[i - p.size()], 1);
            }
            if (cnt == 0) {
                ans.push_back(i - p.size() + 1);
            }
        }
        
        return ans;
    }
};
