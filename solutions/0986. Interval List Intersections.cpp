class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int len1 = firstList.size();
        int len2 = secondList.size();
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        vector<vector<int>> ans;
        
        while (ptr1 < len1 && ptr2 < len2) {
            int lft = max(firstList[ptr1][0], secondList[ptr2][0]);
            int rht = min(firstList[ptr1][1], secondList[ptr2][1]);
            if (lft <= rht) {
                ans.push_back({lft, rht});   
            }
            if (firstList[ptr1][1] < secondList[ptr2][1]) {
                ptr1++;
            } else {
                ptr2++;
            }
        }
        
        return ans;
    }
};
