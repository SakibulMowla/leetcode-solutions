// Question: https://codezym.com/question/9

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
    // atomic to make thread safe
    vector<atomic<int>> pageVisits;

public:
    Solution(int totalPages) : pageVisits(totalPages) {
    }    

    void incrementVisitCount(int pageIndex) {
        if (pageIndex < 0 || pageIndex >= pageVisits.size()) {
            return;
        }

        pageVisits[pageIndex]++;
    }

    int getVisitCount(int pageIndex) {
        if (pageIndex < 0 || pageIndex >= pageVisits.size()) {
            return 0;
        }

        return pageVisits[pageIndex];
    }
};

int main() {
    // Test cases to validate the solution
    Solution solution(2);
    solution.incrementVisitCount(0);
    solution.incrementVisitCount(1);
    solution.incrementVisitCount(1);
    solution.incrementVisitCount(1);
    solution.incrementVisitCount(0);

    cout << solution.getVisitCount(0) << endl;
    cout << solution.getVisitCount(1) << endl;

    return 0;
}
