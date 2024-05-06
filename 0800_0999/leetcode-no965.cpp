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
    int target;
    bool dfs(TreeNode* root){
        if (root->val != target){
            return false;
        }
        if (root->left) {
            if (not dfs(root->left)){
                return false;
            }
        }
        if (root->right) {
            if (not dfs(root->right)){
                return false;
            }
        }
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        target = root->val;
        return dfs(root);
    }
};

int main(){
    Solution test;

}
//
// Created by ASUS on 2023/8/28.
//
