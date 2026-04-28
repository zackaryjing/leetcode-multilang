// problem: https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
#include <algorithm>
#include <iostream>
#include <ranges>
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        TreeNode *res;
        auto dfs = [&](this auto &&dfs, TreeNode *ori, TreeNode *clo) -> void {
            if (ori == target) {
                res = clo;
            }
            if (ori->left) {
                dfs(ori->left, clo->left);
            }
            if (ori->right) {
                dfs(ori->right, clo->right);
            }
        };
        dfs(original, cloned);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    TreeNode *a = stringToTreeNode("[7,4,3,null,null,6,19]");
    TreeNode *b = stringToTreeNode("[7,4,3,null,null,6,19]");
    test.getTargetCopy(a, b, a);
}

//
// Created By jing At 2026-04-28 18:44
//
