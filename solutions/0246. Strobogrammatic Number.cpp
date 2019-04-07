class Solution {
public:
    
    string rotateNum(string num, unordered_map<char, char> hash) {
        int n = num.size();
        string rotatedNum;
        for (int i = n - 1; i >= 0; i--) {
            if (hash.find(num[i]) != hash.end()) {
                rotatedNum += hash[num[i]];
            } else {
                rotatedNum += '-';
            }
        }
        return rotatedNum;
    }
    
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> rotateDigit;
        rotateDigit['6'] = '9';
        rotateDigit['9'] = '6';
        rotateDigit['8'] = '8';
        rotateDigit['0'] = '0';
        rotateDigit['1'] = '1';
        
        return num == rotateNum(num, rotateDigit);
    }
};

