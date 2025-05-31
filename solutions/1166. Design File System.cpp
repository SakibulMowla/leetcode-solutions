// Trie

struct FileNode {
    int val;
    unordered_map<string, int> child;
    FileNode() {}
};

class FileSystem {
private:
    vector<FileNode> tree;

    vector<string> parse(string& path) {
        int n = path.size();
        string part = "";
        vector<string> parts;

        for (int i = 1; i < n; i++) {
            if (path[i] == '/') {
                parts.push_back(part);
                part = "";
            } else {
                part += path[i];
            }
        }
        parts.push_back(part);

        return parts;
    }

    bool insert(vector<string>& parts, int val) {
        int n = parts.size();
        int node = 0;
        for (int i = 0; i < n - 1; i++) {
            string& part = parts[i];
            if (tree[node].child.find(part) == tree[node].child.end()) {
                return false;
            }
            node = tree[node].child[part];
        }

        // path already exists
        string& part = parts[n - 1];
        if (tree[node].child.find(part) != tree[node].child.end()) {
            return false;
        }

        // create new node
        tree[node].child[part] = tree.size();
        tree.push_back(FileNode());
        node = tree[node].child[part];
        tree[node].val = val;

        return true;
    }

public:
    FileSystem() {
        // insert root node
        tree.push_back(FileNode());    
    }
    
    bool createPath(string path, int value) {
        vector<string> parts = parse(path);

        return insert(parts, value);
    }
    
    int get(string path) {
        vector<string> parts = parse(path);

        int n = parts.size();
        int node = 0;
        for (int i = 0; i < n; i++) {
            string& part = parts[i];
            if (tree[node].child.find(part) == tree[node].child.end()) {
                return -1;
            }
            node = tree[node].child[part];
        }

        return tree[node].val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

// ----------------------------------------------------------------------

class FileSystem {
private:
    unordered_map<string, int> pathToValue;

    int findLastIndexOf(string& path, char token) {
        for (int i = path.size() - 1; i >= 0; i--) {
            if (path[i] == token) {
                return i;
            }
        }
        return -1;
    }

public:
    FileSystem() {
        pathToValue.clear();
        pathToValue[""] = -1;
    }
    
    bool createPath(string path, int value) {
        if (pathToValue.find(path) != pathToValue.end()) {
            return false;
        }

        string par = path.substr(0, findLastIndexOf(path, '/'));
        if (pathToValue.find(par) == pathToValue.end()) {
            return false;
        }

        pathToValue[path] = value;
        return true;
    }
    
    int get(string path) {
        if (pathToValue.find(path) == pathToValue.end()) {
            return -1;
        }

        return pathToValue[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
