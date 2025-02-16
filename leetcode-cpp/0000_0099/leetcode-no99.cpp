#include <iostream>
#include <vector>
#include "../utils/treegenerator.h"
using namespace std;
//Definition for a binary tree node.


class Solution {
    // Modified by ASUS on 2025/2/15.
    // 看来两年来思维上还是有点提升的，之前改了n版现在基本也可以一遍过了。
public:
    int prev = 0;
    TreeNode *prev_ptr = nullptr;
    int times = 0;
    TreeNode *first, *second, *first_next;
    bool isInit = true;

    void recoverTree(TreeNode *root) {
        prev_ptr = root;
        dfs(root);
        if (times == 1) {
            swap(first->val, first_next->val);
        } else {
            swap(first->val, second->val);
        }
    }

    void dfs(TreeNode *root) {
        if (root->left) {
            dfs(root->left);
        }

        if (not isInit) {
            if (root->val < prev) {
                if (times == 0) {
                    first = prev_ptr;
                    first_next = root;
                    times++;
                } else {
                    second = root;
                    times++;
                    return;
                }
            }
        }

        prev = root->val;
        prev_ptr = root;
        isInit = false;

        if (root->right) {
            dfs(root->right);
        }
    }
};

int main() {
    Solution test;
    TreeNode *eg1 = stringToTreeNode("[3,1,4,null,null,2]");
    prettyPrintTree(eg1);
    test.recoverTree(eg1);
    prettyPrintTree(eg1);
    cout << endl;

    Solution test2;
    TreeNode *eg2 = stringToTreeNode("[1,3,null,null,2]");
    prettyPrintTree(eg2);
    test2.recoverTree(eg2);
    prettyPrintTree(eg2);
}

class Solution_before {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                //
                predecessor = root->left;
                while (predecessor->right != nullptr and predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                //
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    if (pred != nullptr and root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }

                        pred = root;

                        predecessor->right = nullptr;
                        root = root->right;
                    }
                }
            } else {
                if (pred != nullptr and root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};

class Solution6 {
public:
    void recoverTree2(TreeNode *root) {
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};


class Solution4 {
public:
    TreeNode *first, *second;

    int dfs(TreeNode *root) {
        int left, right;
        if (root->left) {
            left = dfs(root->left);
            if (left > root->val) {
                if (first == nullptr) {
                    first = root->left;
                } else {
                    second = root->left;
                }
            }
        }
        if (root->right) {
            right = dfs(root->right);
            if (root->val > right) {
                if (first == nullptr) {
                    first = root;
                } else {
                    second = root;
                }
            }
            return right;
        }
        if (not root->right) {
            return root->val;
        }
    }

    void recoverTree(TreeNode *root) {
        dfs(root);
        cout << (first == nullptr) << endl;
        cout << first->val << endl;
        cout << second->val << endl;
    }
};


class Solution3 {
public:
    TreeNode *first;
    int wrong_val = 0;

    void dfs(TreeNode *root, int min, int max) {
        cout << root->val << " -- " << wrong_val << endl;
        if (root->left) {
            cout << "LEFT" << endl;
            if (root->val > max or root->val < min) {
                if (not first) {
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                dfs(root->left, min, root->val);
            }
        }
        if (root->right) {
            cout << "RIGHT" << endl;
            if (root->val > max or root->val < min) {
                cout << "?" << endl;
                if (not first) {
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                cout << "GOING" << endl;
                dfs(root->right, root->val, max);
            }
        }
    };

    void recoverTree(TreeNode *root) {
        dfs(root, 0,INT_MAX);
    }
};


class Solution2 {
public:
    TreeNode *first;
    int wrong_val = 0;

    void dfs(TreeNode *root) {
        cout << root->val << " -- " << wrong_val << endl;
        if (root->left) {
            cout << "LEFT" << endl;
            if (root->val < root->left->val) {
                if (not first) {
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                dfs(root->left);
            }
        }
        if (root->right) {
            cout << "RIGHT" << endl;
            if (root->val > root->right->val) {
                cout << "?" << endl;
                if (not first) {
                    first = root;
                } else {
                    first->val = root->val;
                    root->val = wrong_val;
                    return;
                }
            } else {
                cout << "GOING" << endl;
                dfs(root->right);
            }
        }
    };

    void recoverTree(TreeNode *root) {
        dfs(root);
    }
};

//
// Created by ASUS on 2023/6/29.
//
