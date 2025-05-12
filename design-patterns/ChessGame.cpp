// Question: https://codezym.com/question/8

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

// Forward declaration
class ChessBoard;

// Move interface
class Move {
public:
    virtual bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) = 0;
    virtual ~Move() = default;
};

class Piece {
protected:
    char color, type;
    vector<shared_ptr<Move>> moves;

public:
    Piece(char color, char type) : color(color), type(type) {}
    
    Piece(char color, char type, vector<shared_ptr<Move>> moves) : color(color), type(type), moves(moves) {}
    
    virtual bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) {
        for (auto& m: moves) {
            if (m->canMove(board, startRow, startCol, endRow, endCol)) {
                return true;
            }
        }
        return false;
    }

    char getColor() {
        return color;
    }

    char getType() {
        return type;
    }

    virtual ~Piece() = default;
};

class KingPiece : public Piece {
public:
    KingPiece(char color, char type): Piece(color, type) {}

    bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) override {
        int rowDelta = abs(startRow - endRow);
        int colDelta = abs(startCol - endCol);
        return (rowDelta == 1 && colDelta == 0) || (rowDelta == 0 && colDelta == 1);
    }
};

class KnightPiece : public Piece {
public:
    KnightPiece(char color, char type): Piece(color, type) {}

    bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) override {
        int rowDelta = abs(startRow - endRow);
        int colDelta = abs(startCol - endCol);
        return (rowDelta == 1 && colDelta == 2) || (rowDelta == 2 && colDelta == 1);
    }
};

class PawnPiece : public Piece {
public:
    PawnPiece(char color, char type): Piece(color, type) {}
    bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) override;
};

class DiagonalMove: public Move {
public:
    bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) override;
};

class StraightMove: public Move {
public:
    bool canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) override;
};

class ChessPieceFactory {
private:
    shared_ptr<Move> straightMove = make_shared<StraightMove>();
    shared_ptr<Move> diagonalMove = make_shared<DiagonalMove>();
    static shared_ptr<ChessPieceFactory> instance;

public:
    static shared_ptr<ChessPieceFactory> getInstance() {
        if (instance == nullptr) {
            instance = make_shared<ChessPieceFactory>();
        }
        return instance;
    }

    shared_ptr<Piece> createPiece(char color, char type) {
        switch (type) {
            case 'Q': return make_shared<Piece>(color, type, vector<shared_ptr<Move>>{straightMove, diagonalMove});
            case 'R': return make_shared<Piece>(color, type, vector<shared_ptr<Move>>{straightMove});
            case 'B': return make_shared<Piece>(color, type, vector<shared_ptr<Move>>{diagonalMove});
            case 'K': return make_shared<KingPiece>(color, type);
            case 'H': return make_shared<KnightPiece>(color, type);
            case 'P': return make_shared<PawnPiece>(color, type);
        }

        return nullptr;
    }
};

shared_ptr<ChessPieceFactory> ChessPieceFactory::instance = nullptr;

class ChessBoard {
    vector<vector<shared_ptr<Piece>>> board;
    shared_ptr<ChessPieceFactory> factory = ChessPieceFactory::getInstance();
    int gameState = 0; // 0=in progress, 1=white won, 2=black won
    int nextTurn = 0;  // 0=white, 1=black

public:
    bool isValid(int row, int col) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }

    shared_ptr<Piece> getPiece(int row, int col) {
        if (!isValid(row, col)) {
            return nullptr;
        }
        return board[row][col];
    }

    ChessBoard(vector<vector<string>>& inputBoard) {
        int rows = inputBoard.size();
        int cols = inputBoard[0].size();
        board.resize(rows, vector<shared_ptr<Piece>>(cols, nullptr));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (inputBoard[i][j].size() == 2) {
                    char color = inputBoard[i][j][0];
                    char type = inputBoard[i][j][1];
                    board[i][j] = factory->createPiece(color, type);
                }
            }
        }
    }

    string move(int startRow, int startCol, int endRow, int endCol) {
        if (gameState != 0) {
            return "invalid";
        }
        shared_ptr<Piece> startPiece = getPiece(startRow, startCol);
        shared_ptr<Piece> endPiece = getPiece(endRow, endCol);
        if (!startPiece || !isValid(endRow, endCol)) {
            return "invalid";
        }
        if (endPiece && endPiece->getColor() == startPiece->getColor()) {
            return "invalid";
        }
        if (!startPiece->canMove(*this, startRow, startCol, endRow, endCol)) {
            return "invalid";
        }
        if ((nextTurn == 0 && startPiece->getColor() != 'W') || 
            (nextTurn == 1 && startPiece->getColor() != 'B')) {
            return "invalid";
        }

        board[startRow][startCol] = nullptr;
        board[endRow][endCol] = startPiece;
        if (endPiece && endPiece->getType() == 'K') {
            gameState = endPiece->getColor() == 'B' ? 1 : 2;
        }
        nextTurn = 1 - nextTurn;

        if (endPiece) {
            return string(1, endPiece->getColor()) + endPiece->getType();
        }

        return "";
    }

    int getGameStatus() {
        return gameState;
    }

    int getNextTurn() {
        return gameState != 0 ? -1 : nextTurn;
    }
};

bool PawnPiece::canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) {
    shared_ptr<Piece> pawn = board.getPiece(startRow, startCol);
    shared_ptr<Piece> target = board.getPiece(endRow, endCol);
    if (target) {
        if (abs(startCol - endCol) != 1) {
            return false;
        }
        return (pawn->getColor() == 'W' && (endRow - startRow) == 1) ||
               (pawn->getColor() == 'B' && (endRow - startRow) == -1);
    } else {
        if (startCol != endCol) {
            return false;
        }
        return (pawn->getColor() == 'W' && (endRow - startRow) == 1) ||
               (pawn->getColor() == 'B' && (endRow - startRow) == -1);
    }
}

bool DiagonalMove::canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) {
    int rowDelta = endRow - startRow;
    int colDelta = endCol - startCol;
    if (abs(rowDelta) != abs(colDelta)) {
        return false;
    }

    int rStep = rowDelta < 0 ? -1 : 1;
    int cStep = colDelta < 0 ? -1 : 1;
    startRow += rStep;
    startCol += cStep;

    while (startRow != endRow) {
        if (board.getPiece(startRow, startCol)) {
            return false;
        }
        startRow += rStep;
        startCol += cStep;
    }

    return true;
}

bool StraightMove::canMove(ChessBoard& board, int startRow, int startCol, int endRow, int endCol) {
    if (startRow != endRow && startCol != endCol) {
        return false;
    }

    if (startRow == endRow) {
        int step = endCol > startCol ? 1 : -1;
        for (int col = startCol + step; col != endCol; col += step) {
            if (board.getPiece(startRow, col)) {
                return false;
            }
        }
    } else {
        int step = endRow > startRow ? 1 : -1;
        for (int row = startRow + step; row != endRow; row += step) {
            if (board.getPiece(row, startCol)) {
                return false;
            }
        }
    }

    return true;
}

class Solution {
private:
    shared_ptr<ChessBoard> chessBoard;

public:
    void init(vector<vector<string>> inputBoard) {
        chessBoard = make_shared<ChessBoard>(inputBoard);
    }

    string move(int startRow, int startCol, int endRow, int endCol) {
        return chessBoard->move(startRow, startCol, endRow, endCol);
    }

    int getGameStatus() {
        return chessBoard->getGameStatus();
    }

    int getNextTurn() {
        return chessBoard->getNextTurn();
    }
};

// Uses Factory pattern to create the chess pieces
// Uses singletion for ChessPieceFactory instance (but this isn't explicitly required)

int main() {
    Solution solution;

    // Test cases to validate the solution
    vector<vector<string>> inputBoard = {
        {"WR","WH","WB","WQ","WK","WB","WH","WR"},
        {"WP","WP","WP","WP","WP","WP","WP","WP"},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"BP","BP","BP","BP","BP","BP","BP","BP"},
        {"BR","BH","BB","BQ","BK","BB","BH","BR"},
    };

    solution.init(inputBoard);

    cout << solution.move(1, 5, 2, 5) << endl; // returns '', White Pawn moves from (1, 5) to (2, 5)
    cout << solution.getNextTurn() << endl;  // returns 1
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(6, 6, 5, 6) << endl; // returns '', Black Pawn moves from (6, 6) to (5, 6)
    cout << solution.getNextTurn() << endl; // returns 0
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(2, 5, 3, 5) << endl; // returns '', White Pawn moves from (2, 5) to (3, 5)
    cout << solution.getNextTurn() << endl; // returns 1
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(6, 2, 5, 2) << endl; // returns '', Black Pawn moves from (6, 2) to (5, 2)
    cout << solution.getNextTurn() << endl; // returns 0
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(0, 1, 2, 2) << endl; // returns '', White Knight moves from (0, 1) to (2, 2)
    cout << solution.getNextTurn() << endl; // returns 1
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(6, 4, 5, 4) << endl; // returns '', Black Pawn moves from (6, 4) to (5, 4)
    cout << solution.getNextTurn() << endl; // returns 0
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(1, 7, 2, 7) << endl; // returns '', White Pawn moves from (1, 7) to (2, 7)
    cout << solution.getNextTurn() << endl; // returns 1
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(7, 6, 5, 7) << endl; // returns '', Black Knight moves from (7, 6) to (5, 7)
    cout << solution.getNextTurn() << endl; // returns 0
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(2, 2, 3, 4) << endl; // returns '', White Knight moves from (2, 2) to (3, 4)
    cout << solution.getNextTurn() << endl; // returns 1
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(6, 5, 5, 5) << endl; // returns '', Black Pawn moves from (6, 5) to (5, 5)
    cout << solution.getNextTurn() << endl; // returns 0
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(3, 4, 5, 5) << endl; // returns 'BP', White Knight moves from (3, 4) to (5, 5) and kills (captures) Black Pawn
    cout << solution.getNextTurn() << endl; // returns 1
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(6, 0, 5, 0) << endl; // returns '', Black Pawn moves from (6, 0) to (5, 0)
    cout << solution.getNextTurn() << endl; // returns 0
    cout << solution.getGameStatus() << endl; // returns 0

    cout << solution.move(5, 5, 7, 4) << endl; // returns 'BK', White Knight moves from (5, 5) to (7, 4) and kills (captures) Black King
    cout << solution.getNextTurn() << endl; // returns -1
    cout << solution.getGameStatus() << endl; // returns 1, i.e. player with white pieces has WON.

    return 0;
}
