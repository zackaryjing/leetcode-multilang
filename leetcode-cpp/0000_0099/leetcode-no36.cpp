#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int valid[27][9] = {};
//        memset(valid,0,sizeof(int) * 27 * 9);
//        cout << valid[0][8] << " " << valid[3][3] << endl;
//        cout << "there" << endl;
        for (int i = 0;i < 9;i++){
            for (int j = 0;j < 9;j++){
                if (board[i][j] != '.'){
//                    cout << i << " <->==<-> " << j << endl;
//                    cout << board[i][j] << endl;
                    valid[i][board[i][j] - '1'] ++;
                    valid[j+9][board[i][j] - '1'] ++;
                    valid[(i/3) * 3 + j/3 + 18][board[i][j] - '1'] ++;
                }
            }
        }
//        cout << valid[0][0] << "!" << endl;
//        cout << "here" << endl;
        for (int j = 0;j < 27;j++){
            for (int i = 0;i < 9;i++){
//                cout << j << " >- -< " << i << endl;
//                cout << "[" << valid[j][i] << "]" << endl;
                if (valid[j][i] != 0 && valid[j][i] != 1){
//                    cout << "fuck" << endl;
                    return false;
                }
//                cout << "whrer" << endl;
            }
//            cout << "whon" << endl;
        }
//        cout << "a" << endl;
        return true;
    }
};

int main(){
    Solution test;
    vector<vector<char>> board1 = {{'5','3','.','.','7','.','.','.','.'},
    { '6','.','.','1','9','5','.','.','.' }
    ,{ '.','9','8','.','.','.','.','6','.' }
    ,{ '8','.','.','.','6','.','.','.','3' }
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    cout << test.isValidSudoku(board1) << endl;
    return 0;
}
//
// Created by ASUS on 2023/9/5.
//
