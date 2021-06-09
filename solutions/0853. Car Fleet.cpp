class Solution {
private:
    using pii = pair<int, int>;

    struct Data {
        int pos;
        int speed;
        Data(int pos, int speed): pos(pos), speed(speed) {}
        bool operator < (const Data& x) const {
            return pos > x.pos;
        }
    };
    
    bool greater(pii a, pii b) {
        return 1LL * a.first * b.second > 1LL * a.second * b.first;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) {
            return 0;
        }
        
        vector<Data> carInfo;
        for (int i = 0; i < n; i++) {
            carInfo.push_back(Data(position[i], speed[i]));
        }
        
        sort(carInfo.begin(), carInfo.end());
        
        pii last = {target - carInfo[0].pos, carInfo[0].speed}; 
        int fleets = 1;
    
        for (int i = 1; i < n; i++) {
            pii cur = {target - carInfo[i].pos, carInfo[i].speed};
            if (greater(cur, last)) {
                fleets++;
                last = cur;
            }
        }
        
        return fleets;
    }
};
