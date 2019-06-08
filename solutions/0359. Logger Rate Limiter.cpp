class Logger {
public:
    /** Initialize your data structure here. */
    
    unordered_map<string, int> hash;

    Logger() {
        hash.clear();        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = hash.find(message);
        if (it == hash.end() || timestamp - (*it).second >= 10) {
            hash[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
