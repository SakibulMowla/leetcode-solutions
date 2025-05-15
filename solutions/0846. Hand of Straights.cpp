class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        map<int, int> count;
        for (int card: hand) {
            count[card]++;
        }

        int groups = n / groupSize;
        while (groups--) {
            auto it = count.begin();
            int key = it->first;
            it->second--;
            if (it->second == 0) {
                count.erase(it);
            }

            for (int i = 1; i < groupSize; i++) {
                if (count[key + i] == 0) {
                    return false;
                }

                count[key + i]--;
                if (count[key + i] == 0) {
                    count.erase(count.find(key + i));
                }
            }
        }

        return true;
    }
};
