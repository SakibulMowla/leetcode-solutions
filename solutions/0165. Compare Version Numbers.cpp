class Solution {
public:
    void normalize(vector<int>& V, int len) {
        int n = V.size();
        while (n < len) {
            V.push_back(0);
            n++;
        }
        return;
    }

    vector<int> parse(string& s, char delimiter) {
        vector<int> V;
        int buffer = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == delimiter) {
                V.push_back(buffer);
                buffer = 0;
            } else {
                buffer = buffer * 10 + s[i] - '0';
            }
        }
        if (buffer) {
            V.push_back(buffer);
        }
        return V;
    }

    int compare(vector<int>& V1, vector<int>& V2) {
        int len = V1.size();
        for (int i = 0; i < len; i++) {
            if (V1[i] > V2[i]) {
                return 1;
            } else if (V1[i] < V2[i]) {
                return -1;
            }
        }
        return 0;
    }

    int compareVersion(string version1, string version2) {
        vector<int> V1 = parse(version1, '.');
        vector<int> V2 = parse(version2, '.');

        int len = max(V1.size(), V2.size());
        normalize(V1, len);
        normalize(V2, len);

        return compare(V1, V2);
    }
};
