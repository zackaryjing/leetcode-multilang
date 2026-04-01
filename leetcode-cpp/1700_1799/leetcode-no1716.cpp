// problem: https://leetcode.cn/problems/calculate-money-in-leetcode-bank/submissions/713843141/
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


#include <iostream>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
    int weekcnt = n / 7;
        int m = n % 7;
        int day1 = weekcnt * (weekcnt - 1) / 2 * 7;
        int day2 = weekcnt * 28 + (1 + m) * m / 2 + m * weekcnt;
        return day1 + day2;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-04-01 23:49
//