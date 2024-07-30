#include <iostream>
#include <memory>
#include <vector>
#include <utility>


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
    pair<int,int> dfs(TreeNode* root){
        int leftmin = INT_MAX,leftmax = 0;
        int rightmin = INT_MAX,rightmax= 0;
        if (root->left){
            pair<int,int> tmp = dfs(root->left);
            leftmin = tmp.first;
            leftmax = tmp.second;
            if (abs(root->val - leftmax) > ans or abs(root->val - leftmin) > ans){
                ans = max(abs(root->val - leftmax),abs(root->val - leftmin));
            }
        }
        if (root->right){
            pair<int,int> tmp = dfs(root->right);
            rightmin = tmp.first;
            rightmax = tmp.second;
            if (abs(root->val - rightmax) > ans or abs(root->val - rightmin) > ans){
                ans = max(abs(root->val - rightmax),abs(root->val - rightmin));
            }
        }
        return make_pair(min(root->val,min(leftmin,rightmin)),max(root->val,max(leftmax,rightmax)));
//        return min(root->val,max(fromleft,fromright));
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
int main(){
    Solution test;
    TreeNode * node1 = new TreeNode(1);
    TreeNode * node2 = new TreeNode(2);
    TreeNode * node3 = new TreeNode(3);
    TreeNode * node4 = new TreeNode(4);
    TreeNode * node5 = new TreeNode(5);
    TreeNode * node6 = new TreeNode(6);
    TreeNode * node7 = new TreeNode(7);
    TreeNode * node8 = new TreeNode(8);
    TreeNode * node9 = new TreeNode(9);
    TreeNode * node10 = new TreeNode(10);
    TreeNode * node11 = new TreeNode(11);
    TreeNode * node12 = new TreeNode(12);
    TreeNode * node13 = new TreeNode(13);
    TreeNode * node14 = new TreeNode(14);
    node8->left = node3;
    node3->left = node1;
    node3->right =  node6;
    node6->left = node4;
    node6->right = node7;
    node8->right = node10;
    node10->right = node14;
    node14->right = node13;

    cout << test.maxAncestorDiff(node8) << endl;
}

//
// Created by ASUS on 2023/7/16.
//
//    unique_ptr<TreeNode> node1 = make_unique<TreeNode>(1);
//    unique_ptr<TreeNode> node2 = make_unique<TreeNode>(2);
//    unique_ptr<TreeNode> node3 = make_unique<TreeNode>(3);
//    unique_ptr<TreeNode> node4 = make_unique<TreeNode>(4);
//    unique_ptr<TreeNode> node5 = make_unique<TreeNode>(5);
//    unique_ptr<TreeNode> node6 = make_unique<TreeNode>(6);
//    unique_ptr<TreeNode> node7 = make_unique<TreeNode>(7);
//    unique_ptr<TreeNode> node8 = make_unique<TreeNode>(8);
//    unique_ptr<TreeNode> node9 = make_unique<TreeNode>(9);
//    unique_ptr<TreeNode> node10 = make_unique<TreeNode>(10);
//    unique_ptr<TreeNode> node11 = make_unique<TreeNode>(11);
//    unique_ptr<TreeNode> node12 = make_unique<TreeNode>(12);
//    unique_ptr<TreeNode> node13 = make_unique<TreeNode>(13);
//    unique_ptr<TreeNode> node14 = make_unique<TreeNode>(14);
