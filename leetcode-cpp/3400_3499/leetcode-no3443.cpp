// problem: https://leetcode.cn/problems/maximum-manhattan-distance-after-k-changes/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int res = 0;
        int N = 0, S = 0, E = 0, W = 0;
        for (const auto ch: s) {
            switch (ch) {
                case 'N':
                    N++;
                    break;
                case 'S':
                    S++;
                    break;
                case 'E':
                    E++;
                    break;
                case 'W':
                    W++;
                    break;
                default:
                    break;
            }
            res = max(res, abs(N - S) + abs(E - W) + 2 * min(k, min(N, S) + min(E, W)));

        }
        return res;
    }
};


class Solution2 {
public:
    int maxDistance(string s, int k) {
        vector<int> cnt(4);
        int res = 0;
        for (const auto ch: s) {
            switch (ch) {
                case 'N':
                    cnt[0]++;
                    break;
                case 'S':
                    cnt[1]++;
                    break;
                case 'E':
                    cnt[2]++;
                    break;
                case 'W':
                    cnt[3]++;
                    break;
                default:
                    break;
            }
            res = max({res, cnt[0] + cnt[2] + min(k, cnt[1] + cnt[3]) - max(cnt[1] + cnt[3] - k, 0),
                       cnt[0] + cnt[3] + min(k, cnt[1] + cnt[2]) - max(cnt[1] + cnt[2] - k, 0),
                       cnt[1] + cnt[2] + min(k, cnt[0] + cnt[3]) - max(cnt[0] + cnt[3] - k, 0),
                       cnt[1] + cnt[3] + min(k, cnt[0] + cnt[2]) - max(cnt[0] + cnt[2] - k, 0)
            });
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDistance("NWSE", 1) << endl;
    cout << test.maxDistance("NSWWEW", 3) << endl;
}

//
// Created By Zackary At 2025-05-30 17:35:56
//
