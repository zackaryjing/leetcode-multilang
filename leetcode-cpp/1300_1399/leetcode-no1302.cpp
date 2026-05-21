// problem: https://leetcode.cn/problems/deepest-leaves-sum/?envType=problem-list-v2&envId=OOhHf3Bc
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
    int deepestLeavesSum(TreeNode *root) {
        int mxl = 0, s = 0;
        [&](this auto &&dfs, TreeNode *rt, int level) -> void {
            if (rt->left) {
                dfs(rt->left, level + 1);
            }
            if (rt->right) {
                dfs(rt->right, level + 1);
            }
            if (level == mxl) {
                s += rt->val;
            } else if (level > mxl) {
                s = rt->val;
                mxl = level;
            }
        }(root, 0);
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.deepestLeavesSum(stringToTreeNode("[1,2,3,4,5,null,6,7,null,null,null,null,8]")) << endl;
    cout << test.deepestLeavesSum(stringToTreeNode("[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]")) << endl;
}

//
// Created By jing At 2026-05-19 15:01
//
