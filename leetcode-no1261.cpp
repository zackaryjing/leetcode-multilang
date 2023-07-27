#include <iostream>
#include <vector>
#include <set>

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

class FindElements {
public:
    set<int> has;
    void dfs(TreeNode * root,int val){
        root->val = val;
        has.insert(val);
        if (root->left){
            dfs(root->left,2 * val + 1);
        }
        if (root->right){
            dfs(root->right,2 * val + 2);
        }
    }
    FindElements(TreeNode* root) {
        dfs(root,0);
    }

    bool find(int target) {
        if (has.find(target) == has.end()){
            return false;
        } else {
            return true;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main(){

}

//
// Created by ASUS on 2023/7/14.
//
