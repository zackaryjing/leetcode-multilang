// problem:
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <format>
#include <print>
#include "../utils/vector_helper.h"
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
class Solution {
public:
    int sumEvenGrandparent(TreeNode *root) {
        int res = 0;
        auto dfs = [&](this auto &&self, TreeNode *r, bool grad, bool parent) -> void {
            // print("{0} {1} {2}\n", r->val, grad, parent);
            if (grad) {
                res += r->val;
            }
            auto nparent = not(r->val & 1);
            if (r->left) {
                self(r->left, parent, nparent);
            }

            if (r->right) {
                self(r->right, parent, nparent);
            }
        };
        dfs(root, false, false);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sumEvenGrandparent(stringToTreeNode("[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]")) << endl;
}

//
// Created By ASUS At 2025-12-19 15:24
//
