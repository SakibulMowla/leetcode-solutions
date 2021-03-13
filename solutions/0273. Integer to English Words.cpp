class Solution {
public:
    
    unordered_map<int, string> numToWord = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };
    
    const int thousand = 1000;
    const int million = thousand * thousand;
    const int billion = thousand * million;
    
    void threeDigit(int num, vector<string>& ret) {
        if (num > 99) {
            ret.push_back(numToWord[num / 100]);
            ret.push_back("Hundred");
        }
        num %= 100;
        if (num > 0 && num <= 20) {
            ret.push_back(numToWord[num]);
        } else if (num > 20) {
            ret.push_back(numToWord[(num / 10) * 10]);
            if (num % 10) {
                ret.push_back(numToWord[num % 10]);
            }
        }
        return;
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
    
        vector<string> ans;
        if (num / billion) {
            threeDigit(num / billion, ans);
            ans.push_back("Billion");
            num %= billion;
        }
        if (num / million) {
            threeDigit(num / million, ans);
            ans.push_back("Million");
            num %= million;
        }
        if (num / thousand) {
            threeDigit(num / thousand, ans);
            ans.push_back("Thousand");
            num %= thousand;
        }
        if (num) {
            threeDigit(num, ans);
        }
        
        string words;
        for (int i = 0; i < ans.size(); i++) {
            if (i) words += " ";
            words += ans[i];
        }
        
        return words;
    }
};
