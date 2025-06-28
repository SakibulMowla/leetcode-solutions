class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k)
            return "0";

        deque<char> dq;
        string ans = "";

        for (int i = 0; i < n; i++) {
            char ch = num[i];
            while (!dq.empty() && dq.back() > ch) {
                dq.pop_back();
            }
            dq.push_back(ch);
            
            if (i >= k) {
                auto front = dq.front();
                dq.pop_front();

                if (ans.size() != 0 || front != '0') {
                    ans += front;
                }
            }
        }

        if (ans.size() == 0)
            ans = "0";

        return ans;
    }
};
