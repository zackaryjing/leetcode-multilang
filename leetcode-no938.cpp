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
};

class Solution {
private:
    int sum, _low, _high;
public:
    void dfs(TreeNode *root) {
        if (_low <= root->val and root->val <= _high) {
            sum += root->val;

//            cout << root->val << " , ";
        }
        if (root->left and _low < root->val) {
            dfs(root->left);
        }
        if (root->right and root->val < _high) {
            dfs(root->right);
        }
    }

    int rangeSumBST(TreeNode *root, int low, int high) {
        sum = 0;
        _low = low;
        _high = high;
        dfs(root);
        return sum;
    }
};

int main() {
    Solution test;
    TreeNode *node1 = new TreeNode(10);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(7);
//    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(18);
//    TreeNode *node8 = new TreeNode(8);
//    TreeNode *node9 = new TreeNode(9);
//    TreeNode *node10 = new TreeNode(10);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node7;
    cout << test.rangeSumBST(node1,7,15) << endl; //
    cout << test.rangeSumBST(node1,5,7) << endl; // 6

}
//
// Created by ASUS on 2024/2/26.
//
