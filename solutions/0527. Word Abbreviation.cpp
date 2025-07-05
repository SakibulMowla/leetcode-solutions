// Simulation

class Solution {
private:
    string abbreviate(string& word, int prefixLen = 1) {
        return word.size() - prefixLen <= 2 ? 
               word :
               word.substr(0, prefixLen) + to_string(word.size() - prefixLen - 1) + word.back();
    }

public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, vector<int>> groups;

        for (int i = 0; i < words.size(); i++) 
            groups[abbreviate(words[i])].push_back(i);

        for (auto& [abbreviation, members]: groups) {
            int len = words[members[0]].size();
            for (int prefixLen = 1; prefixLen <= len; prefixLen++) {
                unordered_map<string, int> abbreviations;
                for (int member: members)
                    abbreviations[abbreviate(words[member], prefixLen)]++;
                
                for (int i = members.size() - 1; i >= 0; i--) {
                    string abbreviation = abbreviate(words[members[i]], prefixLen);
                    if (abbreviations[abbreviation] == 1) {
                        words[members[i]] = abbreviation;
                        members.erase(members.begin() + i);
                    }
                }
            }
        }

        return words;
    }
};

// --------------------------------------------------------

// Trie

class Trie {
public:
    int count;
    int child[26];

    Trie(): count(0) {
        memset(child, -1, sizeof(child));
    }
};

class Solution {
private:
    string abbreviate(string& word, int prefixLen = 1) {
        return word.size() - prefixLen <= 2 ? 
               word :
               word.substr(0, prefixLen) + to_string(word.size() - prefixLen - 1) + word.back();
    }

    void insert(string& word, vector<Trie>& tree) {
        int node = 0;
        for (char ch: word) {
            int index = ch - 'a';
            if (tree[node].child[index] == -1) {
                tree[node].child[index] = tree.size();
                tree.emplace_back(Trie());
            }
            node = tree[node].child[index];
            tree[node].count++;
        }
    }

    int findPrefixLen(string& word, vector<Trie>& tree) {
        int node = 0, len = 0;
        for (char ch: word) {
            node = tree[node].child[ch - 'a'];
            len++;
            if (tree[node].count == 1) 
                break;
        }

        return len;
    }

public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, vector<int>> groups;

        for (int i = 0; i < words.size(); i++) 
            groups[abbreviate(words[i])].push_back(i);

        for (auto& [_, members]: groups) {
            vector<Trie> tree;
            // insert root
            tree.push_back(Trie());

            for (int member: members)
                insert(words[member], tree);

            for (int member: members) {
                int prefixLen = findPrefixLen(words[member], tree);
                words[member] = abbreviate(words[member], prefixLen);
            }
        }

        return words;
    }
};
