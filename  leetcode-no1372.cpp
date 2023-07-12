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
    int ans = 1;
    void dfs(TreeNode* root,int from,int length){
//        cout << root->val << " " << ans << endl;
        if (length > ans) {
            ans = length;
        }
        if (from == 1){
            if (root->left){
                dfs(root->left,0,length + 1);
            }
            if (root->right){
                dfs(root->right,1,2);
            }
        } else {
            if (root->right){
                dfs(root->right,1,length + 1);
            }
            if (root->left) {
                dfs(root->left,0,2);
            }
        }

    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,1);
        dfs(root,1,1);
        return ans - 1;
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
    TreeNode node8(8);
    TreeNode node9(9);
    TreeNode node10(10);
    TreeNode node11(11);
    node1.left = &node2;
    node1.right = &node5;
    node2.left = &node3;
    node2.right = &node4;
    node5.right = &node6;
    node6.right = &node7;
    node5.left = &node8;
    node6.left = &node9;
    node9.right = &node10;
    node10.right = &node11;
    Solution test;
    cout << "ans: " << test.longestZigZag(&node1) << endl;
}
//
// Created by ASUS on 2023/7/10.
//
