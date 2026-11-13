// problem: https://leetcode.cn/problems/valid-tic-tac-toe-state/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string> &board) {
        int xcnt = 0, ocnt = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                xcnt += board[i][j] == 'X';
                ocnt += board[i][j] == 'O';
            }
        }
        bool xeverWin = false, oeverWin = false;
        if (not(xcnt == ocnt or xcnt == ocnt + 1)) return false;
        for (int i = 0; i < 3; ++i) {
            bool owin = true, xwin = true;
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'X') xwin = false;
                if (board[i][j] != 'O') owin = false;
            }
            if (owin and xeverWin) return false;
            if (owin) oeverWin = true;
            if (xwin and oeverWin) return false;
            if (xwin) xeverWin = true;
        }
        for (int i = 0; i < 3; ++i) {
            bool owin = true, xwin = true;
            for (int j = 0; j < 3; ++j) {
                if (board[j][i] != 'X') xwin = false;
                if (board[j][i] != 'O') owin = false;
            }
            if (owin and xeverWin) return false;
            if (owin) oeverWin = true;
            if (xwin and oeverWin) return false;
            if (xwin) xeverWin = true;
        }

        bool owin = true, xwin = true;
        for (int j = 0; j < 3; ++j) {
            if (board[j][j] != 'X') xwin = false;
            if (board[j][j] != 'O') owin = false;
        }
        if (owin and xeverWin) return false;
        if (owin) oeverWin = true;
        if (xwin and oeverWin) return false;
        if (xwin) xeverWin = true;
        owin = true, xwin = true;
        for (int j = 0; j < 3; ++j) {
            if (board[j][2 - j] != 'X') xwin = false;
            if (board[j][2 - j] != 'O') owin = false;
        }
        if (owin and xeverWin) return false;
        if (owin) oeverWin = true;
        if (xwin and oeverWin) return false;
        if (xwin) xeverWin = true;
        return (xeverWin and xcnt == ocnt + 1 or oeverWin and xcnt == ocnt or not(oeverWin or xeverWin));
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.validTicTacToe(temp_vector({"XXX", "XOO", "OO "})) << endl;
    cout << test.validTicTacToe(temp_vector({"OXX", "XOX", "OXO"})) << endl;
}


// XXX
// XOO
// OO

// OXX
// XOX
// OXO

// XXO
// XOX
// OXO

//
// Created By jing At 2026-07-01 20:12
//
