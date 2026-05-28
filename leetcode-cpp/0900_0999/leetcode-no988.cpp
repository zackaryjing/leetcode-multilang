// problem: https://leetcode.cn/problems/smallest-string-starting-from-leaf/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "../utils/treegenerator.h"
#include "../utils/vector_helper.h"


using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode *root) {
        unordered_map<TreeNode *, TreeNode *> par;
        vector<TreeNode *> candidate;
        int mn = 26, mnDepth = 0;
        [&](this auto &&dfs, TreeNode *rt, int depth) -> void {
            bool hasChild = false;
            if (rt->left) {
                hasChild = true;
                dfs(rt->left, depth + 1);
                par[rt->left] = rt;
            }
            if (rt->right) {
                hasChild = true;
                dfs(rt->right, depth + 1);
                par[rt->right] = rt;
            }
            if (not hasChild and rt->val <= mn) {
                if (rt->val < mn) candidate.clear();
                mn = rt->val;
                candidate.push_back(rt);
            }
        }(root, 0);
        string res = "";
        res.push_back(candidate[0]->val + 'a');
        bool found = false;
        while (true) {
            vector<TreeNode *> nCandidate;
            int mnc = 26;
            for (auto &cand: candidate) {
                if (cand == root) {
                    found = true;
                    nCandidate.clear();
                    mnc = root->val;
                    break;
                }
                if (par[cand]->val <= mnc) {
                    if (par[cand]->val < mnc) {
                        nCandidate.clear();
                    }
                    mnc = par[cand]->val;
                    nCandidate.push_back(par[cand]);
                }
            }
            if (found) break;
            res.push_back(mnc + 'a');
            candidate = nCandidate;
        }
        return res;
    }
};




int main(int argc, char *argv[]) {
    Solution test;
    // cout << test.smallestFromLeaf(stringToTreeNode("[0,1,2,3,4,3,4]")) << endl;
    cout << test.smallestFromLeaf(stringToTreeNode("[25,1,3,1,3,0,2]")) << endl;
    cout << test.smallestFromLeaf(stringToTreeNode("[25,1,null,0,0,1,null,null,null,0]")) << endl;
    // cout << test.smallestFromLeaf(stringToTreeNode("[2,2,1,null,1,0,null,0]")) << endl;
}

//
// Created By jing At 2026-05-27 20:36
//
