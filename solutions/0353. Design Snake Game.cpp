class SnakeGame {
private:
    int height;
    int width;
    bool isGameOver = false;
    vector<vector<bool>> grid;
    deque<vector<int>> snake;
    unordered_map<string, vector<int>> dir = {
        { "U", {-1, 0} },
        { "L", {0, -1} },
        { "R", {0, 1} },
        { "D", {1, 0} }
    };
    vector<vector<int>> food;
    int foodPos;

    vector<int> findNext(string direction, vector<int>& cur) {
        vector<int> ans(2);
        ans[0] = cur[0] + dir[direction][0];
        ans[1] = cur[1] + dir[direction][1];
        return ans;
    }
    
    bool isValid(vector<int>& cur) {
        return cur[0] >= 0 && cur[0] < height && cur[1] >= 0 && cur[1] < width;
    }
    
    bool isNotBody(vector<int>& cur) {
        if (cur == snake.back()) {
            return true;
        }
        return grid[cur[0]][cur[1]] == false;
    }
    
    bool isFood(vector<int>& cur) {
        return foodPos < food.size() && cur == food[foodPos];
    }

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food): foodPos(0), food(food), isGameOver(false), grid(height, vector<bool> (width, false)), height(height), width(width) {
        snake.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (isGameOver) {
            return -1;
        }

        vector<int> cur = snake.front();
        vector<int> next = findNext(direction, cur);
        
        if (isValid(next) && isNotBody(next)) {
            if (isFood(next)) {
                foodPos++;
            } else {
                grid[snake.back()[0]][snake.back()[1]] = false;
                snake.pop_back();
            }
            grid[next[0]][next[1]] = true;
            snake.push_front(next);
            return foodPos;
        } else {
            isGameOver = true;
            return -1;
        }
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
