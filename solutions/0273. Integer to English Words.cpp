class Solution {
private:
    unordered_map<int, string> numToWord = {
        { 0, "Zero" },
        { 1, "One" },
        { 2, "Two" },
        { 3, "Three" },
        { 4, "Four" },
        { 5, "Five" },
        { 6, "Six" },
        { 7, "Seven" },
        { 8, "Eight" },
        { 9, "Nine" },
        { 10, "Ten" },
        { 11, "Eleven" },
        { 12, "Twelve" },
        { 13, "Thirteen" },
        { 14, "Fourteen" },
        { 15, "Fifteen" },
        { 16, "Sixteen" },
        { 17, "Seventeen" },
        { 18, "Eighteen" },
        { 19, "Nineteen" },
        { 20, "Twenty" },
        { 30, "Thirty" },
        { 40, "Forty" },
        { 50, "Fifty" },
        { 60, "Sixty" },
        { 70, "Seventy" },
        { 80, "Eighty" },
        { 90, "Ninety" }
    };
    
    void divideAndConquer(int num, vector<string>& ans) {
        if (num >= 1E9) {
            divideAndConquer(num / 1E9, ans);
            ans.push_back("Billion");
            num %= (int)1E9;
        }
        if (num >= 1E6) {
            divideAndConquer(num / 1E6, ans);
            ans.push_back("Million");
            num %= (int)1E6;
        }
        if (num >= 1E3) {
            divideAndConquer(num / 1E3, ans);
            ans.push_back("Thousand");
            num %= (int)1E3;
        }
        if (num >= 100) {
            divideAndConquer(num / 100, ans);
            ans.push_back("Hundred");
            num %= 100;
        }
        if (num >= 20) {
            ans.push_back(numToWord[num / 10 * 10]);
            num %= 10;
        }
        if (num) {
            ans.push_back(numToWord[num]);
        }
        return;
    }

    string join(vector<string> ans, string del) {
        string sentence;
        for (int i = 0; i < ans.size(); i++) {
            sentence = sentence + (i ? del : "") + ans[i];
        }
        return sentence;
    }
    
public:
    string numberToWords(int num) {
        vector<string> ans;
        divideAndConquer(num, ans);
        return num ? join(ans, " ") : numToWord[0];
    }
};
