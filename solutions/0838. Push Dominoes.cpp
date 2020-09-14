/*
- O(NlogN)
- Priority Queue
*/

class Solution {
public:
    struct data {
        int position;
        int effectTime;
        int direction;

        data() {
        }

        data(int position, int effectTime, int direction): position(position), effectTime(effectTime), direction(direction) {
        }

        bool operator < (const data& x) const {
            return effectTime > x.effectTime;
        }
    };

    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<data> situations(n);
        priority_queue<data> PQ;

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L') {
                situations[i] = data(i, 0, -1);
                PQ.push(data(i, 0, -1));
            } else if (dominoes[i] == 'R') {
                situations[i] = data(i, 0, 1);
                PQ.push(data(i, 0, 1));
            } else {
                situations[i] = data(i, n + 1, 0);
            }
        }
        
        while (!PQ.empty()) {
            data now = PQ.top();
            PQ.pop();
            int nextPos = now.position + now.direction;
            if (nextPos != now.position && nextPos >= 0 && nextPos < n && situations[nextPos].effectTime >= now.effectTime + 1) {
                situations[nextPos].effectTime = now.effectTime + 1;
                situations[nextPos].direction += now.direction;
                PQ.push(situations[nextPos]);
            }
        }
        
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (situations[i].direction == -1) {
                ans += 'L';
            } else if (situations[i].direction == 1) {
                ans += 'R';
            } else {
                ans += '.';
            }
        }
        
        return ans;
    }
};

--------------------------------------------------------------------------------------------
/*
- O(N)
- 2 Linear Swaps
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> lForce(n), rForce(n);
        
        for (int i = 0, cur = 0; i < n; i++) {
            if (dominoes[i] == 'R') cur = n;
            else if (dominoes[i] == 'L') cur = 0;
            else cur = max(0, cur - 1);
            rForce[i] = cur;
        }
        
        for (int i = n - 1, cur = 0; i >= 0; i--) {
            if (dominoes[i] == 'L') cur = -n;
            else if (dominoes[i] == 'R') cur = 0;
            else cur = min(0, cur + 1);
            lForce[i] = cur;
        }
        
        for (int i = 0; i < n; i++) {
            int direction = lForce[i] + rForce[i];
            if (direction < 0) {
                dominoes[i] = 'L';
            } else if (direction > 0) {
                dominoes[i] = 'R';
            } else {
                dominoes[i] = '.';
            }
        }
        
        return dominoes;
    }
};
