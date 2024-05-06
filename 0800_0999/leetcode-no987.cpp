#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
*/

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
    // map<int, vector<map<int, int>>> cols;
    map<int, map<int, multiset<int>>> data;
    // col-> row ->
    vector<vector<int>> res;

    // col->([row->{val}])
public:
    void dfs(TreeNode *root, int row, int col) {
        data[col][row].insert(root->val);
        if (root->left) {
            dfs(root->left, row + 1, col - 1);
        }
        if (root->right) {
            dfs(root->right, row + 1, col + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
//        cout << res.size() << " <-- " << endl;
        dfs(root, 0, 0);
        for (auto [col, rows]: data) {
            vector<int> temp;
            for (auto [row, elements]: rows) {
                copy(elements.begin(), elements.end(), back_inserter(temp));
            }
            for (auto each: temp) cout << each << " ";
//            cout << endl;
            res.push_back(temp);
        }
        return res;
    }

    void clear() {
        res.clear();
        data.clear();
    }
};

int main() {
    Solution test;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node10 = new TreeNode(10);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    test.verticalTraversal(node1);
    cout << endl;
    test.clear();
    node5->val = 6;
    node6->val = 5;
    test.verticalTraversal(node1);
    cout << endl;
    test.clear();
    node1->val = 3;
    node2->val = 9;
    node3->val = 20;
    node6->val = 15;
    node7->val = 7;
    node2->left = nullptr;
    node2->right = nullptr;
    test.verticalTraversal(node1);
    cout << endl;
    test.clear();
//    node5->right = node8;
//    node8->left = node9;
//    node8->right = node10;
}
//
// Created by ASUS on 2024/2/26.
//
