/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int n1 = A.size(), n2 = B.size();
        vector<Interval> ans;
        
        for (int i = 0, j = 0; i < n1 && j < n2; ) {
            int lft = max(A[i].start, B[j].start);
            int rht = min(A[i].end, B[j].end);
            
            if (lft <= rht) ans.push_back(Interval(lft, rht));
            
            if (A[i].end < B[j].end) i++;
            else j++;
        }
        
        return ans;
    }
};
