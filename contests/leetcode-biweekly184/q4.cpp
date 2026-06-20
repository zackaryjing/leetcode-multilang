// problem: https://leetcode.cn/contest/biweekly-contest-184/problems/maximum-score-with-co-prime-element/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxScore(vector<int> &nums, int maxVal) {
        const auto gcd = [](int a, int b) {
            while (b != 0) {
                int oldb = b;
                b = a % b;
                a = oldb;
            }
            return a;
        };
        int n = nums.size();
        int res = 0;
        if (n == 1)
            return max(nums[0], maxVal - 1);
        for (int i = maxVal; i >= 1; --i) {
            int cnts = 0;
            bool hasSame = false;
            for (int j = 0; j < n; ++j) {
                if (i == nums[j]) {
                    hasSame = true;
                }
                if (gcd(i, nums[j]) > 1) {
                    cnts++;
                }
            }
            // cout << "i: " << i << endl;
            // cout << "cnts: " << cnts << endl;
            // res = max(res, hasSame ? i - cnts + 1 : (cnts >= 1 ? i - cnts : i - cnts - 1));
            res = max(res, hasSame ? i - cnts + 1 : i - max(cnts, 1));
            // res = max(res, i - cnts - 1);
        }
        // cout << "res : " << res << endl;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > maxVal) {
                int temp = nums[i];
                int cnts = 0;
                bool hasSame = false;
                for (int j = 0; j < n; ++j) {
                    if (temp == nums[j]) {
                        hasSame = true;
                    }
                    if (gcd(temp, nums[j]) > 1) {
                        cnts++;
                    }
                }
                // cout << "hasSame: " << hasSame << endl;
                res = max(res, hasSame ? temp - cnts + 1 : temp - cnts);
            }
        }
        return res;
    } // 976
};


class Solution3 {
public: // 980
    // Seems to be correct but [TLE]
    int maxScore(vector<int> &nums, int maxVal) {
        unordered_map<long long, bool> cache;
        const auto gcd = [](int a, int b) -> bool {
            while (b != 0) {
                int oldb = b;
                b = a % b;
                a = oldb;
            }
            return a > 1;
        };
        int n = nums.size();
        int res = 0;
        ranges::sort(nums);
        ranges::reverse(nums);
        if (n == 1)
            return max(nums[0], maxVal - 1);
        for (int i = maxVal; i >= 1; --i) {
            int cnts = 0;
            bool hasSame = false;
            if (i <= res)
                break;
            for (int j = 0; j < n; ++j) {
                if (i == nums[j])
                    hasSame = true;
                if (gcd(i, nums[j]))
                    cnts++;
            }
            res = max(res, hasSame ? i - cnts + 1 : i - max(cnts, 1));
        }
        for (int i = 0; i < n; ++i) {
            const int temp = nums[i];
            if (temp > maxVal and temp > res) {
                int cnts = 0;
                for (int j = 0; j < n; ++j) {
                    if (gcd(temp, nums[j]))
                        cnts++;
                }
                res = max(res, temp - cnts + 1);
            } else {
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxScore(vector<int> &nums, int maxVal) {
        auto meratolvic = make_pair(nums, maxVal);

        int n = nums.size();
        int res = 0;

        ranges::sort(nums);
        ranges::reverse(nums);

        if (n == 1)
            return max(nums[0], maxVal - 1);

        unordered_set occurs(nums.begin(), nums.end());
        BadCounter counter(nums, maxVal);

        for (int i = maxVal; i >= 1; --i) {

            if (i <= res)
                break;

            bool hasSame = occurs.contains(i);

            int cnts = counter.badCount(i);

            if (i == 1) {
                res = max(res, hasSame ? 1 : 0);
            } else {
                res = max(res, hasSame ? i - cnts + 1 : i - max(cnts, 1));
            }
        }

        for (int i = 0; i < n; ++i) {
            const int temp = nums[i];
            if (temp > maxVal and temp > res) {
                int cnts = counter.badCount(temp);
                res = max(res, temp - cnts + 1);
            } else {
                break;
            }
        }

        return res;
    }

private:
    class BadCounter {
        int maxNum;
        vector<int> divCnt;
        vector<int> spf;

    public:
        BadCounter(const vector<int>& nums, int maxVal) {
            maxNum = maxVal;
            for (int x : nums) maxNum = max(maxNum, x);

            vector<int> freq(maxNum + 1);
            for (int x : nums) freq[x]++;

            divCnt.assign(maxNum + 1, 0);

            for (int d = 1; d <= maxNum; ++d) {
                for (int m = d; m <= maxNum; m += d) {
                    divCnt[d] += freq[m];
                }
            }

            spf.assign(maxNum + 1, 0);

            for (int i = 2; i <= maxNum; ++i) {
                if (spf[i] == 0) {
                    for (int j = i; j <= maxNum; j += i) {
                        if (spf[j] == 0) spf[j] = i;
                    }
                }
            }
        }

        vector<int> primeFactors(int x) const {
            vector<int> ps;

            while (x > 1) {
                int p = spf[x];
                ps.push_back(p);
                while (x % p == 0) x /= p;
            }

            return ps;
        }

        int badCount(int x) const {
            if (x == 1) return 0;

            auto ps = primeFactors(x);
            int k = ps.size();
            int res = 0;

            for (int mask = 1; mask < (1 << k); ++mask) {
                int prod = 1;
                int bits = 0;

                for (int i = 0; i < k; ++i) {
                    if (mask >> i & 1) {
                        prod *= ps[i];
                        bits++;
                    }
                }

                if (bits & 1) {
                    res += divCnt[prod];
                } else {
                    res -= divCnt[prod];
                }
            }

            return res;
        }
    };
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxScore(temp_vector({3, 4, 6}), 5) << " e 4" << endl;
    cout << test.maxScore(temp_vector({1, 2, 3}), 4) << " e 3" << endl;
    cout << test.maxScore(temp_vector({2, 2}), 1) << " e 1" << endl;
    cout << test.maxScore(temp_vector({3, 4, 6}), 5) << " e 4" << endl;
    cout << test.maxScore(temp_vector({1, 2, 3}), 4) << " e 3" << endl;
    cout << test.maxScore(temp_vector({458, 915}), 709) << " e 915" << endl;
    cout << test.maxScore(temp_vector({42}), 312) << " e 311" << endl;
    cout << test.maxScore(temp_vector({943, 56, 478, 754, 535, 283, 869, 539, 447}), 943) << " e 943" << endl;
    cout << test.maxScore(temp_vector({216, 243}), 386) << " e 385" << endl;
    cout << test.maxScore(temp_vector({160, 438, 177}), 477) << " e 475" << endl;
}

//
// Created By jing At 2026-06-06 23:16
//
