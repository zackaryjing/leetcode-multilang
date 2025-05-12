// problem: https://leetcode.cn/problems/count-number-of-balanced-permutations/?envType=daily-question&envId=2025-05-09
#include <bitset>
#include <iostream>
#include <functional>
#include <ranges>
#include <memory>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

// #define N 80
#define N 80
#define M 1000000007

class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<int> psum(11);
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
        long long memo[10][target + 1][maxOdd + 1];
        memset(memo, 0xff, sizeof(memo));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
        }

        function<long long(int, int, int)> dfs = [&](int pos, int curr, int oddCnt) -> long long {
            /* 如果剩余位置无法合法填充，或者当前奇数位置元素和大于目标值 */
            if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
                return 0;
            }
            if (pos > 9) {
                return curr == target && oddCnt == 0;
            }
            if (memo[pos][curr][oddCnt] != -1) {
                return memo[pos][curr][oddCnt];
            }
            /* 偶数位剩余需要填充的位数 */
            int evenCnt = psum[pos] - oddCnt;
            long long res = 0;
            for (int i = max(0, cnt[pos] - evenCnt); i <= min(cnt[pos], oddCnt); i++) {
                /* 当前数字在奇数位填充 i 位，偶数位填充 cnt[pos] - i 位 */
                long long ways = comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
                res = (res +  ways * dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) % MOD;
            }
            memo[pos][curr][oddCnt] = res;
            return res;
        };

        return dfs(0, 0, maxOdd);
    }
};


class Solution_2 {
    int factorial_[N + 1];

public:
    Solution_2() {
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
