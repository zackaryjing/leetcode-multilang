// problem: https://leetcode.cn/problems/satisfiability-of-equality-equations/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
    vector<int> parent = vector<int>(26);
    vector<int> rank = vector<int>(26, 1);
    int find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }

    void unit(int a, int b) {
        if (a != b) {
            int pa = find(a);
            int pb = find(b);
            if (rank[pa] > rank[pb]) {
                swap(pa, pb);
            }
            rank[pb] += rank[pa];
            parent[pa] = pb;
        }
    }

public:
    bool equationsPossible(vector<string> &equations) {
        ranges::iota(parent, 0);
        vector<int> unequal;
        for (int i = 0; i < equations.size(); ++i) {
            auto e = equations[i];
            if (e[1] == '=') {
                unit(e[0] - 'a', e[3] - 'a');
            } else {
                unequal.push_back(i);
            }
        }
        for (auto u: unequal) {
            if (find(equations[u][0] - 'a') == find(equations[u][3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.equationsPossible(temp_vector({"a==b", "b==c", "a==c"})) << endl;
    cout << test.equationsPossible(temp_vector({"a==b", "b!=c", "c==a"})) << endl;
}

//
// Created By jing At 2026-01-01 19:41
//
