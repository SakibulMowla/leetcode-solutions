class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin() + 0, 0);
        flowerbed.push_back(0);

        for (int i = 1; i < flowerbed.size() - 1 && n > 0; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};
