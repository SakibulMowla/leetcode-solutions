// DP

class Solution {
private:
    double solve(int index, int left, vector<vector<double>>& dp, 
                 vector<double>& doublePrices) {
        if (index == -1) {
            return left == 0 ? 0 : numeric_limits<double>::max();
        }

        if (left < 0) {
            return numeric_limits<double>::max();
        }

        double& ret = dp[index][left];
        if (ret != -1) {
            return ret;
        }

        ret = doublePrices[index] - floor(doublePrices[index]) + 
              solve(index - 1, left, dp, doublePrices);
        if (doublePrices[index] != ceil(doublePrices[index])) {
            ret = min(ret, ceil(doublePrices[index]) - doublePrices[index] + 
                            solve(index - 1, left - 1, dp, doublePrices));
        }
        
        return ret;
    }

    string processAnswer(double res) {
        string ans = to_string(res);
        int decimalIndex = ans.find(".");
        
        return ans.substr(0, decimalIndex + 4);
    }

public:
    string minimizeError(vector<string>& prices, int target) {
        int n = prices.size();
        vector<double> doublePrices(n);

        double min = 0, max = 0;
        for (int i = 0; i < n; i++) {
            doublePrices[i] = stod(prices[i]);
            min += floor(doublePrices[i]);
            max += ceil(doublePrices[i]);
        }

        if (min > target || max < target) {
            return "-1";
        }

        int left = target - min;
        vector<vector<double>> dp(n, vector<double> (left + 1, -1));

        return processAnswer(solve(n - 1, left, dp, doublePrices));
    }
};


// --------------------------------------------------------------------------------

// Greedy

class Solution {
private:
    string processResult(double res) {
        string ans = to_string(res);
        int decimalIndex = ans.find(".");
        return ans.substr(0, decimalIndex + 1 + 3);
    }

public:
    string minimizeError(vector<string>& prices, int target) {
        int n = prices.size();
        int min = 0, max = 0;
        vector<double> fractions(n);

        for (int i = 0; i < n; i++) {
            string price = prices[i];
            double dPrice = stod(price);
            
            min += floor(dPrice);
            max += ceil(dPrice);

            fractions[i] = dPrice - floor(dPrice);
        }

        if (min > target || max < target) {
            return "-1";
        }

        sort(fractions.rbegin(), fractions.rend());
        int left = target - min;
        double res = 0;

        for (int i = 0; i < n; i++) {
            if (left) {
                res += 1 - fractions[i];
                left--;
            } else {
                res += fractions[i];
            }
        }

        return processResult(res);
    }
};
