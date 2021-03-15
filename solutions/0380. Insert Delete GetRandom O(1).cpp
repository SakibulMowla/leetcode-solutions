class RandomizedSet {
public:
    vector<int> vals;
    unordered_map<int, int> valToIndex;

    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            valToIndex[val] = vals.size();
            vals.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            int index = valToIndex[val];
            vals[index] = vals.back();
            valToIndex[vals[index]] = index;
            valToIndex.erase(val);
            vals.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
