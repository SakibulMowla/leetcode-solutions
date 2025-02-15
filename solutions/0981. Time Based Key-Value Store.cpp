class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        vector<pair<int, string>>& keyEntries = store[key];

        string ans = "";
        int low = 0, high = keyEntries.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (keyEntries[mid].first <= timestamp) {
                ans = keyEntries[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
