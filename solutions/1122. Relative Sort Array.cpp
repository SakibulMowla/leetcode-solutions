class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> numToOrder, orderToNum;
        for (int i = 0; i < arr2.size(); i++) {
            numToOrder[arr2[i]] = i;
            orderToNum[i] = arr2[i];
        }
        
        vector<int> toSort, rest;
        for (int i = 0; i < arr1.size(); i++) {
            if (numToOrder.find(arr1[i]) == numToOrder.end()) {
                rest.push_back(arr1[i]);
            } else {
                toSort.push_back(numToOrder[arr1[i]]);
            }
        }
        
        sort(toSort.begin(), toSort.end());
        sort(rest.begin(), rest.end());
        for (int& num: toSort) {
            num = orderToNum[num];
        }
        for (int num: rest) {
            toSort.push_back(num);
        }
        
        return toSort;
    }
};
