// problem: https://leetcode.cn/problems/validate-binary-tree-nodes/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        int edgecnt = 0;
        unordered_map<int, vector<int>> graph;
        unordered_set occur(views::iota(0, n).begin(), views::iota(0, n).end());
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                edgecnt++;
                occur.erase(leftChild[i]);
                graph[i].push_back(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                edgecnt++;
                occur.erase(rightChild[i]);
                graph[i].push_back(rightChild[i]);
            }
        }
        if (edgecnt != n - 1 or occur.size() != 1) {
            return false;
        }
        unordered_set<int> vis;
        bool hasLoop = false;
        const auto dfs = [&](this auto &&dfs, int cur) {
            vis.insert(cur);
            for (const auto nx: graph[cur]) {
                if (vis.contains(nx)) {
                    hasLoop = true;
                    return;
                }
                dfs(nx);
            }
        };
        dfs(*occur.begin());
        return not hasLoop and vis.size() == n;
    }
};


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        int edgecnt = 0;
        vector<vector<int>> graph(n);
        vector<int> occur(n, 1);
        int noParCnt = n;
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                edgecnt++;
                auto &tmp = occur[leftChild[i]];
                if (tmp != 0) {
                    tmp = 0;
                    noParCnt--;
                }
                graph[i].push_back(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                edgecnt++;
                auto &tmp = occur[rightChild[i]];
                if (tmp != 0) {
                    tmp = 0;
                    noParCnt--;
                }
                graph[i].push_back(rightChild[i]);
            }
        }
        if (edgecnt != n - 1 or noParCnt != 1) {
            return false;
        }
        unordered_set<int> vis;
        bool hasLoop = false;
        const auto dfs = [&](this auto &&dfs, int cur) {
            vis.insert(cur);
            for (const auto nx: graph[cur]) {
                if (vis.contains(nx)) {
                    hasLoop = true;
                    return;
                }
                dfs(nx);
            }
        };
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (occur[i] == 1) {
                start = i;
                break;
            }
        }
        dfs(start);
        return not hasLoop and vis.size() == n;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << "1.1" << endl;
    cout << test.validateBinaryTreeNodes(4, temp_vector({1, -1, 3, -1}), temp_vector({2, -1, -1, -1})) << endl;
    cout << test.validateBinaryTreeNodes(4, temp_vector({1, -1, 3, -1}), temp_vector({2, 3, -1, -1})) << endl;
    cout << test.validateBinaryTreeNodes(4, temp_vector({1, 0}), temp_vector({-1, -1})) << endl;
    cout << test.validateBinaryTreeNodes(4, temp_vector({1, 0, 3, -1}), temp_vector({-1, -1, -1, -1})) << endl;
}

//
// Created By jing At 2026-05-04 00:15
//
