// problem: https://leetcode.cn/problems/delete-leaves-with-a-given-value/
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
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        auto dummy = TreeNode(-1, root, nullptr);
        [&target](this auto &&dfs, TreeNode *rt) -> bool {
            bool nochild = true;
            if (rt->left) {
                if (dfs(rt->left))
                    rt->left = nullptr;
                else
                    nochild = false;
            }
            if (rt->right) {
                if (dfs(rt->right))
                    rt->right = nullptr;
                else
                    nochild = false;
            }
            if (nochild and rt->val == target) return true;
            return false;
        }(&dummy);
        return dummy.left;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    prettyPrintTree(test.removeLeafNodes(stringToTreeNode("[1,2,3,2,null,2,4]"), 2));
    prettyPrintTree(test.removeLeafNodes(stringToTreeNode("[1,3,3,3,2]"), 3));
}

//
// Created By jing At 2026-05-22 18:03
//
