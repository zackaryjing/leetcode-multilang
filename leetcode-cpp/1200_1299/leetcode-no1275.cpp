#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>> &moves) {
        vector<vector<int>> win = {{0,1,2},
                                   {3,4,5},
                                   {6,7,8},
                                   {0,3,6},
                                   {1,4,7},
                                   {2,5,8},
                                   {0,4,8},
                                   {2,4,6}};
        int n = moves.size();
        int side = 1;
        vector<int> chessboard(9);
        for (auto i : moves){
            if (side) {
                chessboard[i[0]*3 + i[1]] = 1;
                side = 0;
            } else {
                chessboard[i[0]*3 + i[1]] = 2;
                side = 1;
            }
        }
        for (auto types : win){
            if (chessboard[types[0]] == 1 and chessboard[types[1]] == 1 and chessboard[types[2]] == 1){
                return "A";
            } else if (chessboard[types[0]] == 2 and chessboard[types[1]] == 2 and chessboard[types[2]] == 2){
                return "B";
            }
        }
        if (moves.size() == 9){
            return "Draw";
        } else {
            return "Pending";
        }

    }
};

class Solution2 {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> A_moves,B_moves;
        int n = moves.size();
        int side = 1;
        vector<vector<int>> chessboard(3,vector<int>(3));
        for (auto i : moves){
            if (side == 1){
                chessboard[i[0]][i[1]] = 1;
                side = 0;
            } else {
                chessboard[i[0]][i[1]] = 2;
                side = 1;
            }
        }
        bool win;
        for (int target = 1;target < 3;target++){
            for (int k = 0;k < 3;k ++){
                win = true;
                for (int j = 0;j<3;j++){
                    if (chessboard[k][j] != target){
                        win = false;
                        break;
                    }
                }
                if (win){
                    break;
                }
            }
            if (win) {
                if (target == 1) {
                    return "A";
                } else {

                }
            }
        }
    }
};

int main(){

}
//
// Created by ASUS on 2023/7/2.
//
