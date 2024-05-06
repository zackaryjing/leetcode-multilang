#include <iostream>
#include <vector>
#include <utility>
#include <map>
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
    map<int,pair<long long,long long>> data;
    void dfs(TreeNode *root, int lvl) {
        data[lvl].first += root->val;
        data[lvl].second ++;
        if (root->left) {
            dfs(root->left, lvl + 1);
        }
        if (root->right) {
            dfs(root->right, lvl + 1);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root,0);
        vector<double> ans;
        for (auto [_,level] : data){
            ans.push_back((double)level.first / level.second);
        }
        return ans;
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
    vector<double> res = test.averageOfLevels(&node1);
    for (auto k : res) cout << k << " ";
}


//
// Created by ASUS on 2023/8/11.
//
