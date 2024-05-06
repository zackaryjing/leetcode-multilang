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
    string dfs(TreeNode* root){
        string left = "";
        string right = "";
        if (root->left){
            left = dfs(root->left);
        }
        if (root->right){
            right = dfs(root->right);
        }
        string res = to_string(root->val);
        if (!right.empty()) {
            if (!left.empty()){
                res += "(" + left + ")";
            } else {
                res += "()";
            }
            res += "(" + right + ")";
        } else {
            if (!left.empty()){
                res += "(" + left + ")";
            }
        }
        return res;
    }
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};

int main(){
    Solution test;
    TreeNode node7(7, nullptr, nullptr);
    TreeNode node3(3, nullptr, &node7);
    TreeNode node4(4, nullptr, nullptr);
    TreeNode node5(5, nullptr, nullptr);
    TreeNode node2(2, &node4, &node5);
    TreeNode node1(1,&node2,&node3);
    cout << test.tree2str(&node1) << endl;
}
//
// Created by ASUS on 2023/6/29.
//
