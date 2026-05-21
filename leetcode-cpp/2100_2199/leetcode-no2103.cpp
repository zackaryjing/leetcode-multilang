// problem: https://leetcode.cn/problems/rings-and-rods/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<int> colors(10);
        for (int i = 0; i < rings.size(); i += 2) {
            char c = rings[i];
            if (c == 'R') colors[rings[i + 1] - '0'] |= 0b001;
            if (c == 'G') colors[rings[i + 1] - '0'] |= 0b010;
            if (c == 'B') colors[rings[i + 1] - '0'] |= 0b100;
        }
        int res = 0;
        for (int i = 0; i < 10; ++i) res += colors[i] == 7 ? 1 : 0;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countPoints("B0B6G0R6R0R6G9") << endl;
    cout << test.countPoints("B0R0G0R9R0B0G0") << endl;
    cout << test.countPoints("G4") << endl;
}

//
// Created By jing At 2026-05-13 18:46
//
