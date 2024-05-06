#include <iostream>
#include <vector>
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
    int maxdepth = -1;
    map<int,int> times;
    void getmax(TreeNode* root,int lvl){
        if (root->left) {
            getmax(root->left,lvl + 1);
        } else {
            maxdepth = lvl;
//            cout << maxdepth << endl;
        }
    }
    bool isok = true;
    int down = 0;
    void dfs(TreeNode* root,int lvl){
        times[lvl]++;
        if (not root->left and not root->right){
            if (lvl != maxdepth and lvl != maxdepth - 1) {
                isok = false;
            } else if (lvl == maxdepth - 1){
                down = 1;
            } else if (down and lvl == maxdepth){
                isok = false;
            }
        }
        if (root->left){
            dfs(root->left, lvl + 1);
        }
        if (lvl == maxdepth - 1 and (not root->left or not root->right)){
            down = 1;
        }
        if (root->right) {
            dfs(root->right, lvl + 1);
        }
    }
    bool isCompleteTree(TreeNode* root) {
        getmax(root,0);
        dfs(root,0);
        for (int i = 0;i < maxdepth;i++){
            if (times[i] != ((i < 32) ? (1 << i) : (1 << 31))){
                isok = false;
            }
        }
        return isok;
    }
};

class Solution2 {
public:
    int maxdepth = -1;
    int down = 0;
    bool isok = true;
    void dfs(TreeNode* root,int lvl){
//        printf("%d <-> %d <=> %d\n",root->val,maxdepth,lvl);
        if (not root->left and not root->right){
            if (maxdepth == -1){
                maxdepth = lvl;
            } else {
                if (lvl > maxdepth) {
                    isok = false;
//                    printf("1\n");
                }
                else if (lvl == maxdepth and down) {
                    isok = false;
//                    printf("2\n");
                }
                else if (lvl < maxdepth - 1) {
                    isok = false;
//                    printf("%d <-> %d <=> %d\n",root->val,maxdepth,lvl);
//                    printf("3\n");
                }
                else if (lvl == maxdepth - 1) {
                    down = 1;
                }
            }
        }
        if (maxdepth != -1 and (not root->left or not root->right)){
            if (lvl == maxdepth - 1 and not root->left){
                down = 1;
            }
            if (lvl != maxdepth and lvl != maxdepth - 1) {
                isok = false;
//                printf("%d <-> %d <=> %d <-> %d <-> %d\n",root->val,maxdepth,lvl,down);
//                printf("4\n");
            }
        }
        if (root->left){
            dfs(root->left, lvl + 1);
        }
        if (root->right){
            dfs(root->right, lvl + 1);
        }

    }
    bool isCompleteTree(TreeNode* root) {
        dfs(root,0);
        return isok;
    }
};

int main(){
    Solution test;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node4->left = node9;
    node3->left = node6;
    node3->right = node7;
    node7->right = node8;
//    cout << test.isCompleteTree(node1) << endl;
//    cout << test.isCompleteTree(node7) << endl;
    cout << test.isCompleteTree(node2) << endl;
    cout << test.isCompleteTree(node3) << endl;
}
//
// Created by ASUS on 2023/8/9.
//
