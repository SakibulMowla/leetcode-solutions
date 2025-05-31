class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int dir = 0, x = 0, y = 0;
        for (char ch: instructions) {
            if (ch == 'R') {
                dir = (dir + 1) % 4;
            } else if (ch == 'L') {
                dir = (dir + 3) % 4;
            } else {
                x += dx[dir];
                y += dy[dir];
            }
        }

        return (x == 0 && y == 0) || dir != 0;
    }
};
