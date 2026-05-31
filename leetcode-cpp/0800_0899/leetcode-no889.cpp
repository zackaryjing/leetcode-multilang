// problem:
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        return [&](this auto &&dfs, int l1, int l2, int length) -> TreeNode * {
            const auto rt = new TreeNode(preorder[l1]);
            if (length > 1) {
                int pre = 0, post = 0, m = 0;
                for (; m < length; ++m) {
                    pre |= 1 << preorder[l1 + m + 1];
                    post |= 1 << postorder[l2 + m];
                    if (pre == post) break;
                }
                if (m == 0)
                    rt->left = new TreeNode(preorder[l1 + 1]);
                else
                    rt->left = dfs(l1 + 1, l2, m + 1);
                if (length == m + 3)
                    rt->right = new TreeNode(preorder[l1 + m + 2]);
                else if (length - 2 > m)
                    rt->right = dfs(l1 + m + 2, l2 + m + 1, length - m - 2);
            }
            return rt;
        }(0, 0, preorder.size());
    }
};


class Solution2 {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        return [&](this auto &&dfs, int l1, int l2, int length) -> TreeNode * {
            const auto rt = new TreeNode(preorder[l1]);
            if (length > 1) {
                int pre = 0, post = 0, m = 0;
                for (; m < length; ++m) {
                    pre |= 1 << preorder[l1 + m + 1];
                    post |= 1 << postorder[l2 + m];
                    if (pre == post) {
                        break;
                    }
                }
                rt->left = dfs(l1 + 1, l2, m + 1);
                if (m < length - 2) {
                    rt->right = dfs(l1 + m + 2, l2 + m + 1, length - m - 2);
                }
            }
            return rt;
        }(0, 0, preorder.size());
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    prettyPrintTree(test.constructFromPrePost(temp_vector({1, 2, 4, 5, 3, 6, 7}), temp_vector({4, 5, 2, 6, 7, 3, 1})));
    prettyPrintTree(test.constructFromPrePost(temp_vector({2, 1}), temp_vector({1, 2})));
}

//
// Created By jing At 2026-05-30 22:28
//
