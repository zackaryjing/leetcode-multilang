//Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <algorithm>
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
    void dfs(vector<int>& res,TreeNode* root){
        res.push_back(root->val);
        if (root->left){
            dfs(res,root->left);
        }
        if (root->right){
            dfs(res,root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        dfs(ans,root);
        sort(ans.begin(), ans.end());
        int min = INT_MAX;
        for (int i = 1;i<ans.size();i++){
            if ((ans[i] - ans[i - 1]) < min) min = ans[i] - ans[i - 1];
        }
        return min;
    }
};


int main(){
    Solution test;
    TreeNode node1(1, nullptr, nullptr);
    TreeNode node3(3, nullptr, nullptr);
    TreeNode node2(2, &node1, &node3);
    TreeNode node6(6, nullptr, nullptr);
    TreeNode node4(4, &node2, &node6);
    cout << test.minDiffInBST(&node4) << endl;
}
//
// Created by ASUS on 2023/6/26.
//
