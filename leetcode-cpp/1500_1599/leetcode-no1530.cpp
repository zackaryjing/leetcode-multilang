// problem: https://leetcode.cn/problems/number-of-good-leaf-nodes-pairs/
#include <bitset>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include "../utils/treegenerator.h"
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<vector<int>, int> dfs(int distance, TreeNode *root) {
        vector<int> depth(distance + 1, 0);
        bool isLeaf = not root->left and not root->right;
        if (isLeaf) {
            depth[0] = 1;
            return make_pair(depth, 0);
        }
        vector<int> left_depth(distance + 1), right_depth(distance + 1);
        int left_cnt = 0, right_cnt = 0;
        if (root->left) {
            tie(left_depth, left_cnt) = dfs(distance, root->left);
        }
        if (root->right) {
            tie(right_depth, right_cnt) = dfs(distance, root->right);
        }
        for (int i = 0; i < distance; ++i) {
            depth[i + 1] += left_depth[i] + right_depth[i];
        }
        int cnt = 0;
        for (int i = 0; i <= distance; ++i) {
            for (int j = 0; j + i + 2 <= distance; ++j) {
                cnt += left_depth[i] * right_depth[j];
            }
        }
        return {depth, cnt + left_cnt + right_cnt};
    }

    int countPairs(TreeNode *root, int distance) {
        auto [dep, res] = dfs(distance, root);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto temp = stringToTreeNode("[15,66,55,97,60,12,56,null,54,null,49,null,9,null,null,null,null,null,90]");
    // prettyPrintTree(temp);
    cout << test.countPairs(temp, 5) << endl;
    cout << test.countPairs(stringToTreeNode("[1,2,3,null,4]"), 3) << endl;
    cout << test.countPairs(stringToTreeNode("[1,2,3,4,5,6,7]"), 3) << endl;
}


#define N 1024

class Solution2 {
    // [Fatal] TLE
public:
    int countPairs(TreeNode *root, int distance) {
        using Storage = bitset<N>;
        vector<Storage> pos;
        pos.reserve(520);
        function cal_dist = [](Storage u, Storage v)-> int {
            int res = 0;
            int i = N - 1, j = N - 1;
            int sa = 0, sb = 0;
            for (; i >= 0; --i) {
                if (u[i] == 0) {
                    sa++;
                } else {
                    break;
                }
            }
            for (; j >= 0; --j) {
                if (v[j] == 0) {
                    sb++;
                } else {
                    break;
                }
            }
            res = sa + sb;
            while (i >= 0 and j >= 0 and u[i] == v[j]) {
                sa += 1;
                sb += 1;
                i--, j--;
            }
            return N * 2 - sa - sb;
        };
        int ans = 0;
        function<void(TreeNode *, Storage)> dfs = [&](TreeNode *rt, Storage id)-> void {
            if (not rt->left and not rt->right) {
                // while (not pos.empty() and cal_dist(pos.front(), id) > distance) {
                // pos.pop_front();
                // }
                // ans += static_cast<int>(pos.size());
                for (auto k: pos) {
                    if (cal_dist(k, id) <= distance) {
                        ans += 1;
                    }
                }
                pos.push_back(id);
                return;
            }
            if (rt->left) {
                dfs(rt->left, id << 1);
            }
            if (rt->right) {
                dfs(rt->right, (id << 1).set(0));
            }
        };
        dfs(root, 1);
        return ans;
    }
};


//
// Created By Zackary At 2025-04-25 16:57:43
//
