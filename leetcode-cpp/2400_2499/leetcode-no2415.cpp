// problem: https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
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
    TreeNode *reverseOddLevels(TreeNode *root) {
        auto level = deque<TreeNode *>();
        level.push_back(root);
        int cnt = 1;
        while (not level.empty()) {
            vector<int> vallist;
            for (int i = 0; i < cnt; ++i) {
                auto rt = level.front();
                level.pop_front();
                if (rt->left) {
                    level.push_back(rt->left);
                    vallist.push_back(rt->left->val);
                }
                if (rt->right) {
                    level.push_back(rt->right);
                    vallist.push_back(rt->right->val);
                }
            }
            auto cur = vallist.end();
            for (auto item = level.rbegin(); item != level.rend(); ++item) {
                (*item)->val = cur->val;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-09-09 21:38
//
