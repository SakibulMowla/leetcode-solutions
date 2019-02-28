class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int last = -1;
        string ans = "";
        while (A || B) {
            if (last == -1) {
                if (A > B) {
                    int take = min(2, A);
                    A -= take;
                    ans += string(take, 'a');
                    last = 0;
                } else {
                    int take = min(2, B);
                    B -= take;
                    ans += string(take, 'b');
                    last = 1;
                }
            } else if (last == 0) {
                int take = A >= B ? min(2, A) : 1;
                A -= take;
                ans += string(take, 'a');
            } else {
                int take = B >= A ? min(2, B) : 1;
                B -= take;
                ans += string(take, 'b');
            }
            last ^= 1;
        }
        return ans;
    }
};
