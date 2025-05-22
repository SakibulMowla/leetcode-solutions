class Vector2D {
private:
    vector<vector<int>> vec;
    int currentRow, currentCol;

public:
    Vector2D(vector<vector<int>>& vec): vec(vec) {
        currentRow = 0;
        currentCol = 0;
    }

    void advanceToNext() {
        while (currentRow < vec.size() && currentCol == vec[currentRow].size()) {
            currentRow++;
            currentCol = 0;
        }
    }
    
    int next() {
        if (!hasNext()) {
            return -1;
        }

        return vec[currentRow][currentCol++];
    }
    
    bool hasNext() {
        advanceToNext();
        return currentRow < vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
