class ValidWordAbbr {
public:
    
    string abbreviate(string& str) {
        int n = str.size();
        if (n > 2) {
            return str[0] + to_string(n) + str[n - 1];
        }
        return str;
    }
    
    unordered_map<string, bool> hash;
    unordered_set<string> keep;
    
    ValidWordAbbr(vector<string> dictionary) {
        hash.clear();
        for (auto& word: dictionary) {
            if (keep.find(word) == keep.end()) {
                keep.insert(word);
                string aword = abbreviate(word);
                hash[aword] = (hash.find(aword) == hash.end());
            }
        }
    }
    
    bool isUnique(string word) {
        string aword = abbreviate(word);
        auto it = hash.find(aword);
        return it == hash.end() || (hash[aword] && keep.find(word) != keep.end());
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
