class Solution {
public:
    vector<pair<char, int>> construct(string& s) {
        vector<pair<char, int>> ret;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'X') {
                ret.push_back({s[i], i});
            }
        }
        return ret;
    }

    bool canTransform(string start, string end) {
        int lenStart = start.size();
        int lenEnd = end.size();
        if (lenStart != lenEnd) {
            return false;
        }
        
        vector<pair<char, int>> startForm = construct(start);
        vector<pair<char, int>> endForm = construct(end);
        
        if (startForm.size() != endForm.size()) {
            return false;
        }
        
        for (int i = 0; i < startForm.size(); i++) {
            if (startForm[i].first != endForm[i].first) {
                return false;
            }
            if (startForm[i].first == 'R') {
                if (startForm[i].second > endForm[i].second) {
                    return false;
                }
            } else {
                if (startForm[i].second < endForm[i].second) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
