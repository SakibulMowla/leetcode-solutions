class SparseVector {
public:
    vector<pair<int, int> > indexVal;

    SparseVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                indexVal.push_back({ i, nums[i] });
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int len1 = indexVal.size();
        int len2 = vec.indexVal.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int ans = 0;

        while (ptr1 < len1 && ptr2 < len2) {
            int index1 = indexVal[ptr1].first;
            int val1 = indexVal[ptr1].second;
            int index2 = vec.indexVal[ptr2].first;
            int val2 = vec.indexVal[ptr2].second;

            if (index1 < index2) {
                ptr1++;
            }
            else if (index1 > index2) {
                ptr2++;
            }
            else {
                ptr1++;
                ptr2++;
                ans += val1 * val2;
            }
        }

        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
