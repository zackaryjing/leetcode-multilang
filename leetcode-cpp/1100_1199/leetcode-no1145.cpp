// problem: https://leetcode.cn/problems/binary-tree-coloring-game/
#include <functional>
#include <iostream>
#include <bitset>
#include <vector>
#include "../utils/treegenerator.h"
#include "../utils/vector_helper.h"
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
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        int left = 0;
        int right = 0;
        function<int(const TreeNode *, int)> dfs = [&](const TreeNode *rt, const int level) -> int {
            int leftCnt = 0, rightCnt = 0;
            if (rt->left) {
                leftCnt = dfs(rt->left, level + 1);
            }
            if (rt->right) {
                rightCnt = dfs(rt->right, level + 1);
            }
            if (rt->val == x) {
                left = leftCnt;
                right = rightCnt;
            }
            return leftCnt + rightCnt + 1;
        };
        (void) dfs(root, 0);
        const int top = n - left - right - 1;
        return top > left + right or left > top + right or right > top + left;
    }
};


class Solution2 {
public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        vector<int8_t> lefts(n + 1);
        vector<int8_t> rights(n + 1);
        int length = 0;
        bitset<100> posRecord;
        bitset<100> pos;
        function<int(const TreeNode *, int)> dfs = [&](const TreeNode *rt, int level) -> int8_t {
            int8_t leftCnt = 0, rightCnt = 0;
            if (rt->val == x) {
                pos = posRecord;
                length = level;
            }
            if (rt->left) {
                posRecord.reset(level);
                leftCnt = dfs(rt->left, level + 1);
                lefts[rt->val] = leftCnt;
            }
            if (rt->right) {
                posRecord.set(level);
                rightCnt = dfs(rt->right, level + 1);
                rights[rt->val] = rightCnt;
            }
            return leftCnt + rightCnt + 1;
        };
        dfs(root, 0);

        int8_t top = 0;
        for (int i = 0; i < length; i++) {
            if (pos[i]) {
                top += lefts[root->val] + 1;
                root = root->right;
            } else {
                top += rights[root->val] + 1;
                root = root->left;
            }
        }
        int8_t left = lefts[root->val];
        int8_t right = rights[root->val];
        return top > left + right or left > top + right or right > top + left;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.btreeGameWinningMove(stringToTreeNode("[1,2,3,4,5,6,7,8,9,10,11]"), 11, 3) << endl;
    cout << test.btreeGameWinningMove(stringToTreeNode("[1,2,3]"), 3, 1) << endl;
}

//
// Created By Zackary At 2025-06-05 23:42:17
//
