// =============================================
// Binary Search O(n log m)
// =============================================
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
private:
  int binarySearch(int row, int cols, BinaryMatrix& binaryMatrix) {
    int lo = 0;
    int hi = cols - 1;
    int index = numeric_limits<int>::max();
    
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (binaryMatrix.get(row, mid) == 1) {
        index = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    
    return index;
  }

public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector<int> dimensions = binaryMatrix.dimensions();
      
      int ans = dimensions[1];
      for (int i = 0; i < dimensions[0]; i++) {
        int cur = binarySearch(i, ans, binaryMatrix);
        ans = min(ans, cur);
      }
      
      return ans == dimensions[1] ? -1 : ans;
    }
};

//===================================
// Greedy O(n + m)
//-==================================
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector<int> dimensions = binaryMatrix.dimensions();
      
      int rows = dimensions[0];
      int cols = dimensions[1];
      
      int x = 0;
      int y = cols - 1;
      
      while (x < rows && y >= 0) {
        if (binaryMatrix.get(x, y) == 1) {
          y--;
        } else {
          x++;
        }
      }
      
      return y == cols - 1 ? -1 : y + 1;
    }
};
