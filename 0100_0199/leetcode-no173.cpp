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

class BSTIterator_old {
public:
    vector<TreeNode *> stack;

//    int dfs(TreeNode* root){
//        if (root->left){
//            stack.push_back(root);
//        }
//    }
    int pointer;
    TreeNode *cur;

    BSTIterator(TreeNode *root) {
        while (root->left) {
            stack.push_back(root);
            root = root->left;
        }
        TreeNode *dummy = new TreeNode;
        stack.push_back(root);
        stack.push_back(dummy);
        pointer = stack.size() - 1;
    }

    int next() {
        if (pointer != 0) {
            pointer--;
            stack.pop_back();
            cur = stack[pointer];
            return cur->val;
        } else {
            TreeNode *root = cur->right;
            stack.pop_back();
            while (root->left) {
                stack.push_back(root);
                root = root->left;
            }
            stack.push_back(root);
            cur = root;
            pointer = stack.size() - 1;
            return cur->val;
        }

    }

    bool hasNext() {
        if (pointer == 0 and !cur->right) {
            return false;
        }
        return true;
    }
};


class BSTIterator {
private:
    vector<TreeNode *> stack;
    TreeNode* cur;
public:
    void go_left(TreeNode* &root){
        if (not root){
            return;
        }
        while (root) {
            stack.push_back(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode *root) {
        go_left(root);
    }

    int next() {
        if (not hasNext()){
            throw runtime_error("No element left");
        } else {
            cur = stack.back();
            stack.pop_back();
            go_left(cur->right);
            return cur->val;
        }
    }

    bool hasNext() {
        if (stack.empty() and !cur->right){
            return false;
        } else {
            return true;
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(7);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(9);
    TreeNode *node5 = new TreeNode(10);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    BSTIterator test(node1);
    cout << test.next() << endl;
    cout << test.next() << endl;
    cout << test.hasNext() << endl;
    cout << test.next() << endl;
    cout << test.hasNext() << endl;
    cout << test.next() << endl;
    cout << test.hasNext() << endl;
    cout << test.next() << endl;
    cout << test.hasNext() << endl;
    cout << endl;
    TreeNode *Node1 = new TreeNode(3);
    TreeNode *Node2 = new TreeNode(1);
    TreeNode *Node3 = new TreeNode(4);
    TreeNode *Node4 = new TreeNode(2);
    Node1->left = Node2;
    Node1->right = Node3;
    Node2->right = Node4;
    BSTIterator test2(Node1);
    cout << test2.hasNext() << endl;
    cout << test2.next() << endl;
    cout << test2.hasNext() << endl;
    cout << test2.next() << endl;
    cout << test2.hasNext() << endl;
    cout << test2.next() << endl;
    cout << test2.hasNext() << endl;
    cout << test2.next() << endl;
    cout << test2.hasNext() << endl;
}
//
// Created by ASUS on 2024/2/18.
//
