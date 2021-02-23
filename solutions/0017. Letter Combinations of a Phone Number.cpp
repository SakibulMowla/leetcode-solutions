class Solution {
public:
    unordered_map<char, string> digitToLetters = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "prqs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };

    void bctk(int pos, const string& digits, string& current, vector<string>& ans) {
        if (pos == digits.size()) {
            ans.push_back(current);
        } else {
            for (auto ch: digitToLetters[digits[pos]]) {
                current.push_back(ch);
                bctk(pos + 1, digits, current, ans);
                current.pop_back();
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string current;
        if (digits != "") {
            bctk(0, digits, current, ans);
        }
        return ans;
    }
};
