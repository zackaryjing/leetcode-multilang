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
    int ans = 0;
    void dfs(TreeNode* root,int val){
        if (not root->left and not root->right){
            ans += val;
            return;
        }
        if (root->left){

            dfs(root->left,val * 10 + root->left->val);
        }
        if (root->right){
            dfs(root->right,val * 10 + root->right->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (not root){
            return 0;
        }
        dfs(root,root->val);
        return ans;
    }
};




int main(){
    Solution test;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    cout << test.sumNumbers(root) << endl;
}

//
// Created by ASUS on 2023/7/28.
//
