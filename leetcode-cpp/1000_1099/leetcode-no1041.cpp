#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int direction = 0;
        vector<int> pos = {0,0},start = {0,0},origindir = {0,1};
        for (auto each: instructions){
            if (each == 'L') {
                direction = (direction + 3) % 4;
            } else if (each == 'R') {
                direction = (direction + 1) % 4;
            } else {
                pos[0] += directions[direction][0];
                pos[1] += directions[direction][1];
            }
        }
        if (pos == start){
            return true;
        } else {
            if (direction != 0){
                return true;
            } else {
                return false;
            }
        }
    }
};

int main(){
    Solution test;
    cout << test.isRobotBounded("GGLLGG") << endl;
    cout << test.isRobotBounded("GG") << endl;
    cout << test.isRobotBounded("GL") << endl;
}

//
// Created by ASUS on 2023/7/10.
//
