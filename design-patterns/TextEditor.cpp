// Question: https://codezym.com/question/9

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class CharFlyWeight {
    char ch;
    string fontName;
    int fontSize;
    bool isBold;
    bool isItalic;

public:
    CharFlyWeight() : ch('\0'), fontName(""), fontSize(0), isBold(false), isItalic(false) {}
    
    CharFlyWeight(char ch, string& fontName, int fontSize, bool isBold, bool isItalic): 
                  ch(ch), fontName(fontName), fontSize(fontSize), isBold(isBold), isItalic(isItalic) {}

    string getStyle() {
        return string(1, ch) + "-" + fontName + "-" + to_string(fontSize) + 
               (isBold ? "-b" : "") + (isItalic ? "-i" : "");
    }

    char getChar() {
        return ch;
    }
};

class CharFlyWeightFactory {
    map<string, shared_ptr<CharFlyWeight>> styles;

public:
    shared_ptr<CharFlyWeight> createStyle(char ch, string& fontName, int fontSize, bool isBold, bool isItalic) {
        CharFlyWeight chStyle = CharFlyWeight(ch, fontName, fontSize, isBold, isItalic);
        string key = chStyle.getStyle();

        if (styles.find(key) == styles.end()) {
            styles[key] = make_shared<CharFlyWeight>(chStyle);
        }

        return styles[key];
    }
};

class TextRow {
    vector<shared_ptr<CharFlyWeight>> data;

public:
    void addCharacter(int column, shared_ptr<CharFlyWeight> chStyle) {
        if (column >= data.size()) {
            data.push_back(chStyle);
        } else {
            data.insert(data.begin() + column, chStyle);
        }
        return;
    }

    shared_ptr<CharFlyWeight> getCharacter(int column) {
        if (column < 0 || column >= data.size()) {
            return nullptr;
        }

        return data[column];
    }

    string readLine() {
        string line = "";
        for (int i = 0; i < data.size(); i++) {
            line += data[i]->getChar();
        }
        return line;
    }

    bool deleteCharacter(int column) {
        if (column >= data.size()) {
            return false;
        }

        data.erase(data.begin() + column);

        return true;
    }
};

class Solution {
private:
    unordered_map<int, TextRow> rows;
    CharFlyWeightFactory charFlyWeightFactory;

public:
    void addCharacter(int row, int column, char ch,
                      string fontName, int fontSize, bool isBold, bool isItalic) {
        
        if (rows.find(row) == rows.end()) {
            rows[row] = TextRow();
        }

        shared_ptr<CharFlyWeight> chStyle = 
            charFlyWeightFactory.createStyle(ch, fontName, fontSize, isBold, isItalic);

        rows[row].addCharacter(column, chStyle);

        return;
    }

    string getStyle(int row, int column) {
        if (rows.find(row) == rows.end()) {
            return "";
        }

        auto chStyle = rows[row].getCharacter(column);

        if (chStyle == nullptr) {
            return "";
        }

        return chStyle->getStyle();
    }

    string readLine(int row) {
        if (rows.find(row) == rows.end()) {
            return "";
        }

        return rows[row].readLine();
    }

    bool deleteCharacter(int row, int column) {
        if (rows.find(row) == rows.end()) {
            return false;
        }

        return rows[row].deleteCharacter(column);
    }
};

void runTests() {
    Solution solution;

    // Test 1: Add and retrieve style
    solution.addCharacter(0, 0, 'a', "Arial", 12, false, false);
    string style = solution.getStyle(0, 0);
    assert(style == "a-Arial-12");

    // Test 2: ReadLine for single char
    assert(solution.readLine(0) == "a");

    // Test 3: Add another character in same row
    solution.addCharacter(0, 1, 'b', "Arial", 12, false, false);
    assert(solution.readLine(0) == "ab");

    // Test 4: Insert character at beginning
    solution.addCharacter(0, 0, 'z', "Arial", 12, false, false);
    assert(solution.readLine(0) == "zab");

    // Test 5: Delete middle character
    assert(solution.deleteCharacter(0, 1) == true);
    assert(solution.readLine(0) == "zb");

    // Test 6: Delete out-of-bound
    assert(solution.deleteCharacter(0, 100) == false);

    // Test 7: Read empty line
    assert(solution.readLine(10) == "");

    // Test 8: Add multiple rows and read separately
    solution.addCharacter(1, 0, 'x', "Times", 10, true, false);
    solution.addCharacter(2, 0, 'y', "Courier", 11, false, true);
    assert(solution.readLine(1) == "x");
    assert(solution.readLine(2) == "y");

    // Test 9: Add multiple characters with different styles
    solution.addCharacter(2, 1, 'z', "Courier", 11, false, false);
    assert(solution.readLine(2) == "yz");
    assert(solution.getStyle(2, 0) != solution.getStyle(2, 1));

    cout << "✅ All tests passed!" << endl;
}

int main() {
    Solution solution;

    // Test cases to validate the solution
    solution.addCharacter(0, 0, 'g', "Cambria", 17, true, true);
    solution.addCharacter(1, 0, 'y', "Century Gothic", 14, true, true);
    solution.addCharacter(1, 1, 'h', "Courier New", 22, false, false);
    solution.addCharacter(1, 2, 'y', "Georgia", 14, false, false);


    cout << solution.getStyle(0,0) << endl; // returns 'g-Cambria-17-b-i'
    cout << solution.readLine(0) << endl; // returns 'g'
    solution.addCharacter(0, 0, 'q', "Arial", 21, false, true);
    cout << solution.readLine(0) << endl; // returns 'qg'

    cout << solution.readLine(1) << endl; // returns 'yhy'
    cout << solution.deleteCharacter(1, 1) << endl; // returns true
    cout << solution.readLine(1) << endl; // returns 'yy'
    cout << solution.deleteCharacter(1, 4) << endl; // returns false

    runTests();

    return 0;
}
