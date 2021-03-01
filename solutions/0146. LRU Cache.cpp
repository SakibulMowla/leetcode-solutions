class LRUCache {
public:
    int capacity;
    list<int> keys;
    unordered_map<int, int> keyToValue;
    unordered_map<int, list<int>::iterator> keyIterator;

    LRUCache(int capacity): capacity(capacity) {
    }
    
    int get(int key) {
        if (keyToValue.find(key) == keyToValue.end()) {
            return -1;
        } else {
            keys.erase(keyIterator[key]);
            keys.push_front(key);
            keyIterator[key] = keys.begin();
            return keyToValue[key];
        }
    }
    
    void put(int key, int value) {
        if (keyToValue.find(key) != keyToValue.end()) {
            keys.erase(keyIterator[key]);
        }
        keyToValue[key] = value;
        keys.push_front(key);
        keyIterator[key] = keys.begin();
        
        if (keys.size() > capacity) {
            int keyToDelete = *prev(keys.end());
            keyToValue.erase(keyToValue.find(keyToDelete));
            keys.erase(keyIterator[keyToDelete]);
            keyIterator.erase(keyIterator.find(keyToDelete));
        }
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
