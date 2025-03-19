// problem: longest-special-path-ii
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<int, vector<pair<int, int> > > tree;

    void dfs(int node) {
        if (tree[node].empty()) {
            return;
        }
        // for (auto& [ch,val])
    }

    vector<int> longestSpecialPath(vector<vector<int> > &edges, vector<int> &nums) {
        for (auto edge: edges) {
            tree[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}


//
// Created by ASUS on 2025/3/15.
//
