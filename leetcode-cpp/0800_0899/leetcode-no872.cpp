// problem: leaf-similar-trees/
#include <iostream>
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf;
        auto dfs = [&](auto &&self, TreeNode *root) -> void {
            bool has_left = false;
            bool has_right = false;
            if (root->left) {
                has_left = true;
                self(self, root->left);
            }
            if (root->right) {
                has_right = true;
                self(self, root->right);
            }
            if (not has_left and not has_right) {
                leaf.push_back(root->val);
            }
        };
        dfs(dfs, root1);
        int n = leaf.size();
        int index = 0;
        bool valid = true;
        auto check = [&](auto &&self, TreeNode *root) -> void {
            bool has_left = false;
            bool has_right = false;
            if (root->left) {
                has_left = true;
                self(self, root->left);
            }
            if (root->right) {
                has_right = true;
                self(self, root->right);
            }
            if (not has_left and not has_right) {
                if (index >= n or root->val != leaf[index++]) {
                    valid = false;
                }
            }
        };
        check(check, root2);
        return valid and index == n;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.leafSimilar(stringToTreeNode("[3,5,1,6,2,9,8,null,null,7,4]"),
                     stringToTreeNode("[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]")) << endl;
}


//
// Created by ASUS on 2025/3/14.
//
