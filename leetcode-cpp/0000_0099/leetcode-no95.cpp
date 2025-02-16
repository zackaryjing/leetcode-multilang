#include <iostream>
#include <vector>
#include <map>
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
    map<int, vector<TreeNode *> > trees;
    int cur_value = 1;

    void setval(TreeNode *root) {
        if (root->left) {
            setval(root->left);
        }
        root->val = cur_value;
        cur_value++;
        if (root->right) {
            setval(root->right);
        }
    }

    TreeNode *cloneTree(TreeNode *root) {
        if (!root) return nullptr; // 递归终止条件
        return new TreeNode(root->val, cloneTree(root->left), cloneTree(root->right));
    }

    vector<TreeNode *> generateTrees(int n) {
        trees[0].push_back(nullptr);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                for (auto left: trees[j]) {
                    for (auto right: trees[i - 1 - j]) {
                        // cout << i << endl;
                        trees[i].push_back(new TreeNode(i, cloneTree(left), cloneTree(right)));
                    }
                }
            }
        }

        // for (int i = 0; i <= n; i++) {
        //     cout << i << " " << trees[i].size() << endl;
        // }

        // cout << endl;
        for (auto t: trees[n]) {
            cur_value = 1;
            setval(t);
            // prettyPrintTree(t);
            // cout << endl;
        }
        return trees[n];
    }


    // ~Solution() { // 加了这个leetcode反而过不去，总结为就内存泄露吧，开发中用智能指针就好了
    //     for (const auto &[_,val]: trees) {
    //         for (auto t: val) {
    //             delete t;
    //         }
    //     }
    // }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.generateTrees(8);
}


//
// Created by ASUS on 2025/2/15.
//
