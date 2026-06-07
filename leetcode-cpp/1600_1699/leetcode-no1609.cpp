// problem:  https://leetcode.cn/problems/even-odd-tree/?envType=problem-list-v2&envId=3rBpGyas
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
    bool isEvenOddTree(TreeNode *root) {
        vector<int> left;
        bool valid = true;
        [&](this auto &&dfs, TreeNode *rt, int depth) -> void {
            const auto val = rt->val;
            if (not((depth ^ val) & 1)) valid = false;
            if (depth >= left.size())
                left.push_back(val);
            else {
                if ((depth & 1 and left[depth] <= val) or (not(depth & 1) and left[depth] >= val)) valid = false;
                left[depth] = val;
            }
            if (rt->left) dfs(rt->left, depth + 1);
            if (rt->right) dfs(rt->right, depth + 1);
        }(root, 0);
        return valid;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isEvenOddTree(stringToTreeNode("[1,10,4,3,null,7,9,12,8,6,null,null,2]")) << endl;
    cout << test.isEvenOddTree(stringToTreeNode("[5,4,2,3,3,7]")) << endl;
}

//
// Created By jing At 2026-06-02 01:33
//
