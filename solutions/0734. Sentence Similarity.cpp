class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int len1 = words1.size();
        int len2 = words2.size();
        
        if (len1 != len2) {
            return false;
        }
    
        unordered_set<string> hash;
        for (auto& pair: pairs) {
            hash.insert(pair.first + "&" + pair.second);
            hash.insert(pair.second + "&" + pair.first);
        }

        for (int i = 0; i < len1; i++) {
            if (words1[i] != words2[i] &&
               hash.find(words1[i] + "&" + words2[i]) == hash.end()) {
                return false;
            } 
        }

        return true;
    }
};
