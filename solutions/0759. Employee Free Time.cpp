/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
private:
    vector<Interval> getSingleEmployeeFreeTime(vector<Interval>& workTimes) {
        int n = workTimes.size();
        vector<Interval> freeTimes = {{INT_MIN, workTimes[0].start}};
        for (int i = 1; i < n; i++) {
            freeTimes.push_back(Interval(workTimes[i - 1].end, workTimes[i].start));
        }
        freeTimes.push_back(Interval(workTimes[n - 1].end, INT_MAX));

        return freeTimes;
    }

    vector<Interval> getCommonFreeTime(vector<Interval>& freeTimes1, vector<Interval>& freeTimes2) {
        vector<Interval> commonTimes;
        int index1 = 0, index2 = 0;
        
        while (index1 < freeTimes1.size() && index2 < freeTimes2.size()) {
            if (freeTimes1[index1].end <= freeTimes2[index2].start) {
                index1++;
            } else if (freeTimes2[index2].end <= freeTimes1[index1].start) {
                index2++;
            } else {
                commonTimes.push_back(Interval(
                    max(freeTimes1[index1].start, freeTimes2[index2].start),
                    min(freeTimes1[index1].end, freeTimes2[index2].end)
                ));
                
                if (freeTimes1[index1].end < freeTimes2[index2].end) {
                    index1++;
                } else {
                    index2++;
                }
            }
        }

        return commonTimes;
    }

    void removeNonFiniteTimes(vector<Interval>& freeTimes) {
        // remove first element if infinite window
        if (freeTimes.size() && freeTimes[0].start == INT_MIN) {
            freeTimes.erase(freeTimes.begin());
        }

        // remove last element if infinite window
        int n = freeTimes.size();
        if (n && freeTimes[n - 1].end == INT_MAX) {
            freeTimes.erase(freeTimes.begin() + n - 1);
        }

        return;
    }

public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> curFreeTimes = getSingleEmployeeFreeTime(schedule[0]);
        for (int i = 1; i < schedule.size(); i++) {
            vector<Interval> nextFreeTimes = getSingleEmployeeFreeTime(schedule[i]);
            curFreeTimes = getCommonFreeTime(curFreeTimes, nextFreeTimes);
        }
        removeNonFiniteTimes(curFreeTimes);

        return curFreeTimes;
    }
};

// --------------------------------------------------------------------------------

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int, int>> events; // time, start or end
        for (auto& workTimes: schedule) {
            for (auto& workTime: workTimes) {
                events.push_back({workTime.start, -1});
                events.push_back({workTime.end, 1});
            }
        }

        sort(events.begin(), events.end());

        int prev = -1, sum = 0;
        vector<Interval> ans;

        for (auto event: events) {
            if (sum == 0 && prev >= 0) {
                ans.push_back(Interval(prev, event.first));
            }
            sum += event.second;
            prev = event.first;
        }

        return ans;
    }
};
