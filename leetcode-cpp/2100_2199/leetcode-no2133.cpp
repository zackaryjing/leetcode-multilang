// problem:
// https://leetcode.cn/problems/check-if-every-row-and-column-contains-all-numbers/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> occurs;
            for (int j = 0; j < n; ++j) {
                auto num = matrix[i][j];
                if (1 <= num and num <= n) {
                    occurs.insert(num);
                }
            }
            if (occurs.size() != n) {
                return false;
            }
        }
        for (int j = 0; j < n; ++j) {
            unordered_set<int> occurs;
            for (int i = 0; i < n; ++i) {
                auto num = matrix[i][j];
                if (1 <= num and num <= n) {
                    occurs.insert(num);
                }
            }
            if (occurs.size() != n) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<int> occurs1(n), occurs2(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (int num1 = matrix[i][j], num2 = matrix[j][i]; 1 > num1 || num1 > n || ++occurs1[num1 - 1] != i + 1 || 1 > num2 || num2 > n || ++occurs2[num2 - 1] != i + 1)
                    return false;
        return true;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.checkValid(temp_vector({temp_vector({1, 2, 3}), temp_vector({3, 1, 2}), temp_vector({2, 3, 1})}))
         << endl;
    cout << test.checkValid(
            temp_vector(temp_vector({temp_vector({1, 1, 1}), temp_vector({1, 2, 3}), temp_vector({1, 2, 3})})))
         << endl;
}

//
// Created By ASUS At 2026-05-08 21:45
//
