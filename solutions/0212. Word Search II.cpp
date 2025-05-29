struct TrieNode {
    bool isWord;
    unordered_map<char, int> child;
    
    TrieNode(): isWord(false) {}
};

class Solution {
private:
    vector<TrieNode> tree;
    int rows, cols;
    vector<string> ans;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void insert(string& word) {
        int node = 0;
        for (char ch: word) {
            if (tree[node].child.find(ch) == tree[node].child.end()) {
                tree[node].child[ch] = tree.size();
                tree.push_back(TrieNode());
            }
            node = tree[node].child[ch];
        }
        tree[node].isWord = true;
    }

    bool isWithinBoard(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    void backtrack(int x, int y, int node, vector<vector<char>>& board, string& cur) {
        char letter = board[x][y];
        cur.push_back(letter);

        if (tree[node].isWord) {
            ans.push_back(cur);
            tree[node].isWord = false;
        }

        board[x][y] = '#';

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            if (!isWithinBoard(newX, newY)) {
                continue;
            }

            char ch = board[newX][newY];

            if (tree[node].child.find(ch) != tree[node].child.end()) {
                backtrack(newX, newY, tree[node].child[ch], board, cur);
            }
        }

        board[x][y] = letter;
        cur.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // insert root node
        tree.push_back(TrieNode());
        for (string& word: words) {
            insert(word);
        }

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char ch = board[i][j];
                if (tree[0].child.find(ch) != tree[0].child.end()) {
                    string cur;
                    backtrack(i, j, tree[0].child[ch], board, cur);
                }
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------------------------------------

class Solution {
    int rows;
    int cols;

    struct Trie {
        bool isEnd;
        unordered_map<char, int> child;
        Trie() {
            isEnd = false;
        }
    };
    
    void addWord(string& word, vector<Trie>& tree) {
        int node = 0;
        for (int i = 0; i < word.size(); i++) {
            if (tree[node].child.find(word[i]) == tree[node].child.end()) {
                tree[node].child[word[i]] = tree.size();
                tree.push_back(Trie());
            }
            node = tree[node].child[word[i]];
        }
        tree[node].isEnd = true;
        return;
    }
    
    unordered_map<char, vector<pair<int, int>>> getCharToCord(vector<vector<char>>& board) {
        unordered_map<char, vector<pair<int, int>>> charToCord;
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                if (charToCord.find(board[i][j]) == charToCord.end()) {
                    charToCord[board[i][j]] = vector<pair<int, int>>();
                }
                charToCord[board[i][j]].push_back({i, j});
            }
        }
        
        return charToCord;
    }
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    void backtrack(int x, int y, int node, vector<vector<bool>>& visited, vector<vector<char>>& board, string& cur, vector<string>& ans, vector<Trie>& tree) {
        visited[x][y] = true;
        cur.push_back(board[x][y]);
        if (tree[node].isEnd) {
            ans.push_back(cur);
            tree[node].isEnd = false;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < this->rows && ny >= 0 && ny < this->cols && !visited[nx][ny] && tree[node].child.find(board[nx][ny]) != tree[node].child.end()) {
                backtrack(nx, ny, tree[node].child[board[nx][ny]], visited, board, cur, ans, tree);
                cur.pop_back();
                visited[nx][ny] = false;
            }
        }
        
        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<Trie> tree;
        tree.push_back(Trie());
        
        for (string word: words) {
            addWord(word, tree);
        }
        
        this->rows = board.size();
        this->cols = board[0].size();
        
        unordered_map<char, vector<pair<int, int>>> charToCord = getCharToCord(board);
        
        vector<vector<bool>> visited(this->rows, vector<bool> (this->cols, false));
        vector<string> ans;
        
        for (auto treeIt: tree[0].child) {
            for (auto cord: charToCord[treeIt.first]) {
                int node = treeIt.second;
                string cur;
                backtrack(cord.first, cord.second, node, visited, board, cur, ans, tree);
                cur.pop_back();
                visited[cord.first][cord.second] = false;
            }
        }
        
        return ans;
    }
};
