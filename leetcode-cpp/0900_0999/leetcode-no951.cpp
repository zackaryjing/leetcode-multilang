// problem:  https://leetcode.cn/problems/flip-equivalent-binary-trees/
#include <functional>
#include <iostream>
#include "../utils/treegenerator.h"
#include <vector>
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
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        auto valid = true;
        function<void(TreeNode *, TreeNode *)> dfs = [&](TreeNode *root, TreeNode *cur) {
            auto cur_left = cur->left ? cur->left->val : -1;
            auto cur_right = cur->right ? cur->right->val : -1;
            auto root_left = root->left ? root->left->val : -1;
            auto root_right = root->right ? root->right->val : -1;
            if (cur_left == root_left and cur_right == root_right) {
                if (root_left != -1) {
                    dfs(root->left, cur->left);
                }
                if (root_right != -1) {
                    dfs(root->right, cur->right);
                }
            } else if (cur_right == root_left and cur_left == root_right) {
                if (root_left != -1) {
                    dfs(root->left, cur->right);
                }
                if (root_right != -1) {
                    dfs(root->right, cur->left);
                }
            } else {
                valid = false;
            }
        };
        TreeNode dummy1(-1, root1, nullptr);
        TreeNode dummy2(-1, root2, nullptr);
        dfs(&dummy1, &dummy2);
        return valid;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.flipEquiv(stringToTreeNode("[1,2,3,4,5,6,null,null,null,7,8]"),
                           stringToTreeNode("[1,3,2,null,6,4,5,null,null,null,null,8,7]")) << endl;
    cout << test.flipEquiv(stringToTreeNode("[]"), stringToTreeNode("[]")) << endl;
    cout << test.flipEquiv(stringToTreeNode("[]"),
                           stringToTreeNode("[1]")) << endl;
}

//
// Created By Zackary At 2025-05-07 19:50:18
//
