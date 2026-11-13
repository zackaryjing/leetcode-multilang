// problem:
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    long long finishTime(int n, vector<vector<int>> &edges, vector<int> &baseTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            const auto &edge = edges[i];
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return [&](this auto &&dfs, int cur, int from) -> long long {
            long long mx = 0, mn = LONG_LONG_MAX;
            int childCnt = 0;
            for (auto child: graph[cur]) {
                if (child != from) {
                    childCnt++;
                    long long time = dfs(child, cur);
                    mx = max(time, mx);
                    mn = min(time, mn);
                }
            }
            if (childCnt == 0)
                return baseTime[cur];
            return mx - mn + baseTime[cur] + mx;
        }(0, -1);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.finishTime(3, temp_vector({temp_vector({0, 1}), temp_vector({1, 2})}), temp_vector({9, 5, 3})) << endl;
    cout << test.finishTime(3, temp_vector({temp_vector({0, 1}), temp_vector({0, 2})}), temp_vector({4, 7, 6})) << endl;
    cout << test.finishTime(4, temp_vector({temp_vector({0, 1}), temp_vector({0, 2}), temp_vector({2, 3})}),
                            temp_vector({5, 8, 2, 1}))
         << endl;
}

//
// Created By ASUS At 2026-06-20 22:55
//
