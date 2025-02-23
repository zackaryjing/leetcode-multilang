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
    TreeNode *cur_left;
    TreeNode *cur_right;

    vector<TreeNode *> lefts;
    vector<TreeNode *> rights;

    bool findTarget(TreeNode *root, int k) {
        // 双指针
        cur_left = root;
        cur_right = root;
        while (cur_left->left) {
            lefts.push_back(cur_left);
            cur_left = cur_left->left;
        }
        while (cur_right->right) {
            rights.push_back(cur_right);
            cur_right = cur_right->right;
        }
        while (cur_left != cur_right) {
            int total = cur_left->val + cur_right->val;
            if (total == k) {
                return true;
            } else if (total < k) {
                if (cur_left->right) {
                    cur_left = cur_left->right;
                    while (cur_left->left) {
                        lefts.push_back(cur_left);
                        cur_left = cur_left->left;
                    }
                } else {
                    cur_left = lefts.back();
                    lefts.pop_back();
                }
            } else {
                if (cur_right->left) {
                    cur_right = cur_right->left;
                    while (cur_right->right) {
                        rights.push_back(cur_right);
                        cur_right = cur_right->right;
                    }
                } else {
                    cur_right = rights.back();
                    rights.pop_back();
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findTarget(stringToTreeNode("[5,3,6,2,4,null,7]"), 28) << endl;;
    cout << test.findTarget(stringToTreeNode("[5,3,6,2,4,null,7]"), 9) << endl;;
}


//
// Created by ASUS on 2025/2/18.
//
