// problem: https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-ii/?envType=daily-question&envId=2025-06-11
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int inf = INT_MAX / 2;
        int ans = -inf;
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (y == x)
                    continue;
                int pre[5]{}, cur[5]{};
                int min_pre[2][2] = {{inf, inf}, {inf, inf}};
                int left = 0;
                for (int i = 0; i < n; i++) {
                    cur[s[i] - '0']++;
                    int r = i + 1;
                    while (r - left >= k and cur[x] > pre[x] and cur[y] > pre[y]) {
                        int &p = min_pre[pre[x] & 1][pre[y] & 1];
                        p = min(p, pre[x] - pre[y]);
                        pre[s[left] - '0']++;
                        left++;
                    }
                    ans = max(ans, cur[x] - cur[y] - min_pre[cur[x] & 1 ^ 1][cur[y] & 1]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDifference("12233", 4) << " -1" << endl;
    cout << test.maxDifference("1122211", 3) << " 1" << endl;
    cout << test.maxDifference("110", 3) << " -1" << endl;
}

//
// Created By Zackary At 2025-06-11 12:50:52
//
