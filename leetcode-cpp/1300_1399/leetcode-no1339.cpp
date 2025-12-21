// problem: https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"
#include <deque>
#include "../utils/treegenerator.h"


using namespace std;

/**
 * Definition for a binary tree node.
  struct TreeNode {
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
    int maxProduct(TreeNode *root) {
        long long total = 0;
        deque<TreeNode *> nodeList;
        nodeList.push_back(root);
        while (nodeList.size() > 0) {
            auto c = nodeList.front();
            total += c->val;
            nodeList.pop_front();
            if (c->left) {
                nodeList.push_back(c->left);
            }
            if (c->right) {
                nodeList.push_back(c->right);
            }
        }
        cout << "total: " << total << endl;
        auto key = INT_MAX;
        [&](this auto &&dfs, TreeNode *root)-> int {
            int section = root->val << 1;
            if (root->left) {
                section += dfs(root->left);
            }
            if (root->right) {
                section += dfs(root->right);
            }
            if (abs(key) > abs(section - total)) {
                key = section - total;
            }
            return section;
        }(root);
        auto t = (total - key) >> 1;
        return t * (total - t) % 1000000007;
    }
};


class Solution {
public:
    int maxProduct(TreeNode *root) {
        const long long total = [&](this auto &&dfs, TreeNode *root)-> long long {
            long long section = root->val;
            if (root->left) {
                section += dfs(root->left);
            }
            if (root->right) {
                section += dfs(root->right);
            }
            return section;
        }(root);
        cout << "total: " << total << endl;
        auto key = INT_MAX;
        [&](this auto &&dfs, TreeNode *root)-> int {
            int section = root->val << 1;
            if (root->left) {
                section += dfs(root->left);
            }
            if (root->right) {
                section += dfs(root->right);
            }
            if (abs(key) > abs(section - total)) {
                key = section - total;
            }
            return section;
        }(root);
        auto t = (total - key) >> 1;
        return t * (total - t) % 1000000007;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxProduct(stringToTreeNode("[1,2,3,4,5,6]")) << endl;
    cout << test.maxProduct(stringToTreeNode("[1,null,2,3,4,null,null,5,6]")) << endl;
}

//
// Created By ASUS At 2025-12-19 15:52
//
