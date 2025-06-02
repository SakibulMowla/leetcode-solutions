class Solution {
private:
    int recurIndex;
    unordered_map<int, int> seen;

    string divide(long long rem, long long denominator, int index) {
        if (seen.find(rem) != seen.end()) {
            recurIndex = seen[rem];
            return "";
        }

        if (rem == 0) {
            return "";
        }

        seen[rem] = index;

        return to_string(rem / denominator) + divide((rem % denominator) * 10, denominator, index + 1);
    }

public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        int sign = (numerator < 0 ? -1 : 1) * (denominator < 0 ? -1 : 1);
        string ans = "";

        if (sign == -1) {
            ans += "-";
        }

        long long res = 1L * labs(numerator) / labs(denominator);
        long long rem = 1l * labs(numerator) % labs(denominator);

        ans += to_string(res);

        if (rem != 0) {
            ans += ".";
            rem *= 10l;

            recurIndex = -1;
            string decPart = divide(rem, labs(denominator), 0);

            if (recurIndex != -1) {
                decPart.insert(recurIndex, "(");
                decPart += ")";
            }

            ans += decPart;
        }

        return ans;
    }
};
