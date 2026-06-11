// problem:
// https://leetcode.cn/problems/number-of-restricted-paths-from-first-to-last-node/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


class Solution2 {
public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        vector<vector<long long>> graph(n);
        for (const auto edge: edges) {
            graph[edge[0] - 1].push_back((static_cast<long long>(edge[2]) << 32) | (edge[1] - 1));
            graph[edge[1] - 1].push_back((static_cast<long long>(edge[2]) << 32) | (edge[0] - 1));
        }
        // show_matrix(graph);
        vector<long long> dist(n);
        priority_queue<long long, vector<long long>, greater<>> toVis;
        toVis.push(n - 1);
        vector<long long> vis(n);
        const long long mask = (1LL << 32) - 1;
        while (not toVis.empty()) {
            long long cur = toVis.top();
            toVis.pop();
            long long curId = cur & mask;
            if (vis[curId]) continue;
            long long curDist = cur & ~mask;
            dist[curId] = cur >> 32;
            vis[curId] = true;
            for (auto weightChild: graph[curId]) {
                long long child = weightChild & mask;
                if (not vis[child]) {
                    toVis.push(weightChild + curDist);
                }
            }
        }
        // show_vector(dist);
        long long mxDist = dist[0];

        auto seq = views::zip(dist, views::iota(0LL, n)) |
                   views::filter([mxDist](const auto t) { return get<0>(t) < mxDist or get<1>(t) == 0; }) |
                   ranges::to<vector>();
        ranges::sort(seq, greater{});

        int s = seq.size();
        vector<int> dp(s);
        vector<int> prevPos(n, -1);
        prevPos[0] = 0;
        dp[0] = 1;
        const int mod = 1000000007;
        for (int i = 1; i < s; ++i) {
            long long curId = get<1>(seq[i]);
            prevPos[curId] = i;
            for (auto prev: graph[curId]) {
                long long prevId = prev & mask;
                if (dist[prevId] > dist[curId] and dist[prevId] <= mxDist and prevPos[prevId] >= 0) {
                    dp[i] = (dp[i] + dp[prevPos[prevId]]) % mod;
                }
            }
        }
        // show_vector(dp);
        return dp[s - 1];
    }
};

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        vector<vector<long long>> graph(n);
        for (const auto edge: edges) {
            const long long a = edge[0] - 1, b = edge[1] - 1, c = ((long long) edge[2]) << 32;
            graph[b].push_back(c | a), graph[a].push_back(c | b);
        }
        vector<long long> dist(n);
        vector<bool> vis(n);
        priority_queue<long long, vector<long long>, greater<>> toVis;
        toVis.push(n - 1);
        const long long mask = (1LL << 32) - 1;
        while (not toVis.empty()) {
            const long long cur = toVis.top(), curId = cur & mask, curDist = cur & ~mask;
            toVis.pop();
            if (vis[curId]) continue;
            dist[curId] = cur >> 32;
            vis[curId] = true;
            for (const auto weightChild: graph[curId])
                if (not vis[weightChild & mask]) toVis.push(weightChild + curDist);
        }
        long long mxDist = dist[0];
        auto seq = views::iota(0LL, n) | views::transform([&dist](int index) {
                       return pair{
                       dist[index],
                       index,
                       };
                   }) |
                   views::filter([mxDist](const auto &t) { return t.first < mxDist or t.second == 0; }) |
                   ranges::to<vector>();
        ranges::sort(seq, greater{});
        int s = seq.size();
        vector<int> dp(s), prevPos(n, -1);
        prevPos[0] = 0, dp[0] = 1;
        const long long mod = 1000000007;
        for (int i = 1; i < s; ++i) {
            const long long curId = seq[i].second;
            prevPos[curId] = i;
            for (const auto prev: graph[curId])
                if (const long long prevId = prev & mask;
                    dist[prevId] > dist[curId] and dist[prevId] <= mxDist and prevPos[prevId] >= 0)
                    dp[i] = (dp[i] + dp[prevPos[prevId]]) % mod;
        }
        return dp[s - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countRestrictedPaths(
            5,
            temp_vector({temp_vector({1, 2, 3}), temp_vector({1, 3, 3}), temp_vector({2, 3, 1}), temp_vector({1, 4, 2}),
                         temp_vector({5, 2, 2}), temp_vector({3, 5, 1}), temp_vector({5, 4, 10})}))
         << endl;
}

//
// Created By jing At 2026-06-11 21:47
//
