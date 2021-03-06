class Solution {
public:
    
    void normalize(string& s) {
        for (auto& ch: s) {
            ch = tolower(ch);
        }
        return;
    }
    
    void parse(int pos, int n, string& paragraph, string current, unordered_map<string, int>& hash) {
        if (pos == n) {
            if (current != "") {
                if (hash.find(current) == hash.end()) {
                    hash[current] = 0;
                }   
                hash[current]++;
            }
        } else {
            if (isalpha(paragraph[pos])) {
                current += paragraph[pos];
            } else {
                if (current != "") {
                    if (hash.find(current) == hash.end()) {
                        hash[current] = 0;
                    }   
                    hash[current]++;
                }
                current = "";
            }
            parse(pos + 1, n, paragraph, current, hash);
        }
        
        return;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        normalize(paragraph);
        unordered_set<string> banDict;
        for (auto s: banned) {
            normalize(s);
            banDict.insert(s);
        }
        
        int n = paragraph.size();
        string current;
        unordered_map<string, int> hash;
        
        parse(0, n, paragraph, current, hash);
        string ans;
        int best = 0;

        for (auto it: hash) {
            if (banDict.find(it.first) == banDict.end() && it.second > best) {
                best = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};
