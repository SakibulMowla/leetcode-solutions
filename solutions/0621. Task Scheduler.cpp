class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;
        for (int i = 0; i < tasks.size(); i++) {
            if (freq.find(tasks[i]) == freq.end()) {
                freq[tasks[i]] = 0;
            }
            freq[tasks[i]]++;
        }
        
        priority_queue<int> pq;
        for (auto it: freq) {
            pq.push(it.second);
        }

        int current = 0;
        while (!pq.empty()) {
            int qSize = pq.size();
            int positions = n + 1;
            vector<int> tmp;
            for (int i = 0; i < qSize && positions; i++) {
                int top = pq.top();
                pq.pop();
                if (top > 1) {
                    tmp.push_back(top - 1);
                }
                positions--;
                current++;
            }
            if (tmp.size() && positions) {
                current += positions;
            }
            for (int x: tmp) {
                pq.push(x);
            }
        }
        
        return current;
    }
};
