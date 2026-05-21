// problem: https://leetcode.cn/problems/minimum-moves-to-convert-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size(),res = 0;
        for (int i = 0;i < n;++i) {
            if (s[i] == 'X') {
                res++;
                i += 2;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumMoves("XXX") << endl;
    cout << test.minimumMoves("XX0X") << endl;
    cout << test.minimumMoves("0000") << endl;

}

//
// Created By ASUS At 2026-05-11 06:15
//