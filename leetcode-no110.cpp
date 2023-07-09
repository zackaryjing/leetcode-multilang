//Definition for a binary tree node.
#include <iostream>
#include <vector>
using namespace std;
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
    int dfs(TreeNode* root,int* result) {
        int leftdepth = 0,rightdepth = 0;
        if (root->left) {
            leftdepth = dfs(root->left,result);
        }
        if (root->right) {
            rightdepth = dfs(root->right,result);
        }
        //cout << root->val << " " << leftdepth << " " << rightdepth << endl;
        if (abs(rightdepth-leftdepth) > 1){
            *result = 0;
        }
        return max(rightdepth, leftdepth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (not root){
            return true;
        }
        int ans = 1;
        dfs(root,&ans);
        if (ans == 0) return false;
        else return true;
    }
};

TreeNode node15(15, nullptr, nullptr);
TreeNode node7(7, nullptr, nullptr);
TreeNode node20(20, &node7,&node15);
TreeNode node9(9, nullptr, nullptr);
TreeNode node3(3, &node9, &node20);

int main(){
    Solution test;
    cout << test.isBalanced(&node3) << endl;
}
//
// Created by ASUS on 2023/6/28.
//
