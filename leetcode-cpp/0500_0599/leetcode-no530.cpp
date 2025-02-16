#include <iostream>
#include <deque>
#include <vector>
#include "../utils/treegenerator.h"

using namespace std;


class Solution {
public:
    int ans = 10000000;

    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return ans;
    }

    pair<int, int> dfs(TreeNode *root) {
        auto value = root->val;
        int left_max = value, right_min = value;
        int left_min = value, right_max = value;
        if (root->left) {
            tie(left_min, left_max) = dfs(root->left);
            ans = min(value - left_max, ans);
        }
        if (root->right) {
            tie(right_min, right_max) = dfs(root->right);
            ans = min(right_min - value, ans);
        }
        return {left_min, right_max};
    }
};


int main() {
    Solution test;
    cout << test.getMinimumDifference(stringToTreeNode("[1,0,48,null,null,12,49]")) << endl;;
}


//
// Created by ASUS on 2025/2/7.
//
