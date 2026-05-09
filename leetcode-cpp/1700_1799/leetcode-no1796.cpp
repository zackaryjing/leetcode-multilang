// problem: https://leetcode.cn/problems/second-largest-digit-in-a-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int mx = -1;
        int mn = -1;
        for (char c: s) {
            if (std::isdigit(c)) {
                int num = c - '0';
                if (num > mx) {
                    mn = mx;
                    mx = num;
                } else if (num > mn and num != mx) {
                    mn = num;
                }
            }
        }
        return mn;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.secondHighest("dfa12321afd") << endl;
    cout << test.secondHighest("abc1111") << endl;
}

//
// Created By ASUS At 2026-05-09 19:26
//
