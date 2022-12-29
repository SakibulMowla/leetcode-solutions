// ---------------------- BFS ---------------------- //

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        queue<Node*> q;
        q.push(node);
        unordered_map<int, Node*> duplicateMap;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (duplicateMap.find(front->val) == duplicateMap.end()) {
                duplicateMap[front->val] = new Node(front->val);
            }
            Node* dupFront = duplicateMap[front->val];
            
            for (Node* adjacent: front->neighbors) {
                if (duplicateMap.find(adjacent->val) == duplicateMap.end()) {
                    duplicateMap[adjacent->val] = new Node(adjacent->val);
                    q.push(adjacent);
                }
                dupFront->neighbors.push_back(duplicateMap[adjacent->val]);
            }
        }
        
        return duplicateMap[1];
    }
};

// ---------------------- DFS ---------------------- //

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<int, Node*>& duplicateMap) {
        if (duplicateMap.find(node->val) != duplicateMap.end()) {
            return;
        }
        duplicateMap[node->val] = new Node(node->val);
        for (Node* adjacent: node->neighbors) {
            dfs(adjacent, duplicateMap);
            duplicateMap[node->val]->neighbors.push_back(duplicateMap[adjacent->val]);
        }
        return;
    }
 
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<int, Node*> duplicateMap;
        dfs(node, duplicateMap);
        return duplicateMap[1];
    }
};
