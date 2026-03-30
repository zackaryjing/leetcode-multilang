// problem: https://leetcode.cn/problems/minimum-number-of-vertices-to-reach-all-nodes/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    };

    void unit(int a, int b) {
        parent[find(a)] = parent[find(b)];
    };

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int> > &edges) {
        parent = vector<int>(n);
        ranges::iota(parent, 0);
        for (const auto &edge: edges) {
            if (find(edge[1]) == edge[1]) {
                unit(edge[1], edge[0]);
            }
        }
        unordered_set<int> groups;
        for (int i = 0; i < n; ++i) {
            parent[i] = find(i);
            groups.insert(parent[i]);
        }
        return {groups.begin(), groups.end()};
    }
};

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };

    void unit(int a, int b) {
        parent[find(a)] = parent[find(b)];
    };

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int> > &edges) {
        parent = vector<int>(n);
        ranges::iota(parent, 0);
        for (const auto edge: edges) {
            if (find(edge[1]) == edge[1]) {
                unit(edge[1], edge[0]);
            }
        }
        unordered_set<int> groups;
        for (int i = 0; i < n; ++i) {
            find(i);
            groups.insert(parent[i]);
        }
        return {groups.begin(), groups.end()};
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.findSmallestSetOfVertices(6, temp_vector({
                                                   temp_vector({0, 1}), temp_vector({0, 2}), temp_vector({2, 5}),
                                                   temp_vector({3, 4}), temp_vector({4, 2})
                                               })));
}

//
// Created By ASUS At 2026-02-10 21:27
//
