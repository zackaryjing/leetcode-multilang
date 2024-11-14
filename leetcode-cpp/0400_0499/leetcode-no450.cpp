#include <vector>
#include <iostream>
#include <set>
#include <map>
// Definition for a binary tree node.
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
    TreeNode* findleftend(TreeNode* root){
        if (root->left){
            return findleftend(findleftend(root->left));
        } else {
            return root;
        }
    }
    void dfs(TreeNode* root,int target){
        //cout << root->val << " From dfs " << endl;
        if (root->left) {
            if (root->left->val == target){
                if (!root->left->right){
                    root->left = root->left->left;
                } else {
                    TreeNode* tmp = findleftend(root->left->right);
                    //cout << root->val << " " << tmp->val << endl;
                    tmp->left = root->left->left;
                    root->left = root->left->right;
                }
            } else {
                dfs(root->left,target);
            }
        }
        if (root->right){
            if (root->right->val == target){
                if (!root->right->right) {
                    root->right = root->right->left;
                } else {
                    TreeNode* tmp = findleftend(root->right->right);
                    tmp->left = root->right->left;
                    root->right = root->right->right;
                }
            } else {
                dfs(root->right,target);
            }

        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        static TreeNode dummy;
        //cout << "findl" << endl;
        dummy.left = root;
        dfs(&dummy,key);
        return dummy.left;
    }
};


void bfs(TreeNode  * root,int lvl,map<int,vector<int>> & to){
    //cout << root->val << "From bfs " << endl;
    to[lvl].push_back(root->val);
    if (root->left){
        bfs(root->left,lvl+1,to);
    }
    if (root->right){
        bfs(root->right,lvl+1,to);
    }
}
int main(){
    Solution test;
    TreeNode node2(2);
    TreeNode node4(4);
    TreeNode node7(7);
    TreeNode node6(6,nullptr,&node7);
    TreeNode node3(3,&node2,&node4);
    TreeNode node5(5,&node3,&node6);

    map<int,vector<int>> ans;
    cout << 1 << endl;
    TreeNode* res = test.deleteNode(&node5,3);
    cout << 3 << endl;
    bfs(res,0,ans);
    cout << 2 << endl;

    cout << ans.size() << " from main " << endl;
    for (int i = 0;i < 4;i++){
        for (auto j : ans[i]) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}
//
// Created by ASUS on 2023/6/19.
//
