#include<string>
#include<unordered_set>
#include<vector>
#include<iostream>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<std::string> s; // return pair<identifier,boolean>, stores
                             // unique identifiers with boolean value
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char val = board[i][j];
            if (val != '.') {
                // make identifier using (string("r") + to_string(i) + val)
                // , it creates identifier as r05 , means row 0 have value
                // 5, if identifier is repeated in set means duplicate value
                // exists
                if (
                    // use .second to use the boolean value
                    // we just need to find for particular box and not every
                    // index of box, so for i =5 ,j=2 , we i/3 , j/3 means
                    // b105 means boxRow = 1 and boxCol= 0, if we need
                    // tofind boxNum that would be i/3 * 3 + j/3 , for this
                    // example it would be box 3
                    (!s.insert(std::string("r") + std::to_string(i) + val).second) ||
                    (!s.insert(std::string("c") + std::to_string(j) + val).second) ||
                    (!s.insert(std::string("b") + std::to_string(i / 3) + std::to_string(j / 3) + val) .second)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {

    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'5','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board))
       std:: cout << "Sudoku is VALID ✅" <<std:: endl;
    else
        std::cout << "Sudoku is INVALID ❌" << std::endl;

    return 0;
}