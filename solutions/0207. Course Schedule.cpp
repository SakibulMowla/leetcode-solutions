class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> dependents(numCourses);
        for (auto prerequisite: prerequisites) {
            inDegree[prerequisite[0]]++;
            dependents[prerequisite[1]].push_back(prerequisite[0]);
        }

        queue<int> availableCourses;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                availableCourses.push(i);
            }
        }

        int courseTaken = 0;
        while (!availableCourses.empty()) {
            int course = availableCourses.front();
            availableCourses.pop();
            courseTaken++;

            for (int dependent: dependents[course]) {
                inDegree[dependent]--;
                if (inDegree[dependent] == 0) {
                    availableCourses.push(dependent);
                }
            }
        }

        return courseTaken == numCourses;
    }
};
