// problem: https://leetcode.cn/problems/sum-of-unique-elements/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        pmr::unordered_map<int, int> unique;
        for (const auto num: nums) {
            unique[num]++;
        }
        int res = 0;
        for (const auto &[k, v]: unique) {
            if (v == 1) {
                res += k;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sumOfUnique(temp_vector({1, 2, 3, 2})) << endl;
}

//
// Created By ASUS At 2026-04-19 18:26
//
