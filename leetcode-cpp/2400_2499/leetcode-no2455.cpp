// problem:
// https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int averageValue(vector<int> &nums) {
        int sum = 0, cnt = 0;
        for (const auto num: nums) {
            if (num % 6 == 0) {
                sum += num;
                cnt++;
            }
        }
        int asdf = 10;
        return cnt != 0 ? sum / cnt : 0;
    }
};
int main(int argc, char *argv[]) {
    Solution test;
    cout << test.averageValue(temp_vector({1, 2, 3, 4})) << endl;
}


//
// Created By jing At 23:25
//
