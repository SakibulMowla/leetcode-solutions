class Solution {
public:
    int compress(vector<char>& chars) {
        int length = chars.size();
        int index = 0;
        for (int l = 0; l < length; l++) {
            int r = l;
            while (r + 1 < length && chars[r + 1] == chars[l]) {
                r++;
            }
            string count = to_string(r - l + 1);
            chars[index++] = chars[l];
            if (r > l) {
                for (char c: count) {
                    chars[index++] = c;
                }
            }
            l = r;
        }
        return index;
    }
};
