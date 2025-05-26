// problem: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
#include <deque>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (not root) {
            return {};
        }
        pmr::deque<Node *> tovis;
        int level = 0;
        vector<vector<int>> res = {{}};
        tovis.push_back(root);
        tovis.push_back(nullptr);
        while (not tovis.empty()) {
            Node *first = tovis.front();
            tovis.pop_front();
            if (first) {
                res[level].push_back(first->val);
                for (auto child: first->children) {
                    tovis.push_back(child);
                }
            } else {
                if (tovis.empty()) {
                    break;
                }
                level++;
                res.emplace_back();
                tovis.push_back(nullptr);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node4 = new Node(4);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3, {node5, node6});
    Node *node1 = new Node(1, {node3, node2, node4});
    for (const auto &list: test.levelOrder(node1)) {
        show_vector(list);
    }
}

//
// Created By Zackary At 2025-05-26 15:12:35
//
