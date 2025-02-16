#include <iostream>
#include <vector>

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
    int ans = 0;

    int maxDepth(Node *root) {
        if (root) {
            if (root->children.empty()) {
                return 1;
            } else {
                dfs(root, 1);
            }
            return ans;
        } else {
            return 0;
        }
    }

    void dfs(Node *root, int depth) {
        for (auto child: root->children) {
            if (not child->children.empty()) {
                ans = max(ans, depth + 1);
                dfs(child, depth + 1);
            } else {
                ans = max(ans, depth + 1);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created by ASUS on 2025/2/16.
//
