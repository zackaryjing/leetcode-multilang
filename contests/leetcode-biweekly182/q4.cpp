// problem: https://leetcode.cn/contest/biweekly-contest-182/problems/minimum-threshold-path-with-limited-heavy-edges/
#include <algorithm>
#include <c++/13/unordered_set>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    int minimumThreshold(int n, vector<vector<int>> &edges, int source, int target, int k) {
        int left = 0, right = 0;
        if (source == target) return 0;
        vector<vector<pair<int, int>>> graph(n);
        for (const auto edge: edges) {
            right = max(right, edge[2]);
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        bool anyfound = false;
        while (left < right) {
            int mid = (left + right) / 2;
            queue<int> heavyQueue, lightQueue;
            lightQueue.push(source);
            vector<bool> vis(n);
            vis[source] = true;
            int cost = 0;
            bool found = false;
            while (not lightQueue.empty() || not heavyQueue.empty()) {
                while (not lightQueue.empty()) {
                    int cur = lightQueue.front();
                    if (cur == target) {
                        found = true;
                        break;
                    }
                    lightQueue.pop();
                    for (const auto &[nx, wight]: graph[cur]) {
                        if (vis[nx] == false) {
                            if (wight > mid) {
                                heavyQueue.push(nx);
                            } else {
                                lightQueue.push(nx);
                                vis[nx] = true;
                            }
                        }
                    }
                }
                if (found)
                    break;
                int hn = heavyQueue.size();
                if (hn > 0) {
                    cost++;
                    for (int i = 0; i < hn; ++i) {
                        int cur = heavyQueue.front();
                        if (cur == target) {
                            found = true;
                            break;
                        }
                        heavyQueue.pop();
                        for (const auto &[nx, wight]: graph[cur]) {
                            if (vis[nx] == false) {
                                vis[nx] = true;
                                if (wight > mid) {
                                    heavyQueue.push(nx);
                                } else {
                                    lightQueue.push(nx);
                                }
                            }
                        }
                    }
                    if (found)
                        break;
                }
            }
            if (found)
                anyfound = true;
            if (found and cost <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return anyfound ? left : -1;
    }
};

int main(int argc, char *argv[]) { Solution test; }

//
// Created By jing At 2026-05-09 23:25
//
