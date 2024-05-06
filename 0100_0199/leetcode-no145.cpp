#include <iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root){
        if (root->left){
            dfs(root->left);
        }
        if (root->right){
            dfs(root->right);
        }
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root) dfs(root);
        return ans;
    }
};

int main(){
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    node1.left = &node2;
    node1.right = &node5;
    node2.left = &node3;
    node2.right = &node4;
    node5.right = &node6;
    node6.left = &node7;
    Solution test;
    vector<int> res = test.postorderTraversal(&node1);
    for (auto i : res) cout << i << " ";
}
//
// Created by ASUS on 2023/6/13.
//
