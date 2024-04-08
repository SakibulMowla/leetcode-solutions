class TimeMap {
private:
    vector<vector<pair<int, string>>> store;
    unordered_map<string, int> keyToIndex;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if (!keyToIndex.contains(key)) {
            keyToIndex[key] = keyToIndex.size();
            store.push_back(vector<pair<int, string>>());
        }
        store[keyToIndex[key]].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!keyToIndex.contains(key)) {
            return "";
        }

        int index = keyToIndex[key];
        string ans = "";
        int low = 0, high = store[index].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (store[index][mid].first <= timestamp) {
                ans = store[index][mid].second;
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
