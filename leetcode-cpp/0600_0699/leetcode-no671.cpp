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
    int min_num = INT_MAX;
    int second_min_num = INT_MAX;
    int has_val = false;

    int findSecondMinimumValue(TreeNode *root) {
        if (not root) {
            return -1;
        }
        min_num = root->val;
        // second_min_num = root->val;
        dfs(root);
        if (has_val) {
            return second_min_num;
        } else {
            return -1;
        }
    }

    void dfs(TreeNode *root) {
        if (root->val < min_num) {
            second_min_num = min_num;
            has_val = true;
            min_num = root->val;
        } else if (root->val > min_num) {
            if (second_min_num >= root->val) {
                has_val = true;
                second_min_num = root->val;
            }
        }
        if (root->left) {
            dfs(root->left);
        }
        if (root->right) {
            dfs(root->right);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findSecondMinimumValue(stringToTreeNode("[2,2,5,null,null,5,7]")) << endl;
    Solution test1;
    cout << test1.findSecondMinimumValue(stringToTreeNode("[2,2,2]")) << endl; // -1
    Solution test2;
    cout << test2.findSecondMinimumValue(stringToTreeNode("[2,2,7]")) << endl; // 7
}


//
// Created by ASUS on 2025/2/19.
//
