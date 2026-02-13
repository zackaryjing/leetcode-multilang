// problem: https://leetcode.cn/problems/flip-binary-tree-to-match-preorder-traversal/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
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
    vector<int> order;
    int cur = 1;
    bool valid = true;
    vector<int> res;

public:
    void dfs(TreeNode *root) {
        if (cur >= order.size()) return;
        if (root->left and root->right) {
            if (root->left->val != order[cur]) {
                if (root->right->val == order[cur]) {
                    res.push_back(root->val);
                    cur++;
                    dfs(root->right);
                } else {
                    valid = false;
                    return;
                }
                if (root->left->val == order[cur]) {
                    cur++;
                    dfs(root->left);
                } else {
                    valid = false;
                }
            } else {
                cur++;
                dfs(root->left);
                if (root->right->val == order[cur]) {
                    cur++;
                    dfs(root->right);
                } else {
                    valid = false;
                }
            }
        } else if (root->left) {
            if (root->left->val != order[cur]) {
                valid = false;
            } else {
                cur++;
                dfs(root->left);
            }
        } else if (root->right) {
            if (root->right->val != order[cur]) {
                valid = false;
            } else {
                cur++;
                dfs(root->right);
            }
        }
    }

    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        order = voyage;
        if (root->val == voyage[0]) {
            dfs(root);
        } else {
            valid = false;
        }
        if (not valid) return {-1};
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.flipMatchVoyage(stringToTreeNode("[1,2,3]"), temp_vector({1, 3, 2})));
}

//
// Created By ASUS At 2026-02-12 17:21
//
