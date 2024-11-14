#include <iostream>
#include <vector>
#include <algorithm>

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

TreeNode *generator(vector<int> data) {
    vector<TreeNode *> tmp;
    for (auto node: data) {
        tmp.push_back(new TreeNode(node));
    }
    int k = data.size() / 2 - 1;
    for (int i = 0; i <= k; ++i) {
        if (tmp[i * 2 + 1]->val != INT_MAX) {
            tmp[i]->left = tmp[i * 2 + 1];
        }
        if ((i * 2 + 2) < data.size() and tmp[i * 2 + 2]->val != INT_MAX) {
            tmp[i]->right = tmp[i * 2 + 2];
        }
    }
    return tmp[0];
}

class Solution {
public:
    vector<long long> sides;
    vector<int> ans;
    int depth = -1;

    void dfs(TreeNode *root, int lvl, unsigned int pos) {
        if (lvl > depth) {
            sides.push_back(pos);
            ans.push_back(1);

            depth++;
        } else {
            ans[lvl] = pos - sides[lvl] + 1;
        }
        if (root->left) {
            dfs(root->left, lvl + 1, pos * 2);
        }
        if (root->right) {
            dfs(root->right, lvl + 1, pos * 2 + 1);
        }
    }

    int widthOfBinaryTree(TreeNode *root) {
        dfs(root, 0, 1);
        int res = *max_element(ans.begin(), ans.end());
        return res;
    }
};

void test_dfs(TreeNode *root) {
    if (root->left) {
        test_dfs(root->left);
    }
    if (root->right) {
        test_dfs(root->right);
    }
}

int main() {
    Solution test;
//    vector<int> num = {1, 3, 2, 5, 4, INT_MAX, 9};
    vector<int> num = {0,0,0,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX,INT_MAX,0,0,INT_MAX};
    TreeNode *r = generator(num);
    test_dfs(r);
    cout << test.widthOfBinaryTree(r) << endl;

}
//
// Created by ASUS on 2024/3/18.
//
