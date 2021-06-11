class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> lengths;
        int n = sentence.size();
        for (int i = 0; i < n; i++) {
            lengths.push_back(sentence[i].size());
            if (lengths.back() > cols) {
                return 0;
            }
        }
        
        vector<int> dp(n);
        for (int start = 0; start < n; start++) {
            int pos = 0;
            int index = start;
            int words = 0;
            while (pos <= cols) {
                pos += lengths[index];
                index = (index + 1) % n;
                words++;
                if (pos < cols) {
                    pos++;
                }
            }
            dp[start] = words - 1;
        }

        int totalWords = 0;
        for (int i = 0, start = 0; i < rows; i++) {
            totalWords += dp[start];
	        start = (start + dp[start]) % n;
        }

        return totalWords / n;
    }
};
