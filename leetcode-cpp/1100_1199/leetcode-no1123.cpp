// problem: https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2025-04-04
#include <functional>
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

class Solution2 {
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        int max_depth = 0;
        TreeNode *ans = root;
        auto dfs = [&](auto &&self, TreeNode *root, int depth)-> int {
            int left_depth = depth;
            int right_depth = depth;
            max_depth = max(depth, max_depth);
            if (root->left) {
                left_depth = self(self, root->left, depth + 1);
            }
            if (root->right) {
                right_depth = self(self, root->right, depth + 1);
            }
            if (left_depth == max_depth and right_depth == max_depth) {
                ans = root;
            }
            return max({right_depth, left_depth, depth});
        };
        dfs(dfs, root, 0);
        return ans;
    }
};



class Solution3 {
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        int max_depth = 0;
        TreeNode *ans = root;
        function<int(TreeNode *, int)> dfs = [&](TreeNode *const root, const int depth)-> int {
            int left_depth = depth;
            int right_depth = depth;
            max_depth = max(depth, max_depth);
            if (root->left) {
                left_depth = dfs(root->left, depth + 1);
            }
            if (root->right) {
                right_depth = dfs(root->right, depth + 1);
            }
            if (left_depth == max_depth and right_depth == max_depth) {
                ans = root;
            }
            return max({right_depth, left_depth, depth});
        };
        dfs(root, 0);
        return ans;
    }
};


class Solution {
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        int max_depth = 0;
        TreeNode *ans = root;
        auto dfs = [&](this auto &&dfs, TreeNode *root, int depth)-> int {
            int left_depth = depth;
            int right_depth = depth;
            max_depth = max(depth, max_depth);
            if (root->left) {
                left_depth = dfs(root->left, depth + 1);
            }
            if (root->right) {
                right_depth = dfs(root->right, depth + 1);
            }
            if (left_depth == max_depth and right_depth == max_depth) {
                ans = root;
            }
            return max({right_depth, left_depth, depth});
        };
        dfs(root, 0);
        return ans;
    }
};



int main(int argc, char *argv[]) {
    Solution test;
    cout << test.lcaDeepestLeaves(stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]"))->val << endl;
    cout << test.lcaDeepestLeaves(stringToTreeNode("[0,1,3,null,2]"))->val << endl;
    cout << test.lcaDeepestLeaves(stringToTreeNode("[1]"))->val << endl;
}


//
// Created by ASUS on 2025/4/7.
//
