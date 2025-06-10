class LogSystem {
private:
    multimap<string, int> timeAndId;

    unordered_map<string, int> granularityLen = {
        {"Year", 4},
        {"Month", 7},
        {"Day", 10},
        {"Hour", 13},
        {"Minute", 16},
        {"Second", 19},
    };

public:
    LogSystem() {
        timeAndId.clear();
    }
    
    void put(int id, string timestamp) {
        timeAndId.insert({timestamp, id});
    }
    

    vector<int> retrieve(string start, string end, string granularity) {
        int len = granularityLen[granularity];

        string startPrefix = start.substr(0, len);
        string endPrefix = end.substr(0, len);

        vector<int> ans;
        for (auto it = timeAndId.lower_bound(startPrefix); it != timeAndId.end(); it++) {
            string keyPrefix = it->first.substr(0, len);
            if (keyPrefix > endPrefix) {
                break;
            }

            ans.push_back(it->second);
        }

        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
