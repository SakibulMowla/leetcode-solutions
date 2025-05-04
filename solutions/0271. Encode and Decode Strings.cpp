class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string enc;
        for (auto& str: strs) {
            enc += to_string(str.size()) + " " + str;
        }
        return enc;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.size();
        vector<string> dec;
        for (int i = 0; i < n; i++) {
            int j = i;
            int len = 0;
            while (s[j] != ' ') {
                len = len * 10 + s[j] - '0';
                j++;
            }
            dec.push_back(s.substr(j + 1, len));
            i = j + len;
        }
        return dec;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


// --------------------------------------------

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string& str: strs) {
            res += to_string((int)str.size()) + ",";
        }
        res += "#";

        for (string& str: strs) {
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<int> lens;
        int index = 0;
        for (int len = 0; index < s.size(); index++) {
            if (s[index] == '#') {
                break;
            } else if (s[index] == ',') {
                lens.push_back(len);
                len = 0;
            } else {
                len = len * 10 + (s[index] - '0');
            }
        }
        index++;

        vector<string> res;
        for (int len: lens) {
            string str = s.substr(index, len);
            res.push_back(str);
            index += len;
        }

        return res;
    }
};

