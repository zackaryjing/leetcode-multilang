#include "../utils/treegenerator.h"
#include "../utils/vector_helper.h"
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
    int prev;
    vector<int> ans;
    int max_length = 0;
    int cur_length = 0;

    vector<int> findMode(TreeNode *root) {
        prev = root->val;
        dfs(root);
        if (cur_length > max_length) {
            max_length = cur_length;
            ans.clear();
            ans.push_back(prev);
        } else if (cur_length == max_length) {
            ans.push_back(prev);
        }

        return ans;
    }

    void dfs(TreeNode *root) {
        if (root->left) {
            dfs(root->left);
        }

        if (root->val == prev) {
            cur_length++;
        } else {
            if (cur_length > max_length) {
                max_length = cur_length;
                ans.clear();
                ans.push_back(prev);
            } else if (cur_length == max_length) {
                ans.push_back(prev);
            }
            cur_length = 1;
        }
        prev = root->val;
        if (root->right) {
            dfs(root->right);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> res = test.findMode(stringToTreeNode("[1, null, 2]"));
    show_vector(res);
    Solution test1;
    vector<int> res1 = test1.findMode(stringToTreeNode("[0]"));
    show_vector(res1);
    Solution test2;
    vector<int> res2 = test2.findMode(stringToTreeNode("[1, null, 2, 2]"));
    show_vector(res2);
}


//
// Created by ASUS on 2025/2/16.
//
