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

    TreeNode(vector<int> data) {
        vector<TreeNode*> tmp;
        for (auto node : data) {
            tmp.push_back(new TreeNode(node));
        }
        int k = data.size()  / 2 - 2;
        for (int i = 0;i <= k;++i){
            tmp[i]->left = tmp[i * 2 + 1];
            if (i * 2 + 2 < data.size()){
                tmp[i]->right = tmp[i * 2 + 2];
            }
        }
        return tmp[0];
    }
};



//
// Created by ASUS on 2024/3/18.
//
