// problem: https://leetcode.cn/problems/valid-binary-strings-with-cost-limit/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        for (int i = 0; i < (1 << n); ++i) {
            int cost = 0;
            int num = i;
            bool lastIsOne = false;
            bool valid = true;
            for (int j = 0; num > 0; num >>= 1, ++j) {
                if (num & 1) {
                    if (lastIsOne) {
                        valid = false;
                        break;
                    }
                    lastIsOne = true;
                } else {
                    lastIsOne = false;
                }
                cost += num & 1 ? (n - 1 - j) : 0;
            }
            if (valid and cost <= k) {
                res.push_back(vformat("{:0{}b}", make_format_args(i, n)));
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.generateValidStrings(3, 1));
    show_vector(test.generateValidStrings(1,0));
}

//
// Created By ASUS At 2026-06-07 10:36
//
