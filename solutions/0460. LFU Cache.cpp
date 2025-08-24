class Node {
public:
    int key, val, freq;

    Node (int k, int v, int f = 1): key(k), val(v), freq(f) {}
};

class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>::iterator> cacheMap;
    unordered_map<int, list<Node>> freqMap;

    void updateFreq(list<Node>::iterator it) {
        int oldFreq = it->freq;
        int key = it->key;
        int val = it->val;

        // delete from old list
        freqMap[oldFreq].erase(it);
        if (freqMap[oldFreq].size() == 0) {
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq)
                minFreq++;
        }

        // add to new list
        int newFreq = oldFreq + 1;
        freqMap[newFreq].push_front(Node(key, val, newFreq));
        cacheMap[key] = freqMap[newFreq].begin();
    }

public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {
        
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        auto it = cacheMap[key];
        int val = it->val;
        updateFreq(it);

        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;
        
        // Upadte if key exists
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            it->val = value;
            updateFreq(it);
            return;
        }

        // Evict using LFU
        if (cacheMap.size() == capacity) {
            auto it = prev(freqMap[minFreq].end());
            cacheMap.erase(it->key);
            freqMap[minFreq].erase(it);
            if (freqMap[minFreq].size() == 0)
                freqMap.erase(minFreq);
        }

        // Insert new
        freqMap[1].push_front(Node(key, value));
        cacheMap[key] = freqMap[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
