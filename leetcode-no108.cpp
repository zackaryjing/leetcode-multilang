//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
    TreeNode* Build(int start,int end,vector<int>& source){
        // cout << start << " " << end << endl;
        if (start == end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        return new TreeNode (source[mid], Build(start,mid,source),Build(mid + 1,end,source));
        //return &tmp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // cout << "here" << endl;
        int length = nums.size();
        TreeNode* root = Build(0,length,nums);
        return root;
    }
};

void dfs(TreeNode* root,int lvl,unordered_map<int,vector<int>> &to){
    to[lvl].push_back(root->val);
    if (root->left) dfs(root->left,lvl+1,to);
    if (root->right) dfs(root->right,lvl+1,to);
    cout << "end" << endl;
}


int main(){
    Solution test;
    TreeNode node1(-10);
    TreeNode node2(5);
    TreeNode node3(-3,&node1, nullptr);
    TreeNode node4(9,&node2, nullptr);
    TreeNode node5(0,&node3,&node4);
    vector<int> input = {-10,-3,0,5,9};
    TreeNode* res = test.sortedArrayToBST(input);
    unordered_map<int,vector<int>> data;
    dfs(res,0,data);
    for (int i = 0;i < 3;i++) {
        for (auto j : data[i]) cout << j << " ";
        cout << endl;
    }
}
//
// Created by ASUS on 2023/6/20.
//
