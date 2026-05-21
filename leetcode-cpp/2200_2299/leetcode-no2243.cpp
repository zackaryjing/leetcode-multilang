// problem: https://leetcode.cn/problems/calculate-digit-sum-of-a-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int n = s.size();
            string ns;
            ns.reserve(n);
            for (int i = 0; i < n; i += k) {
                int temp = 0;
                for (int j = i; j < min(n, i + k); ++j) {
                    temp += s[j] - '0';
                }
                ns.append(std::to_string(temp));
            }
            s = ns;
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.digitSum("11111222223", 3) << endl;
}

//
// Created By jing At 2026-05-15 18:09
//
