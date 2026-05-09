// problem: https://leetcode.cn/problems/maximum-binary-tree-ii/?envType=problem-list-v2&envId=3rBpGyas
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        auto dummy = new TreeNode(-1);
        const auto dfs = [&](this auto &&dfs, TreeNode *cur, TreeNode *par) {
            if (val > cur->val) {
                auto temp = new TreeNode(val);
                par->right = temp;
                temp->left = cur;
                return;
            }
            if (cur->right)
                dfs(cur->right, cur);
            else
                cur->right = new TreeNode(val);
        };
        dummy->right = root;
        dfs(root, dummy);
        return dummy->right;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    TreeNode *a = stringToTreeNode("[4,1,3,null,null,2]");
    prettyPrintTree(test.insertIntoMaxTree(a, 5));
}

//
// Created By jing At 2026-05-04 16:23
//
