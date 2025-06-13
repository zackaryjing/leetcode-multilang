// problem:
#include <iostream>
#include <vector>
#include <cmath>
#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
        long long baseDigit = (intLength + 1) / 2;
        long long base = pow(10, baseDigit - 1);
        long long maxHalf = pow(10, baseDigit) - 1;
        bool isOdd = intLength & 1;
        auto reverse = [&](long long num) {
            long long ans = pow(10, intLength / 2) * num;
            if (isOdd) {
                num /= 10;
            }
            long long right = 0;
            while (num > 0) {
                right *= 10;
                right += num % 10;
                num /= 10;
            }
            return ans + right;
        };
        vector<long long> res;
        int n = queries.size();
        res.reserve(n);
        for (auto query: queries) {
            query -= 1;
            query += base;
            if (query > maxHalf) {
                res.push_back(-1);
            } else {
                res.push_back(reverse(query));
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.kthPalindrome(temp_vector({1, 2, 3, 4, 5, 90}), 3));
    show_vector(test.kthPalindrome(temp_vector({2, 4, 6}), 4));
}

//
// Created By Zackary At 2025-06-12 20:43:39
//
