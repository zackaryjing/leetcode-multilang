#include <iostream>
#include <vector>
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
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr , *pred = nullptr,*predecessor = nullptr;

        while (root != nullptr){
            if (root->left != nullptr){
                //
                predecessor = root->left;
                while (predecessor->right != nullptr and predecessor->right != root){
                    predecessor = predecessor->right;
                }

                //
                if (predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                } else {
                    if (pred != nullptr and root->val < pred->val){
                        y = root;
                        if (x == nullptr){
                            x = pred;
                        }

                        pred = root;

                        predecessor->right = nullptr;
                        root = root->right;
                    }
                }
            } else {
                if (pred != nullptr and root->val < pred->val){
                    y = root;
                    if (x == nullptr){
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val,y->val);
    }
};

class Solution6 {
public:
    void recoverTree2(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                    // 说明左子树已经访问完了，我们需要断开链接
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
                // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};


class Solution4 {
public:
    TreeNode* first,*second;
    int dfs(TreeNode * root){
        int left,right;
        if (root->left) {
            left = dfs(root->left);
            if (left > root->val){
                if (first == nullptr){
                    first = root->left;
                } else {
                    second = root->left;
                }
            }
        }
        if (root->right){
            right = dfs(root->right);
            if (root->val > right){
                if (first == nullptr){
                    first = root;
                } else {
                    second = root;
                }

            }
            return right;
        } if (not root->right){
            return root->val;
        }

    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        cout << (first == nullptr) << endl;
        cout << first->val << endl;
        cout << second->val << endl;
    }
};

int main(){
    Solution test;
    TreeNode node7(7, nullptr, nullptr);
    TreeNode node6(6, nullptr, &node7);
    TreeNode node4(5, nullptr, nullptr);
    TreeNode node1(1, nullptr, nullptr);
    TreeNode node3(3, &node1, &node4);
    TreeNode node5(4,&node3,&node6);
    TreeNode* what;
    cout << (what == nullptr) << " TEST " << endl;
    test.recoverTree(&node5);
    cout << "HRER" << endl;
    cout << node5.val << endl;
    cout << node4.val << endl;
}

class Solution3 {
public:
    TreeNode* first;
    int wrong_val = 0;
    void dfs(TreeNode* root,int min,int max){
        cout << root->val << " -- " << wrong_val << endl;
        if (root->left){
            cout << "LEFT" << endl;
            if (root->val > max or root->val < min){
                if (not first){
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                dfs(root->left,min,root->val);
            }
        }
        if (root->right){
            cout << "RIGHT" << endl;
            if (root->val > max or root->val < min){
                cout << "?" << endl;
                if (not first){
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                cout << "GOING" << endl;
                dfs(root->right,root->val,max);
            }
        }
    };
    void recoverTree(TreeNode* root) {
        dfs(root,0,INT_MAX);
    }
};


class Solution2 {
public:
    TreeNode* first;
    int wrong_val = 0;
    void dfs(TreeNode* root){
        cout << root->val << " -- " << wrong_val << endl;
        if (root->left){
            cout << "LEFT" << endl;
            if (root->val < root->left->val){
                if (not first){
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                dfs(root->left);
            }
        }
        if (root->right){
            cout << "RIGHT" << endl;
            if (root->val > root->right->val){
                cout << "?" << endl;
                if (not first){
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                cout << "GOING" << endl;
                dfs(root->right);
            }
        }
    };
    void recoverTree(TreeNode* root) {
        dfs(root);
    }
};
//
// Created by ASUS on 2023/6/29.
//
