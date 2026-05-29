// problem: https://leetcode.cn/problems/build-an-array-with-stack-operations/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 0;
        vector<string> res;
        for (int i = 1;i <= n;++i) {
            if (cur == target.size()) break;
            if (i == target[cur]) {
                res.emplace_back("Push");
                ++cur;
            } else {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-05-29 22:55
//