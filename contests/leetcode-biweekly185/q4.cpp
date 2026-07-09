// problem:
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
    // TLE
public:
    long long goodIntegers(long long l, long long r, int k) {
        vector<long long> llimit;
        long long cl = l, index = 0, offset = 1, cr = r;
        while (cl > 0 or cr > 0) {
            llimit.push_back(cl * offset);
            cl /= 10;
            cr /= 10;
            offset *= 10;
            ++index;
        }
        ranges::reverse(llimit);
        // show_vector(llimit);
        long long res = 0;
        const auto dfs = [&](this auto &&dfs, long long cur, int lastDigit, long long coffset, int pos,
                             bool started) -> void {
            int lo = 0, hi = 9;
            if (started) {
                lo = max(0, lastDigit - k);
                hi = min(9, lastDigit + k);
            }
            for (int i = lo; i <= hi; ++i) {
                long long ncur = cur + i * coffset;
                if (ncur >= llimit[pos] and ncur <= r) {
                    if (pos == index - 1) {
                        res++;
                    } else {
                        dfs(ncur, i, coffset / 10, pos + 1, started || i != 0);
                    }
                }
            }
        };
        offset /= 10;
        for (int i = 0; i <= 9; ++i) {
            long long candidate = i * offset;
            if (candidate >= llimit[0] and candidate <= r) {
                if (index == 1) {
                    res++;
                } else {
                    dfs(candidate, i, offset / 10, 1, i != 0);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // cout << test.goodIntegers(357283475, 15, 1) << endl;
    cout << test.goodIntegers(10, 15, 1) << endl;
    cout << test.goodIntegers(201, 204, 2) << endl;
}

//
// Created By ASUS At 2026-06-20 23:15
//
