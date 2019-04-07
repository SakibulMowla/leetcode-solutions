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

