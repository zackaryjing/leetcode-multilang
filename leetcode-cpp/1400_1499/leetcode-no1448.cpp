#include "../utils/treegenerator.h"
#include <iostream>
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
    int ans = 0;

    void dfs(TreeNode *root, int max_num) {
        if (root->val >= max_num) {
            ans++;
            max_num = root->val;
        }
        if (root->left) {
            dfs(root->left, max_num);
        }
        if (root->right) {
            dfs(root->right, max_num);
        }
    }

    int goodNodes(TreeNode *root) {
        dfs(root, INT_MIN);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.goodNodes(stringToTreeNode("[3,1,4,3,null,1,5]")) << endl;
    cout << test.goodNodes(stringToTreeNode("[3,3,null,4,2]")) << endl;
    cout << test.goodNodes(stringToTreeNode("[1]")) << endl;
}


//
// Created by ASUS on 2025/2/22.
//
