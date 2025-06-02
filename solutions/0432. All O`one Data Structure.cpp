class AllOne {
    struct Node {
        int freq;
        std::unordered_set<std::string> keys;
        Node(int f) : freq(f) {}
    };
    
    std::list<Node> nodes;  // Doubly linked list of nodes
    std::unordered_map<std::string, std::list<Node>::iterator> keyToNode;
    
public:
    AllOne() {
        nodes.push_back(Node(0));  // dummy head with freq 0
    }
    
    void inc(const std::string& key) {
        if (keyToNode.count(key)) {
            auto curr = keyToNode[key];
            auto next = std::next(curr);
            curr->keys.erase(key);
            
            if (next == nodes.end() || next->freq != curr->freq + 1) {
                next = nodes.insert(next, Node(curr->freq + 1));
            }
            next->keys.insert(key);
            keyToNode[key] = next;
            
            if (curr->keys.empty()) {
                nodes.erase(curr);
            }
        } else {
            auto first = nodes.begin();
            auto next = std::next(first);
            if (next == nodes.end() || next->freq != 1) {
                next = nodes.insert(next, Node(1));
            }
            next->keys.insert(key);
            keyToNode[key] = next;
        }
    }
    
    void dec(const std::string& key) {
        if (!keyToNode.count(key)) return;

        auto curr = keyToNode[key];
        curr->keys.erase(key);
        
        if (curr->freq == 1) {
            keyToNode.erase(key);
        } else {
            auto prev = std::prev(curr);
            if (prev == nodes.begin() || prev->freq != curr->freq - 1) {
                prev = nodes.insert(curr, Node(curr->freq - 1));
            }
            prev->keys.insert(key);
            keyToNode[key] = prev;
        }
        
        if (curr->keys.empty()) {
            nodes.erase(curr);
        }
    }
    
    std::string getMaxKey() {
        if (nodes.size() <= 1) return ""; // Only dummy head
        return *(--nodes.end())->keys.begin();
    }
    
    std::string getMinKey() {
        if (nodes.size() <= 1) return "";
        auto it = ++nodes.begin();
        return *(it->keys.begin());
    }
};

// --------------------------------------------------------------------------------------------------

class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> map; // map from key to the Node

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;        
    }
    
    void inc(string key) {
        if (map.find(key) != map.end()) { // key exists
            Node* node = map[key];
            int freq = node->freq;
            node->keys.erase(key);

            Node* nextNode = node->next;
            if (nextNode == tail || nextNode->freq != freq + 1) {
                Node* newNode = new Node(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            if (node->keys.empty()) {
                removeNode(node);
            }
        } else { // key doesn't exist
            Node* firstNode = head->next;
            if (firstNode == tail || firstNode->freq > 1) {
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }
    
    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;
        }

        Node* node = map[key];
        int freq = node->freq;
        node->keys.erase(key);

        if (freq == 1) {
            map.erase(key);
        } else {
            Node* prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                Node* newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        if (node->keys.empty()) {
            removeNode(node);
        }
    }
    
    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
