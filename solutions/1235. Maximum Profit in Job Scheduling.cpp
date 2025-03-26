class Solution {
private:
    int n;

    struct Job {
        int start, end, profit;
        Job(int start, int end, int profit): start(start), end(end), profit(profit) {

        }
        bool operator <(Job& newJob) const {
            return start < newJob.start;
        }
    };

    int findNextIndex(int low, int after, vector<Job>& jobs) {
        int high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid].start >= after) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int findMaxProfit(int index, vector<Job>& jobs, vector<int>& dp) {
        if (index == n) {
            return 0;
        }

        if (dp[index] == -1) {
            dp[index] = findMaxProfit(index + 1, jobs, dp);

            int nextIndex = findNextIndex(index + 1, jobs[index].end, jobs);
            dp[index] = max(
                dp[index],
                jobs[index].profit + findMaxProfit(nextIndex, jobs, dp)
            );
        }

        return dp[index];
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        vector<Job> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);
        return findMaxProfit(0, jobs, dp);
    }
};
