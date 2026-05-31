// problem:
// https://leetcode.cn/problems/minimum-time-to-collect-all-apples-in-a-tree/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
        vector<vector<int>> graph(n);
        for (const auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        const auto v = [&](this auto &&dfs, int rt, int from) -> bool {
            bool valid = hasApple[rt];
            for (auto child: graph[rt])
                if (child != from) valid |= dfs(child, rt);
            if (valid) res += 1;
            return valid;
        }(0, -1);
        res -= v;
        return res * 2;
    }
};


class Solution {
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
        vector<int> head(2 * n + 1), to(2 * n + 1), nxt(2 * n + 1);
        int cnt = 1;
        const auto addEdge = [&](int a, int b) {
            nxt[cnt] = head[a];
            to[cnt] = b;
            head[a] = cnt++;
        };
        for (const auto &edge: edges) {
            addEdge(edge[0], edge[1]);
            addEdge(edge[1], edge[0]);
        }
        int res = 0;
        const auto v = [&](this auto &&dfs, int rt, int from) -> bool {
            bool valid = hasApple[rt];
            for (int c = head[rt]; c > 0; c = nxt[c]) {
                int child = to[c];
                if (child != from) valid |= dfs(child, rt);
            }
            if (valid) res += 1;
            return valid;
        }(0, -1);
        res -= v;
        return res * 2;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minTime(7,
                         temp_vector({temp_vector({0, 1}), temp_vector({0, 2}), temp_vector({1, 4}),
                                      temp_vector({1, 5}), temp_vector({2, 3}), temp_vector({2, 6})}),
                         temp_vector({false, false, true, false, true, true, false}))
         << endl;
}

//
// Created By jing At 2026-05-29 21:33
//
