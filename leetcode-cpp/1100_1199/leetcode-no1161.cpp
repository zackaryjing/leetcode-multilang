// problem: https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/?envType=problem-list-v2&envId=OOhHf3Bc
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
    int maxLevelSum(TreeNode *root) {
        auto dq = queue<TreeNode *>();
        dq.push(root);
        int size = 1, depth = 1, total = 0, mx = INT_MIN, res = 0;
        while (not dq.empty()) {
            const auto rt = dq.front();
            dq.pop();
            total += rt->val;
            if (rt->left) {
                dq.push(rt->left);
            }
            if (rt->right) {
                dq.push(rt->right);
            }
            size--;
            if (size == 0) {
                size = dq.size();
                if (total > mx) {
                    res = depth;
                    mx = total;
                }
                total = 0;
                depth++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxLevelSum(stringToTreeNode("[1,7,0,7,-8,null,null]")) << endl;
    cout << test.maxLevelSum(stringToTreeNode("[989,null,10250,98693,-89388,null,null,null,-32127]")) << endl;
    cout << test.maxLevelSum(stringToTreeNode("[-100,-200,-300,-20,-5,-10,null]")) << endl;
}

//
// Created By jing At 2026-02-06 00:43
//
