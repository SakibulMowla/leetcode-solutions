class Solution {
public:
    struct data {
        int wIndex, bIndex, dist;
        data(int wIndex, int bIndex, int dist):
            wIndex(wIndex), bIndex(bIndex), dist(dist) {}
        bool operator <(const data& x) const {
            if (dist == x.dist) {
                if (wIndex == x.wIndex) {
                    return bIndex > x.bIndex;
                }
                return wIndex > x.wIndex;
            }
            return dist > x.dist;
        }
    };
    
    int findDist(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int wsz = workers.size(), bsz = bikes.size();
        priority_queue<data> pq;

        for (int i = 0; i < wsz; i++) {
            for (int j = 0; j < bsz; j++) {
                pq.push(data(i, j, findDist(workers[i], bikes[j])));
            }
        }
        
        vector<bool> settledWorker(wsz, false), settledBike(bsz, false);
        vector<int> ans(wsz);

        while (!pq.empty()) {
            data u = pq.top();
            pq.pop();
            int worker = u.wIndex;
            int bike = u.bIndex;
            if (!settledWorker[worker] && !settledBike[bike]) {
                settledWorker[worker] = true;
                settledBike[bike] = true;
                ans[worker] = bike;
            }
        }
        
        return ans;
    }
};
