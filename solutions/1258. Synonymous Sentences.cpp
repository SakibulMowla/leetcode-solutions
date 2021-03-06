class Solution {
public:
    void backtrack(int pos, vector<string>& parsedText, vector<string> cur, unordered_map<string, set<string>>& dictionary, vector<string>& ans) {
        if (pos == parsedText.size()) {
            string sentence;
            for (int i = 0; i < cur.size(); i++) {
                if (i) sentence += " ";
                sentence += cur[i];
            }
            ans.push_back(sentence);
        } else {
            if (dictionary.find(parsedText[pos]) == dictionary.end()) {
                cur.push_back(parsedText[pos]);
                backtrack(pos + 1, parsedText, cur, dictionary, ans);
                cur.pop_back();
            } else {
                for (auto it: dictionary[parsedText[pos]]) {
                    cur.push_back(it);
                    backtrack(pos + 1, parsedText, cur, dictionary, ans);
                    cur.pop_back();
                }
            }
        }
        return;
    }
    
    void parse(int pos, int n, string cur, string& text, vector<string>& parsedText) {
        if (pos == n) {
            if (cur != "") {
                parsedText.push_back(cur);
            }
        } else {
            if (text[pos] == ' ') {
                parsedText.push_back(cur);
                cur = "";
            } else {
                cur += text[pos];
            }
            parse(pos + 1, n, cur, text, parsedText);
        }
        return;
    }
    
    string findParent(string cur, unordered_map<string, string>& parent) {
        return parent[cur] = (cur == parent[cur] ? cur : findParent(parent[cur], parent)); 
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, string> parent;
        for (auto& synonym: synonyms) {
            string wordA = synonym[0];
            string wordB = synonym[1];
            
            if (parent.find(wordA) == parent.end()) {
                parent[wordA] = wordA;
            }
            if (parent.find(wordB) == parent.end()) {
                parent[wordB] = wordB;
            }
            
            string parA = findParent(wordA, parent);
            string parB = findParent(wordB, parent);
            
            if (parA != parB) {
                parent[parA] = parB;
            }
        }
        
        unordered_map<string, set<string>> dictionary;
        for (auto it: parent) {
            string par = findParent(it.second, parent);
            if (dictionary.find(par) == dictionary.end()) {
                dictionary[par] = set<string>{};
            }
            dictionary[par].insert(it.first);
        }
        
        vector<string> parsedText;
        string cur = "";
        int n = text.size();
        parse(0, n, cur, text, parsedText);
        
        for (auto& x: parsedText) {
            if (parent.find(x) != parent.end()) {
                x = findParent(x, parent);   
            }
        }
        
        vector<string> ans;
        vector<string> cur2;
        backtrack(0, parsedText, cur2, dictionary, ans);
        
        return ans;
    }
};
