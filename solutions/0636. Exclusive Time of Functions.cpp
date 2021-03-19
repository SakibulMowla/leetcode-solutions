class Solution {
private:
    struct Data {
        int id;
        bool isStart;
        int timestamp;
        int index;
        Data(int id, bool isStart, int timestamp, int index) : id(id), isStart(isStart), timestamp(timestamp), index(index) {}
    };
    
    vector<string> split(string& log) {
        vector<string> tmp;
        string running;
        
        for (char ch: log) {
            if (ch == ':') {
                tmp.push_back(running);
                running = "";
            } else {
                running += ch;
            }
        }
        tmp.push_back(running);
        
        return tmp;
    }
    
    Data parseLog(string log, int index) {
        vector<string> tmp = split(log);
        Data current = Data(stoi(tmp[0]), tmp[1] == "start", stoi(tmp[2]), index);
        return current;
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> stk;
        
        Data cur = parseLog(logs[0], 0);
        int prev = cur.timestamp;
        stk.push(cur.id);
        
        for (int i = 1; i < logs.size(); i++) {
            Data cur = parseLog(logs[i], i);
            if (cur.isStart) {
                if (!stk.empty()) {
                    ans[stk.top()] += cur.timestamp - prev;
                }
                stk.push(cur.id);
                prev = cur.timestamp;
            } else {
                ans[cur.id] += cur.timestamp - prev + 1;
                stk.pop();
                prev = cur.timestamp + 1;
            }
        }
        
        return ans;
    }
};
