// problem: https://leetcode.cn/problems/serialize-and-deserialize-bst/?envType=problem-list-v2&envId=tree
#include <iostream>
#include <vector>
#include "../utils/treegenerator.h"
#include <sstream>
#include <functional>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res = "";
        if (not root) {
            return "";
        }
        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            res += std::to_string(root->val) + " ";
            if (root->left) {
                dfs(root->left);
            }
            if (root->right) {
                dfs(root->right);
            }
        };
        dfs(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return {};
        }
        istringstream iss(data);
        int temp;
        iss >> temp;
        auto *rt = new TreeNode(temp);
        function<void(int, TreeNode *)> dfs = [&](int num, TreeNode *root) {
            if (root->val > num) {
                if (root->left) {
                    dfs(num, root->left);
                } else {
                    root->left = new TreeNode(num);
                }
            } else {
                if (root->right) {
                    dfs(num, root->right);
                } else {
                    root->right = new TreeNode(num);
                }
            }
        };
        while (iss >> temp) {
            dfs(temp, rt);
        }
        return rt;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


int main(int argc, char *argv[]) {
    Codec test;
    prettyPrintTree(stringToTreeNode("[5,4,9,2,null,7,null,1,null,6,null]"));
    prettyPrintTree(
            test.deserialize(
                    test.serialize(
                            stringToTreeNode("[5,4,9,2,null,7,null,1,null,6,null]"))));
}
