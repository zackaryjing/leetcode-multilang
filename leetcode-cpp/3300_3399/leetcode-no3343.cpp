// problem: https://leetcode.cn/problems/count-number-of-balanced-permutations/?envType=daily-question&envId=2025-05-09
#include <bitset>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

// #define N 80
#define N 80
#define M 1000000007

class Solution {
    int factorial_[N + 1];

public:
    Solution() {
        factorial_[0] = 1;
        long long res = 1;
        for (int i = 1; i <= N; i++) {
            res = res * i % M;
            factorial_[i] = static_cast<int>(res);
        }
    }

    int countBalancedPermutations(string num) {
        int n = num.size();
        vector<vector<bitset<N> > > reach(321);
        int cur_sum = 0;
        reach[0] = {0};
        for (int i = 0; i < n; ++i) {
            int m = num[i] - '0';
            cur_sum += m;
            for (int j = cur_sum; j >= m; j--) {
                for (auto temp: reach[j - m]) {
                    reach[j].push_back(temp.set(i));
                }
            }
        }

        // show_matrix(reach);
        vector<bitset<N> > &ways = reach[cur_sum / 2];
        // show_vector(ways);
        cout << cur_sum << endl;
        bool even = n % 2 == 0;
        int res = 0;

        int g_cnts[10] = {0};
        for (int i = 0; i < n; ++i) {
            g_cnts[num[i] - '0']++;
        }
        // show_vector(ways);
        // cout << "len: " << ways.size() << endl;
        // cout << "g_cnts" << endl;
        for (auto &way: ways) {
            cout << way << endl;
            int cnts[10] = {0};
            int cnt = 0;
            for (int i = 0; i < N; ++i) {
                if (way[i]) {
                    cnts[num[i] - '0']++;
                    cnt++;
                }
            }
            // cout << "cnt: " << cnt << endl;
            if (cnt == n / 2) {
                long long temp = factorial_[n / 2] * factorial_[n - n / 2];
                bool same = true;
                for (auto [c,gc]: views::zip(cnts, g_cnts)) {
                    // cout << c << " " << gc << endl;
                    temp /= factorial_[c];
                    temp /= factorial_[gc - c];
                    same &= c == gc;
                }
                // cout << temp << endl;
                res += static_cast<int>(same or not even ? temp : temp * 2) % M;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countBalancedPermutations("123") << endl;;
    cout << endl;
    cout << test.countBalancedPermutations("112") << endl;;
}

//
// Created By Zackary At 2025-05-09 22:37:20
//
