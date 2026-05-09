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
    int minimumThreshold(int n, vector<vector<int>> &edges, int source, int target, int k) {
        int left = 0, right = 0;
        if (source == target)
            return 0;
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
            unordered_set<int> heavyQueueTemp;
            while (not lightQueue.empty() || not heavyQueue.empty() || not heavyQueueTemp.empty()) {
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
                                heavyQueueTemp.insert(nx);
                            } else {
                                lightQueue.push(nx);
                                vis[nx] = true;
                            }
                        }
                    }
                }
                if (found)
                    break;
                for (const auto hv: heavyQueueTemp) {
                    if (not vis[hv]) {
                        vis[hv] = true;
                        heavyQueue.push(hv);
                    }
                }
                int hn = heavyQueue.size();
                heavyQueueTemp.clear();
                if (hn > 0) {
                    cost++;
                    for (int i = 0; i < hn; ++i) {
                        int cur = heavyQueue.front();
                        if他 (cur == target) {
                            found = true;
                            break;
                        }
                        heavyQueue.pop();
                        for (const auto &[nx, wight]: graph[cur]) {
                            if (vis[nx] == false) {
                                if (wight > mid) {
                                    heavyQueueTemp.insert(nx);
                                } else {
                                    lightQueue.push(nx);
                                    vis[nx] = true;
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

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumThreshold(3,temp_vector({temp_vector({0,1,79}),temp_vector({0,2,63})}),2,2,1) << endl;
}

//
// Created By jing At 2026-05-09 23:25
//
