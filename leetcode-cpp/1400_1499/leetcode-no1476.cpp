// problem:  https://leetcode.cn/problems/subrectangle-queries/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>> rect;
    vector<pair<pair<int, int>, pair<int, int>>> op;
    vector<int> val;
    SubrectangleQueries(vector<vector<int>> &rectangle) {
        rect = rectangle;
    }
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        op.emplace_back(pair{row1, col1}, pair{row2, col2});
        val.push_back(newValue);
    }
    int getValue(int row, int col) {
        int n = op.size();
        for (int i = n - 1; i >= 0; --i) {
            int a = op[i].first.first, b = op[i].first.second, c = op[i].second.first, d = op[i].second.second;
            if (a <= row and b <= col and row <= c and col <= d) {
                return val[i];
            }
        }
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

int main(int argc, char *argv[]) {

}

//
// Created By jing At 2026-06-02 15:35
//
