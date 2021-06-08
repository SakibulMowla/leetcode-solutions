class Logger {
private:
unordered_map<string, int> messageToTime;

public:
    /** Initialize your data structure here. */
    Logger() {
        messageToTime.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (messageToTime.find(message) == messageToTime.end() || timestamp - messageToTime[message] >= 10) {
            messageToTime[message] = timestamp;
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
