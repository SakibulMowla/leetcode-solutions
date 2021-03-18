class Solution {
private:
    struct Data {
        int dist;
        int index;
        Data(int dist, int index): dist(dist), index(index) {}
        bool operator < (const Data& x) const {
            return dist < x.dist;
        }
    };
    
    int pointToDist(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<Data> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push(Data(pointToDist(points[i]), i));
            if (i >= k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) {
            Data top = pq.top();
            pq.pop();
            ans.push_back(points[top.index]);
        }
        
        return ans;
    }
};
