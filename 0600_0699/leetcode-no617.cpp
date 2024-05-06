#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    void dfs(TreeNode* root1, TreeNode* root2) {
        if (root1->left && root2->left){
            root1->left->val += root2->left->val;
            dfs(root1->left,root2->left);
        } else if (not root1->left and root2){
            root1->left = root2->left;
        }
        if (root1->right and root2->right){
            root1->right->val += root2->right->val;
            dfs(root1->right,root2->right);
        } else if (not root1->right and root2->right){
            root1->right = root2->right;
        }

//        if (root1 and root2){
//            root1->val += root2->val;
//        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1){
            if (root2) {
                root1->val += root2->val;
                dfs(root1,root2);
            }
            return root1;
        } else {
            return root2;
        }
    }
};

void show(TreeNode* root,unordered_map<int,vector<int>> & res,int lvl){
    res[lvl].push_back(root->val);
    if (root->left) {
        show(root->left,res,lvl + 1);
    }
    if (root->right) {
        show(root->right,res,lvl + 1);
    }
}

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
    TreeNode * ans = test.mergeTrees(&node1,&node2);
    //vector<int> res;
    // queue<TreeNode*> q;
    //    q.push(ans);
    unordered_map<int,vector<int>> res;
    show(ans,res,0);
    for (int i = 0;i<4;i++){
        for (auto t : res[i]){
            cout << t << " ";
        }
        cout << endl;
    }
}

//    1
//   / \
//  2    5
// / \    \
//3   4    6
//          \
//          7
//
// Created by ASUS on 2023/7/2.
//
