// problem: https://leetcode.cn/problems/regions-cut-by-slashes/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> parent, rank;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unionSets(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
    }

    int regionsBySlashes(vector<string> &grid) {
        const int n = static_cast<int>(grid.size());
        const int m = static_cast<int>(grid[0].size());
        const int lineSize = 2 * m + 1;
        const int N = n * lineSize + m;
        parent.resize(N);
        rank.resize(N);
        ranges::iota(parent, 0);
        for (int i = 0; i < n; ++i) {
            auto &line = grid[i];
            for (int j = 0; j < m; ++j) {
                const int cur = i * lineSize + j;
                if (line[j] == '/') {
                    unionSets(cur, cur + m);
                    unionSets(cur + m + 1, cur + lineSize);
                } else if (line[j] == '\\') {
                    unionSets(cur, cur + m + 1);
                    unionSets(cur + m, cur + lineSize);
                } else {
                    unionSets(cur, cur + m);
                    unionSets(cur, cur + m + 1);
                    unionSets(cur, cur + lineSize);
                }
            }
        }
        vector<uint8_t> seen(N, 0);
        int components = 0;
        for (int i = 0; i < N; ++i) {
            int r = find(i);
            if (not seen[r]) {
                seen[r] = 1;
                ++components;
            }
        }
        return components;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<string> t1 = {"/\\", "\\/"};
    cout << test.regionsBySlashes(t1) << endl;
    cout << test.regionsBySlashes(temp_vector({" /", "  "})) << endl;
    cout << test.regionsBySlashes(temp_vector({" /", "/ "})) << endl;
}

//
// Created By jing At 2025-10-20 16:30
//
