#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 *
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    vector<TreeNode *> target;
    TreeNode *result;
public:
    void dfs(TreeNode *root) {
//        cout << root->val << endl;
        if (find(target.begin(), target.end(), root) != target.end()) {
            result = root;
            return;
        }
        if (root->val > target[0]->val and root->val > target[1]->val) {
            dfs(root->left);
        } else if (root->val < target[0]->val and root->val < target[1]->val) {
            dfs(root->right);
        } else {
            result = root;
//            cout << "here " <<  result->val << endl;
            return;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        target = {p, q};
        dfs(root);
        return result;
    }
};


int main() {
    Solution test;
    TreeNode *node1 = new TreeNode(6);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(8);
    TreeNode *node4 = new TreeNode(0);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(7);
    TreeNode *node7 = new TreeNode(9);
    TreeNode *node8 = new TreeNode(3);
    TreeNode *node9 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    TreeNode* res = test.lowestCommonAncestor(node1, node5, node3);
    cout << res->val << "<--" <<endl;
    res = test.lowestCommonAncestor(node1, node8, node9);
    cout << res->val << "<--" << endl;
    res = test.lowestCommonAncestor(node1, node6, node7);
    cout << res->val << "<--" << endl;
    res = test.lowestCommonAncestor(node1, node2, node9);
    cout << res->val << "<--" << endl;
}
//
// Created by ASUS on 2024/2/25.
//
