// problem: https://leetcode.cn/problems/maximize-alternating-sum-using-swaps/description/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps) {
        int n = nums.size();

        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto edge: swaps) {
            int u = edge[0], v = edge[1];
            unionSets(u, v);
        }
        for (int i = 0; i < n; ++i) {
            parent[i] = find(parent[i]);
        }

        pmr::unordered_map<int, vector<long long>> groups;
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += nums[i];
            groups[parent[i]].push_back(i);
        }
        long long even_total = 0;
        for (auto &[_, group]: groups) {

            // cout << _ << ": ";
            // for (auto k: group) {
            //     cout << k << " ";
            // }
            // cout << endl;
            auto m = group.size();
            vector<long long> elements;
            elements.reserve(m);
            auto even_cnt = 0;
            for (auto pos: group) {
                if (pos % 2 == 0) {
                    even_cnt++;
                }
                elements.push_back(nums[pos]);
            }
            ranges::sort(elements);
            for (auto i = 0; i < even_cnt; ++i) {
                even_total += elements[m - i - 1];
            }
        }
        return 2 * even_total - total;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxAlternatingSum(temp_vector({1, 2, 3}), temp_vector({{0, 2}, {1, 2}})) << endl;
    cout << test.maxAlternatingSum(temp_vector({1, 1, 1, 2}), temp_vector({{0, 2}, {1, 3}, {2, 3}})) << endl;

    vector<vector<int>> temp1 = {{1, 2}};
    cout << test.maxAlternatingSum(temp_vector({1, 2, 3}), temp1) << endl;
}

//
// Created By Zackary At 2025-09-27 23:23
//
