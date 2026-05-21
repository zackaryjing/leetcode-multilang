// problem:
// https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int n = s.size(),res = 0;;
        char cin = '0';
        for (int i = n - 1; i >= 0; --i) {
            char cur = s[i];
            if (cur == '0' and cin == '0')
                res += 1, cin = '0';
            else if (cur == '1' and cin == '1')
                res += 1, cin = '1';
            else if (i != 0)
                res += 2, cin = '1';
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numSteps("111") << " e4" << endl;
    cout << test.numSteps("1101") << " e6" << endl;
    cout << test.numSteps("10") << " e1" << endl;
    cout << test.numSteps("1") << " e0" << endl;
}

//
// Created By jing At 2026-05-18 16:31
//
