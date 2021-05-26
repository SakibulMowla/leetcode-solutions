class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
    
        bool isNegative = num < 0;
        num = abs(num);
        string ans;
    
        while (num) {
            ans.push_back((num % 7) + '0');
            num /= 7;
        }
        
        if (isNegative) {
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
