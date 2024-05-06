#include <iostream>
#include <vector>
#include <string>
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
    bool check(TreeNode* root,TreeNode* subroot){
        //cout << "Check " << root->val << endl;
        bool left = false,right = false;
        if (root->val != subroot->val){
            return false;
        }
        if (root->left and subroot->left){
            left = check(root->left,subroot->left);
        } else if ((not root->left) and (not subroot->left)){
            left = true;
        }
        if (root->right and subroot->right){
            right = check(root->right,subroot->right);
        } else if ((not root->right) and (not subroot->right)){
            right = true;
        }
        if (not (left and right)){
            return false;
        }
        return true;
    }
    bool ans = false;
    void dfs(TreeNode * root,TreeNode* target){
        //cout << "dfs " << root->val << endl;
        if (root->val == target->val){
            if (check(root,target)){
                ans = true;
                return;
            }
        }
        if (root->left){
            dfs(root->left,target);
        }
        if (root->right){
            dfs(root->right,target);
        }

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root and subRoot){
            dfs(root,subRoot);
            return ans;
        } else {
            return false;
        }
    }
};

class Solution2 {
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string first = dfs(root);
        string second = dfs(subRoot);
        return first.find(second,0) != string::npos;
    }
};

int main(){
    Solution test;
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
    cout << test.isSubtree(&node1,&node2);
}
//
// Created by ASUS on 2023/6/30.
//
