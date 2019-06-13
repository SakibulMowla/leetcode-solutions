class Solution {
public:
    string getHint(string secret, string guess) {
        int length = secret.size();
        int bulls = 0;
        vector<int> cnt(10, 0);

        for (int i = 0; i < length; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                cnt[secret[i] - '0']++;
                cnt[guess[i] - '0']--;
            }
        }
        
        int cowsPrime = 0;
        for (int i = 0; i < 10; i++) {
            cowsPrime +=  abs(cnt[i]);
        }
        int cows = length - bulls - cowsPrime / 2;
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
