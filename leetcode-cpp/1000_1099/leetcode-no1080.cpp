// problem:
// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/?envType=problem-list-v2&envId=OOhHf3Bc
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
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        auto dummy = TreeNode(0, root, nullptr);
        const auto dfs = [&](this auto &&dfs, TreeNode *rt, int sum) -> bool {
            bool hasChild = false, valid = false;
            const int curSum = sum + rt->val;
            if (rt->left) {
                hasChild = true;
                const auto temp = dfs(rt->left, curSum);
                valid |= temp;
                if (not temp) rt->left = nullptr;
            }
            if (rt->right) {
                hasChild = true;
                const auto temp = dfs(rt->right, curSum);
                valid |= temp;
                if (not temp) rt->right = nullptr;
            }
            if (not hasChild) {
                if (curSum < limit) return false;
                return true;
            }
            return valid;
        }(&dummy, 0);
        return dummy.left;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-28 19:21
//
