// problem:
// https://leetcode.cn/problems/distribute-money-to-maximum-children/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
    // this problem is so weird
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        const int x = (money - children) % 7;
        const int y = (money - children) / 7;
        if (x == 3) {
            if (y == children - 1) return children - 2;
            if (y > children - 1) return children - 1;
            return y;
        }
        return max(y == children ? children - (x != 0) : min(y, children - 1), 0);
    }
};


class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        const int x = (money - children) % 7;
        const int y = (money - children) / 7;
        return x == 3 ? min(y - (y == children - 1), children - 1)
                      : min(children - (x != 0 or y != children), y - (x != 0 and y == children));
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.distMoney(20, 3) << endl;
    cout << test.distMoney(16, 2) << endl;
}

//
// Created By ASUS At 2026-05-29 16:14
//
