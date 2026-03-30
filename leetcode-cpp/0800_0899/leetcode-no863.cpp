//symotion-prefix)  problem:
// https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
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
 *     TreeNode(int x) : val(x), left(NULL),
 * right(NULL) {}
 * };
 */
class Solution2 {
  TreeNode *target;
  unordered_map<TreeNode *, TreeNode *> upper;
  void find(TreeNode *root) {
    if (root != target) {
      if (root->left) {
        upper[root->left] = root;
        find(root->left);
      }
      if (root->right) {
        upper[root->right] = root;
        find(root->right);
      }
    }
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target,
                        int k) {
    this->target = target;
    find(root);
    auto q = queue<TreeNode *>();
    q.push(target);
    int depth = 0;
    unordered_set<TreeNode *> vis;
    while (not q.empty() and depth != k) {
      auto n = q.size();
      for (int i = 0; i < n; ++i) {
        auto c = q.front();
        q.pop();
        vis.insert(c);
        if (upper.contains(c))
          if (TreeNode *nc = upper[c]; not vis.contains(nc))
            q.emplace(nc);
        if (c->left and not vis.contains(c->left))
          q.emplace(c->left);
        if (c->right and not vis.contains(c->right))
          q.emplace(c->right);
      }
      depth++;
    }
    const int m = static_cast<int>(q.size());
    vector<int> res(m);
    for (int i = 0; i < m; ++i) {
      res[i] = q.front()->val;
      q.pop();
    }
    return res;
  }
};

class Solution {
  TreeNode *target;
  unordered_map<TreeNode *, TreeNode *> upper;
  void find(TreeNode *root) {
    if (root != target) {
      if (root->left) {
        upper[root->left] = root;
        find(root->left);
      }
      if (root->right) {
        upper[root->right] = root;
        find(root->right);
      }
    }
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target,
                        int k) {
    this->target = target;
    find(root);
    auto q = deque{target};
    int depth = 0;
    unordered_set<TreeNode *> vis;
    while (not q.empty() and depth != k) {
      const auto n = q.size();
      for (int i = 0; i < n; ++i) {
        auto c = q.front();
        q.pop_front(), vis.insert(c);
        if (upper.contains(c))
          if (TreeNode *nc = upper[c]; not vis.contains(nc))
            q.emplace_back(nc);
        if (c->left and not vis.contains(c->left))
          q.emplace_back(c->left);
        if (c->right and not vis.contains(c->right))
          q.emplace_back(c->right);
      }
      depth++;
    }
    return q |
           views::transform([](auto a) { return a->val; }) |
           ranges::to<vector<int>>();
  }
};

int main(int argc, char *argv[]) {
  Solution test;
  auto t1 =
  stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
  auto s1 = findTreeNode(t1, 5);

  show_vector(test.distanceK(t1, s1, 2));
}

//
// Created By ASUS At 2026-02-14 15:19
//
