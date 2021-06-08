/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int, Employee*> idToEmployee;

        for (int i = 0; i < n; i++) {
            idToEmployee[employees[i]->id] = employees[i];
        }

        int sum = 0;
        queue<Employee*> q;
        q.push(idToEmployee[id]);
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            sum += cur->importance;
            
            for (int v: cur->subordinates) {
                q.push(idToEmployee[v]);
            }
        }

        return sum;
    }
};
