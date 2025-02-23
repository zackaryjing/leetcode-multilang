#include <deque>
#include "../utils/treegenerator.h"
#include <iostream>

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
    string serialize(TreeNode *root) {
        queue<TreeNode *> data;
        string ans = "[";
        if (!root) return "[]";
        bool is_first = true;
        data.push(root);
        while (!data.empty()) {
            TreeNode *cur = data.front();
            data.pop();
            if (cur == nullptr) {
                ans += ",null";
            } else {
                ans += (is_first ? "" : ",") + to_string(cur->val);
                is_first = false;
                data.push(cur->left);
                data.push(cur->right);
            }
        }
        ans += "]";
        return ans;
    }

    TreeNode *deserialize(string data) {
        if (data == "[]") return nullptr;
        vector<string> nodes;
        size_t start = 1, n = data.size();

        // 解析字符串为节点值数组
        while (start < n - 1) {
            size_t end = data.find(',', start);
            if (end == string::npos) end = n - 1;
            nodes.push_back(data.substr(start, end - start));
            start = end + 1;
        }

        if (nodes.empty()) return nullptr;
        if (nodes[0] == "null") return nullptr;

        // 使用队列构建树
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        q.push(root);
        size_t i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode *cur = q.front();
            q.pop();

            // 左子节点
            if (i < nodes.size() && nodes[i] != "null") {
                cur->left = new TreeNode(stoi(nodes[i]));
                q.push(cur->left);
            }
            i++;

            // 右子节点
            if (i < nodes.size() && nodes[i] != "null") {
                cur->right = new TreeNode(stoi(nodes[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }
};

class Codec_2 {
    // 我的版本
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        queue<TreeNode *> data;
        string ans = "[";
        if (not root) {
            return "[]";
        }
        bool is_first = true;
        data.push(root);
        while (not data.empty()) {
            TreeNode *cur = data.front();
            data.pop();
            if (cur == nullptr) {
                ans += ",null";
            } else {
                ans += (is_first ? "" : ",") + to_string(cur->val);
                is_first = false;
                data.push(cur->left);
                data.push(cur->right);
            }
        }
        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        deque<TreeNode *> tree;
        TreeNode *cur;
        int state = 2;
        size_t start_index = 1;
        const size_t n = data.size();
        bool is_first = true;
        TreeNode *first_node = nullptr;
        while (start_index < n - 1) {
            cout << tree.size() << endl;
            auto ch = data[start_index];
            while (ch == ',' or ch == ' ') {
                start_index++;
                ch = data[start_index];
            }
            if (ch == ']') {
                break;
            }
            TreeNode *new_node;
            if (data.substr(start_index, 4) == "null") {
                new_node = nullptr;
                start_index += 4;
            } else {
                const char *start_ptr = data.c_str() + start_index;
                size_t len = 0;
                int number = std::stoi(start_ptr, &len);
                start_index += len;
                new_node = new TreeNode(number);
                tree.push_back(new_node);
            }

            if (is_first) {
                first_node = new_node;
                is_first = false;
                continue;
            }

            if (state == 2) {
                cur = tree.front();
                tree.pop_front();
                state = 0;
            }

            if (state == 0) {
                cur->left = new_node;
                state = 1;
            } else if (state == 1) {
                cur->right = new_node;
                state = 2;
            }
        }
        return first_node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, char *argv[]) {
    Codec test;
    // auto eg1 = stringToTreeNode("[1,2,3,null,null,4,5]");
    // auto eg1 = stringToTreeNode("[4,null]");
    // cout << test.serialize(eg1) << endl;
    // auto res1 = test.deserialize("[4,null]");
    // cout << (res1 != nullptr) << endl;
    // cout << treeNodeToString(res1);
    //
    Codec_2 test2;
    string eg2 =
            "[7,3,6,8,2,3,6,4,7,6,5,1,null,3,null,8,7,9,9,6,5,3,3,0,null,0,0,0,null,1,6,2,6,7,0,9,null,8,null,5,2,2,6,3,null,3,2,9,0,5,2,null,8,7,0,8,null,6,9,8,5,9,1,9,0,8,8,0,5,null,5,1,8,8,0,3,3,4,6,7,null,1,null,null,null,8,3,0,6,2,null,6,8,null,9,5,8,5,0,6,6,1,7,0,8,9,7,2,1,5,8,6,9,1,null,6,null,null,4,7,0,6,9,3,3,9,2,1,3,7,7,9,9,1,5,5,null,3,4,4,6,3,2,6,1,4,0,4,4,4,9,7,2,8,6,6,null,1,9,2,6,1,1,null,8,6,1,1,7,7,6,7,1,0,4,1,3,4,4,null,null,4,1,8,7,5,6,null,2,5,6,9,7,null,8,6,7,null,9,8,9,9,9,1,null,7,null,7,7,8,0,8,5,1,null,2,6,7,9,5,2,8,null,2,null,7,5,5,null,2,null,0,7,null,null,null,5,5,9,9,null,0,1,null,5,null,5,6,5,null,1,3,9,null,1,9,0,6,8,7,2,1,4,4,7,7,8,0,8,3,7,7,8,7,3,7,6,7,5,5,9,7,null,9,9,1,3,2,2,5,6,2,4,3,null,5,null,5,3,1,null,0,6,0,8,6,1,1,3,4,3,0,8,7,null,null,6,null,null,2,7,0,null,2,null,1,6,7,6,3,null,null,0,5,5,0,7,3,6,5,3,2,5,null,9,2,7,0,5,null,9,1,5,null,3,1,7,null,6,5,3,5,null,6,5,5,9,0,0,2,6,3,9,3,2,3,0,4,null,7,0,5,1,7,5,4,2,null,5,8,9,9,0,9,9,6,8,2,0,null,1,null,0,null,1,5,3,8,1,6,3,8,null,0,8,null,3,9,5,1,6,4,7,8,0,8,7,9,9,2,null,3,6,1,0,6,4,1,7,6,null,9,5,7,1,2,6,null,2,null,0,9,null,8,8,3,7,0,3,5,3,8,4,7,2,3,7,5,7,3,5,6,2,7,7,null,0,5,7,4,1,null,0,null,6,0,7,null,2,4,7,8,6,1,0,9,1,9,4,3,2,0,null,4,9,4,1,7,5,8,null,9,0,2,null,4,3,1,2,4,2,6,2,5,1,null,0,0,7,8,9,7,6,null,null,3,null,7,2,0,5,8,null,2,null,0,5,1,1,4,1,2,5,8,9,2,5,0,null,2,8,null,null,2,4,0,6,4,null,8,0,6,8,2,null,4,4,0,2,0,9,6,2,null,null,6,0,2,9,5,9,7,0,9,3,null,8,5,5,null,4,1,5,8,3,3,7,null,8,null,8,null,9,4,null,2,7,2,8,8,6,7,5,3,9,6,4,0,null,5,0,8,7,8,null,5,9,6,null,6,6,5,2,3,9,8,1,2,0,2,1,null,8,8,null,8,4,null,1,null,0,0,1,8,7,7,9,8,9,null,7,1,null,7,9,3,9,null,7,3,7,null,8,1,2,8,3,4,null,5,7,0,6,7,1,null,null,1,null,8,4,3,6,0,9,null,2,3,0,3,8,null,6,null,null,7,2,7,9,null,4,9,4,null,8,null,3,4,6,0,0,2,8,1,5,0,7,1,3,0,4,4,5,3,0,0,2,1,5,5,1,3,8,3,null,6,8,1,2,null,0,9,2,null,null,8,8,null,4,9,6,9,8,8,5,1,5,0,6,6,0,9,null,5,null,4,2,null,9,0,4,7,7,1,null,null,null,5,9,8,null,null,5,5,8,null,9,7,0,0,2,4,0,1,3,5,8,null,9,7,6,8,6,0,1,9,9,4,3,3,0,5,null,null,7,8,5,null,9,6,1,6,7,2,7,3,5,8,4,4,8,null,7,null,3,8,0,2,8,8,2,1,8,4,1,null,null,7,1,0,0,7,5,6,null,0,7,null,0,null,4,8,4,null,null,6,2,0,null,5,4,8,3,null,3,6,8,2,5,6,null,1,1,4,1,null,7,2,8,7,6,5,null,9,7,9,1,4,null,4,9,null,3,1,null,null,9,7,null,0,8,4,4,8,2,7,0,0,4,7,1,null,9,2,4,5,null,5,4,4,3,9,8,1,3,3,1,0,4,5,8,6,0,0,null,null,1,1,0,9,3,0,4,null,2,1,9,1,4,0,5,2,0,null,1,1,8,7,9,8,2,9,2,7,5,3,3,6,7,null,2,0,9,5,9,null,6,null,6,3,1,3,0,0,8,0,2,4,3,2,9,7,null,2,2,2,null,2,4,9,2,0,null,5,null,3,7,0,1,3,3,8,4,0,9,3,2,6,null,5,9,5,6,3,3,2,0,4,3,0,0,5,null,7,null,4,1,1,9,null,null,0,4,5,7,2,6,8,8,null,null,2,3,8,2,2,3,2,7,2,2,null,2,9,0,9,0,6,6,1,5,null,null,8,8,9,7,5,0,6,null,9,4,8,0,2,7,5,1,4,8,5,9,3,6,0,5,3,null,0,3,0,5,8,7,2,3,6,8,6,9,0,4,6,1,3,1,3,2,3,5,6,3,8,7,3,3,6,5,1,2,2,9,4,3,3,0,4,null,4,4,2,null,null,7,null,5,2,2,1,0,3,null,1,2,3,0,6,2,7,2,9,5,9,1,3,5,8,9,null,5,0,5,1,null,2,7,0,8,4,6,null,2,2,8,5,null,4,5,8,8,7,9,0,8,9,9,0,4,8,6,3,8,5,0,1,1,0,8,4,7,null,1,null,6,2,2,9,9,8,2,3,5,6,4,8,null,null,4,null,1,6,2,3,null,3,null,7,5,null,9,2,0,7,4,2,0,7,0,2,9,1,1,8,0,3,9,7,0,0,2,5,9,null,3,null,null,4,9,null,0,5,0,6,8,0,0,9,0,3,1,null,7,7,0,0,9,1,7,8,2,null,6,9,1,0,1,8,1,9,8,8,8,5,6,3,5,7,0,7,7,9,6,null,null,1,8,null,2,7,6,7,4,6,4,1,2,2,1,2,1,null,7,8,7,null,3,1,5,null,3,9,1,3,5,3,7,7,3,null,0,2,4,9,3,7,7,5,null,0,0,null,5,0,7,6,2,8,2,null,4,null,2,7,null,null,7,3,4,1,7,8,2,6,4,7,8,7,8,3,4,9,3,6,9,6,5,9,0,6,5,4,9,4,2,7,1,1,2,0,5,2,9,null,5,6,1,7,0,7,null,9,7,9,9,null,null,8,1,2,2,9,9,3,7,null,2,0,3,null,null,6,5,null,7,null,0,4,1,3,null,6,7,4,0,5,1,null,8,null,8,2,1,2,3,2,9,8,3,null,3,4,1,5,1,7,3,null,4,3,5,7,9,4,2,null,1,4,3,null,9,7,null,2,null,1,2,2,3,8,8,3,1,5,1,null,6,1,5,5,0,null,1,null,8,9,3,8,7,5,4,0,9,9,5,null,4,null,null,1,0,1,0,3,null,0,7,1,2,5,4,2,1,3,9,null,null,null,1,5,6,4,null,3,0,4,0,1,3,6,null,0,6,5,null,2,null,7,null,null,null,null,1,3,4,7,5,null,null,0,3,8,0,null,3,1,7,3,null,2,9,9,1,null,9,null,4,5,null,7,0,null,5,9,2,6,2,4,3,0,3,0,7,3,7,4,4,1,9,3,2,3,7,2,null,6,8,1,2,0,0,1,6,5,5,6,7,4,7,8,6,2,8,8,6,4,5,8,4,0,5,3,1,null,1,9,6,null,null,9,3,6,8,3,5,0,null,6,5,8,null,1,null,9,2,5,1,5,1,null,8,null,null,6,3,6,4,1,null,2,1,2,9,8,4,3,2,5,null,0,5,6,null,null,2,1,6,4,4,9,1,9,9,3,6,3,3,0,5,7,0,7,2,4,0,9,6,5,null,1,0,4,9,3,4,4,0,null,9,2,0,7,3,8,0,8,3,4,6,null,7,8,2,7,3,1,9,3,3,4,4,null,3,4,null,null,8,8,9,9,null,5,null,1,5,7,0,9,6,1,8,8,7,7,null,null,0,3,0,null,8,4,5,0,9,5,7,null,5,0,8,7,8,0,2,4,4,3,9,0,8,4,3,4,3,8,6,2,1,5,null,null,0,2,4,0,6,5,2,8,7,2,9,1,7,null,5,0,null,null,null,7,4,1,5,8,6,null,7,0,3,8,2,9,8,1,null,0,7,null,2,null,8,7,6,5,1,1,7,9,7,3,7,null,5,null,2,4,6,8,null,0,4,5,8,null,7,5,9,1,null,null,5,8,5,0,null,null,1,1,0,2,0,4,5,3,3,8,0,4,null,2,3,8,null,9,5,4,4,6,5,4,7,2,0,1,null,4,8,9,0,7,8,2,8,0,5,4,6,2,8,5,2,6,7,5,9,0,4,null,6,9,2,0,2,6,null,null,null,7,2,2,7,0,9,null,9,9,null,1,6,null,3,9,1,9,6,5,0,0,3,8,6,2,0,2,null,7,null,8,1,3,7,null,1,null,6,9,3,6,8,2,8,4,3,6,6,8,null,3,1,1,8,3,0,9,6,null,5,7,5,null,9,2,1,7,3,7,3,null,3,2,null,2,null,4,4,9,0,1,8,5,5,1,7,5,3,0,8,5,3,6,6,5,null,3,6,7,8,null,0,1,6,5,null,5,7,3,1,2,6,3,null,6,1,7,4,9,3,3,1,1,8,4,6,null,1,2,0,null,7,9,4,6,0,7,3,4,7,3,0,1,9,6,8,2,7,null,null,7,1,2,1,0,8,8,8,2,0,3,7,3,1,8,null,5,3,2,8,7,8,null,null,8,9,9,7,null,null,7,4,7,4,null,7,7,9,3,null,3,0,6,0,5,7,2,2,6,4,3,null,7,0,6,9,9,5,2,3,6,7,null,8,2,null,6,null,8,4,1,2,0,3,null,4,9,7,3,9,4,8,6,0,0,null,5,null,2,0,3,1,9,0,8,8,null,9,8,8,7,2,0,5,4,4,5,0,2,2,6,8,5,3,5,8,9,8,6,9,4,7,4,3,2,4,1,9,9,0,2,9,null,null,4,3,null,null,5,7,1,6,3,5,9,null,1,null,2,4,9,1,8,3,2,null,7,7,3,8,5,1,3,5,9,null,8,8,2,6,9,0,2,5,1,7,6,0,2,0,7,6,null,0,3,9,6,9,5,6,1,null,3,7,null,6,2,3,4,9,5,4,null,null,1,null,4,7,5,9,null,4,0,4,7,4,1,6,7,7,0,5,1,8,1,3,2,3,4,3,2,9,8,2,8,2,0,8,6,1,4,9,9,9,7,5,8,0,6,4,3,0,null,null,4,4,null,null,5,null,5,1,0,5,null,8,5,null,null,6,1,1,0,7,8,2,8,7,8,9,8,null,6,7,9,1,0,3,7,null,null,3,0,2,1,8,1,3,6,9,1,null,6,null,7,7,5,6,1,8,0,2,1,5,1,5,null,7,6,null,2,4,null,5,1,0,8,7,3,9,7,7,6,7,null,2,9,7,0,8,5,9,3,3,null,6,2,2,5,0,null,1,5,5,6,3,1,4,2,null,8,9,3,7,3,6,6,5,6,0,9,4,5,4,3,3,3,null,7,7,null,8,null,5,8,9,1,9,0,4,9,7,2,8,3,6,3,1,8,null,3,3,1,8,8,5,3,2,0,7,5,6,9,2,3,1,4,9,9,0,null,7,8,1,3,8,2,7,8,7,6,7,8,5,7,null,7,2,2,0,9,6,0,1,8,4,1,0,4,5,5,0,0,8,9,2,8,0,1,6,6,0,4,null,7,1,null,1,0,6,0,null,2,6,null,null,1,null,7,1,6,4,null,5,2,9,5,8,2,6,0,5,9,5,7,9,null,4,null,1,null,1,6,null,null,1,0,null,null,7,7,6,3,4,9,4,9,4,9,5,5,null,3,6,4,6,8,7,0,1,9,9,null,0,7,1,5,null,2,6,8,1,0,2,8,6,null,8,8,3,null,2,0,6,null,7,8,7,8,null,8,null,5,0,7,7,0,0,3,null,null,8,null,9,4,4,1,5,2,0,2,8,1,0,7,0,8,2,5,null,2,6,null,0,null,null,5,4,7,null,0,null,1,1,7,5,9,1,1,9,5,null,8,8,6,1,8,9,null,9,6,2,3,null,8,3,8,5,6,1,1,null,7,9,3,3,3,5,2,7,7,9,5,null,5,9,null,6,null,9,0,7,8,6,4,8,0,null,null,1,3,6,8,null,9,null,null,8,null,null,5,null,3,4,null,9,9,9,null,3,1,1,3,1,8,3,4,6,8,7,5,9,2,null,3,5,null,3,null,5,4,1,8,8,4,0,3,2,0,1,4,9,null,6,5,null,1,0,6,3,8,7,null,2,1,5,2,8,3,5,5,1,null,3,7,4,6,6,6,4,8,9,4,null,8,null,7,null,6,4,8,6,null,6,9,0,3,3,null,4,7,7,7,1,4,3,null,5,9,8,null,null,1,6,3,2,3,6,2,5,1,8,9,3,1,1,9,4,4,null,8,7,7,2,1,9,3,0,1,3,0,3,9,3,1,2,8,null,6,7,9,2,8,9,0,3,2,null,6,4,3,null,9,8,0,5,6,0,2,8,5,9,4,2,3,4,4,6,9,4,8,0,3,6,2,0,2,1,null,0,3,4,null,3,7,1,null,0,null,1,0,7,5,5,9,0,9,7,0,8,0,0,1,null,6,6,1,5,null,1,0,3,4,1,null,null,4,null,null,7,7,null,7,7,4,9,5,8,1,null,1,7,0,8,null,9,null,null,0,9,null,2,null,5,null,9,3,2,1,6,6,5,2,3,7,9,null,4,8,8,null,2,null,null,1,4,5,9,6,3,null,4,null,null,0,null,1,5,1,9,null,1,5,null,2,3,2,null,5,3,null,3,3,5,7,2,1,null,6,7,8,7,4,1,null,6,0,1,4,6,2,3,1,7,7,0,2,8,7,9,5,1,3,8,3,1,6,9,4,7,3,6,2,0,null,null,2,8,6,9,2,null,null,1,3,2,9,null,7,null,null,9,7,null,null,7,2,9,4,8,6,4,1,7,3,8,5,4,5,null,9,5,7,8,7,0,6,7,7,null,2,3,6,3,7,8,8,0,7,null,3,6,2,6,2,6,6,7,5,0,9,1,9,8,9,null,null,5,8,2,5,8,null,5,3,null,2,7,7,null,3,5,3,3,0,7,6,0,9,9,2,3,6,3,4,9,null,7,1,5,4,7,null,1,2,9,8,9,null,2,3,4,1,2,2,1,4,0,9,0,8,0,2,1,8,0,2,2,6,3,3,null,3,null,0,4,8,9,1,4,6,4,4,null,0,0,7,null,5,4,2,2,2,3,3,4,7,6,null,8,4,7,null,6,9,7,2,2,0,4,null,2,3,7,8,0,null,6,null,1,4,6,4,7,6,9,3,4,2,null,2,3,null,7,7,7,5,4,9,8,null,4,2,7,null,7,4,2,8,8,9,9,8,6,4,8,3,6,4,0,4,null,1,6,7,7,3,null,0,6,7,9,2,5,9,6,2,9,3,7,5,null,3,5,9,3,null,4,2,0,null,0,null,0,null,1,4,null,5,5,4,8,5,null,null,2,7,0,2,null,7,4,8,7,8,2,0,0,7,null,null,6,7,null,8,5,0,null,6,0,1,4,null,null,9,1,null,0,4,6,4,4,9,4,0,7,7,3,9,null,null,9,5,3,6,null,9,2,1,0,6,null,6,5,3,null,7,4,1,9,null,6,9,2,1,6,null,8,6,null,4,0,5,0,8,2,7,9,4,6,3,9,9,9,1,0,null,8,6,4,8,2,0,0,8,6,0,null,2,3,null,9,7,4,8,9,8,1,9,0,8,9,null,null,1,7,3,null,8,7,4,6,8,8,5,null,9,5,8,6,2,8,2,1,null,0,9,null,5,1,null,2,6,3,4,2,0,3,5,4,null,null,8,null,8,8,0,8,1,3,9,5,2,5,0,2,null,6,1,9,6,6,5,7,5,null,2,5,9,null,7,9,null,6,7,5,8,7,8,0,4,7,null,0,0,null,6,3,3,null,7,1,8,2,4,9,9,7,4,7,5,1,3,8,0,1,9,8,9,2,null,8,null,6,3,0,2,4,7,3,5,5,4,3,1,6,2,1,1,3,7,3,9,7,9,6,8,9,5,5,6,9,9,8,null,9,0,0,null,0,8,null,0,4,8,null,1,6,9,1,5,4,4,5,3,5,null,9,9,9,9,5,4,0,7,4,8,1,0,3,1,4,6,9,null,9,7,4,7,3,7,5,3,null,null,9,5,2,6,null,9,4,0,null,7,2,3,7,6,2,0,1,7,1,3,1,6,8,null,9,5,null,4,null,5,2,5,null,2,null,2,4,2,4,5,3,null,8,3,1,9,3,4,null,2,2,2,4,null,3,7,1,null,1,4,6,1,8,null,8,4,2,5,3,7,2,3,8,4,5,8,null,3,1,null,0,4,4,0,6,3,1,0,2,9,9,3,null,8,0,6,4,1,2,1,5,1,6,7,9,null,4,6,1,8,6,3,9,null,3,2,2,6,0,6,2,0,0,6,5,1,9,7,2,3,null,4,1,1,7,8,2,1,null,9,4,null,null,7,7,5,2,9,9,5,0,8,1,6,7,0,2,1,null,0,9,4,6,null,null,8,5,6,6,4,2,null,8,2,null,7,4,null,null,null,null,3,6,null,0,null,5,null,1,8,1,0,5,6,5,6,0,0,7,2,null,7,null,8,9,0,8,8,9,null,2,8,2,9,3,null,null,3,1,4,0,6,3,null,4,null,8,7,7,null,7,0,5,1,0,7,9,8,2,7,8,1,0,6,5,0,5,null,3,5,2,null,null,6,null,1,3,null,5,2,8,5,9,2,5,3,6,null,6,0,null,5,1,0,8,2,0,7,0,8,2,6,null,4,0,5,null,7,4,4,5,6,1,5,4,4,9,0,0,9,2,4,1,2,9,6,0,0,9,1,7,2,4,9,4,0,7,4,3,2,5,1,0,8,null,1,2,null,1,8,9,8,8,2,9,5,0,3,0,4,6,8,null,5,2,5,7,9,2,4,4,0,1,8,null,5,9,8,0,null,2,7,8,9,7,null,7,8,null,null,4,null,9,2,1,1,0,1,6,5,8,3,5,8,7,9,2,5,1,4,6,null,6,0,4,9,8,0,8,4,6,1,8,4,3,null,4,5,6,null,2,null,9,8,7,7,1,9,8,8,6,0,1,6,6,3,1,6,1,0,2,null,1,5,0,8,null,7,null,4,5,7,null,8,null,1,9,7,2,2,null,0,7,6,1,null,1,null,4,1,0,5,1,3,5,5,1,2,9,5,null,9,6,5,1,1,8,2,2,4,null,6,8,null,6,4,0,null,5,0,3,3,1,7,1,3,3,8,7,null,9,0,null,9,3,9,null,null,7,null,3,0,3,null,7,null,1,6,null,6,null,1,3,9,7,1,1,4,5,9,8,9,6,1,0,null,8,3,4,2,5,6,4,null,2,null,2,2,9,2,4,1,7,9,2,2,0,0,5,null,0,7,9,null,2,null,null,0,null,6,9,null,8,5,4,null,null,8,5,2,null,null,2,0,null,1,8,7,null,9,6,3,0,9,7,8,5,1,4,8,7,8,0,null,0,7,5,8,2,null,8,2,4,4,null,5,0,1,8,7,3,9,6,2,5,5,1,3,3,8,3,1,2,4,null,0,8,3,7,2,null,null,1,7,0,0,6,4,2,0,6,6,4,7,7,6,2,1,1,6,2,7,8,null,9,null,9,0,9,7,5,4,2,6,null,1,0,4,8,6,5,0,9,8,9,3,3,null,8,2,3,5,null,1,6,6,3,8,5,null,1,3,5,5,6,2,0,3,null,6,4,7,null,3,2,3,9,5,0,7,9,3,7,3,8,4,2,null,9,4,6,null,7,6,8,3,6,0,6,null,9,5,null,null,1,1,5,2,8,4,1,0,1,4,5,7,4,6,4,null,0,7,null,9,null,4,0,9,5,4,2,1,2,null,5,4,null,null,8,6,8,6,null,3,6,9,8,3,2,0,3,2,5,9,null,null,1,null,6,0,0,5,9,2,4,null,2,3,3,5,4,6,null,4,8,null,2,5,0,null,null,1,null,5,2,null,8,9,2,7,1,4,3,6,6,9,7,7,null,9,null,7,null,5,9,0,5,7,4,8,4,2,4,6,8,1,null,8,5,null,3,7,7,9,5,3,null,null,1,0,1,8,6,3,2,1,8,null,0,3,6,3,1,7,9,9,1,2,5,0,7,1,7,6,9,8,7,2,4,0,3,7,5,4,9,6,null,0,8,2,3,5,null,4,1,7,5,7,7,8,7,9,null,7,3,null,1,2,6,5,8,9,2,3,8,0,0,9,null,4,0,3,3,null,4,6,0,null,4,5,7,5,8,2,0,null,7,1,null,2,5,3,8,9,8,5,0,null,8,null,null,9,5,7,null,7,null,3,2,8,0,null,9,1,1,5,2,7,0,null,0,5,0,5,null,4,8,7,0,2,8,4,0,8,5,4,9,0,null,4,8,4,3,4,2,9,5,null,3,null,2,3,null,3,null,8,3,5,1,1,3,5,8,9,null,1,1,4,9,null,3,7,1,null,5,4,8,1,4,9,0,3,2,null,6,null,3,null,4,3,4,2,4,5,5,4,6,1,4,0,4,1,0,3,5,1,5,3,9,8,7,3,1,2,null,0,7,4,9,7,8,7,null,1,0,9,8,6,0,7,0,3,3,7,0,9,1,5,9,5,2,4,0,6,0,4,4,5,null,0,9,7,1,7,8,8,6,3,9,null,0,5,5,5,7,6,9,null,8,6,9,null,9,4,5,0,null,2,2,null,4,9,2,1,null,6,5,8,2,8,6,8,5,8,2,null,0,null,7,7,8,3,0,4,null,3,7,null,0,9,1,5,6,9,6,3,6,1,5,0,null,4,7,0,0,9,0,3,7,1,9,0,null,9,1,6,null,3,0,1,null,0,null,4,0,8,3,3,8,3,1,8,9,7,6,9,0,4,6,1,9,6,6,1,3,2,4,5,null,null,5,null,5,8,null,3,7,6,5,6,0,0,3,7,9,3,9,null,0,2,3,8,4,null,0,3,6,6,8,null,1,6,0,9,4,2,7,9,0,1,null,0,5,8,6,5,null,5,7,3,0,2,7,0,9,null,5,1,4,1,2,null,6,2,4,3,1,1,4,5,4,null,5,6,4,0,0,5,6,8,9,0,9,9,7,3,8,4,5,4,null,null,8,0,null,5,3,8,8,null,null,1,4,null,null,4,5,6,0,0,1,0,null,8,5,null,0,6,6,null,6,6,4,2,6,null,2,0,1,2,1,6,3,4,5,3,null,1,0,3,8,0,4,5,8,null,null,5,2,9,9,9,7,4,1,5,null,0,5,5,0,0,1,null,9,null,2,null,null,0,2,null,2,4,1,9,3,1,5,3,3,5,3,8,9,3,9,7,9,null,null,6,2,1,1,null,5,6,5,4,7,4,null,1,4,null,2,9,null,9,0,6,8,7,null,6,null,8,5,null,0,0,0,1,4,null,8,null,null,9,null,8,7,1,6,5,6,null,6,7,1,null,7,4,null,null,5,2,null,0,9,8,null,6,2,4,null,null,null,5,0,null,9,1,9,8,9,8,4,null,8,1,5,null,null,7,0,4,6,2,6,6,7,null,0,7,5,0,2,9,7,8,null,1,6,7,9,5,0,4,6,9,6,4,3,2,6,2,8,6,7,2,9,7,2,9,9,8,5,5,0,2,5,9,4,0,1,7,2,5,null,6,4,4,7,6,4,1,0,8,7,5,7,3,1,1,4,1,null,4,1,8,4,null,0,5,2,3,3,9,7,9,8,null,null,3,null,9,6,2,7,0,1,null,8,null,null,3,1,0,4,0,8,9,9,8,2,0,null,8,7,5,null,null,6,3,null,0,4,0,4,1,8,1,9,9,0,8,8,6,null,8,1,6,4,5,0,2,0,1,4,7,5,3,6,7,null,3,6,4,7,4,6,6,7,8,6,1,3,null,null,9,2,3,4,9,3,null,8,2,6,7,2,9,7,null,null,8,2,6,9,8,9,1,9,7,0,null,2,1,null,2,3,null,0,7,8,1,6,7,1,7,4,null,7,null,1,1,9,3,9,5,1,2,3,2,7,null,null,1,3,0,8,6,6,2,2,9,1,4,8,6,9,null,1,9,2,3,2,0,3,8,null,6,0,4,0,4,null,null,1,4,9,8,7,null,3,2,2,9,8,2,5,2,9,5,7,null,9,8,null,9,3,8,0,null,3,9,6,8,8,8,3,null,null,4,6,6,2,9,3,5,6,4,7,3,7,0,3,3,8,null,null,null,4,6,3,3,4,0,6,2,3,0,null,7,6,1,8,1,null,null,0,null,null,9,7,8,1,3,null,1,4,2,8,7,8,8,6,null,null,3,1,2,8,1,4,8,8,9,null,0,7,null,1,0,6,5,7,null,8,7,8,4,7,4,6,3,3,8,3,2,0,6,2,8,null,9,0,7,4,null,5,9,5,8,5,9,8,3,8,null,null,9,4,2,9,6,2,1,2,null,null,5,1,0,2,6,7,6,3,null,5,6,8,3,6,9,9,7,null,7,0,1,9,4,7,0,1,3,0,4,9,8,0,2,4,9,2,2,3,8,2,0,4,3,null,7,9,1,3,4,8,null,2,null,5,6,3,5,5,5,5,7,null,null,3,1,7,4,1,null,5,5,1,8,7,8,3,0,0,1,5,1,5,5,2,0,1,1,3,null,7,4,4,8,9,null,8,null,7,9,5,1,null,0,9,2,4,null,0,1,5,9,0,0,6,1,0,0,2,null,null,5,9,null,6,8,1,6,1,2,9,null,2,2,9,4,9,5,8,6,4,7,9,4,9,3,null,2,null,4,4,8,4,4,0,8,2,3,0,5,2,2,7,4,7,1,null,8,0,6,6,8,2,6,null,8,4,3,1,7,null,7,2,2,2,8,9,2,1,null,2,9,8,0,6,null,null,2,8,5,7,2,1,8,5,4,1,4,1,9,0,3,1,0,8,3,2,4,8,3,6,4,0,5,3,8,2,5,8,8,3,9,null,9,null,2,9,1,null,7,null,7,1,8,8,4,5,7,5,2,null,3,null,4,7,0,5,0,3,0,4,8,3,null,0,6,9,7,9,null,4,9,4,null,0,5,2,4,null,9,3,0,5,3,2,3,8,3,7,9,1,0,2,4,6,2,0,2,8,3,5,2,3,4,8,4,0,6,null,null,5,null,4,null,3,null,2,2,9,9,null,6,0,null,8,0,9,null,4,2,9,4,2,2,0,3,0,1,8,8,3,null,4,7,8,4,null,9,8,null,8,9,4,4,3,2,5,2,null,5,4,6,0,4,null,2,7,null,1,5,9,2,6,null,4,8,null,3,4,7,8,9,null,null,1,null,4,null,6,4,null,7,7,0,7,4,8,7,4,2,0,8,2,0,0,8,6,7,7,7,7,5,3,null,6,6,5,null,null,4,9,4,null,3,9,null,2,7,5,null,null,1,9,8,0,4,4,5,8,1,4,7,9,2,1,9,9,8,8,5,null,5,1,3,9,null,2,4,0,3,2,0,3,3,null,6,6,null,8,null,2,5,5,7,5,1,null,4,5,0,7,1,9,null,3,null,2,4,8,1,6,0,9,3,4,9,null,4,4,6,2,0,null,7,7,0,9,7,null,null,6,5,8,null,3,8,1,0,2,9,0,3,9,3,6,1,3,0,null,5,2,9,4,null,5,8,6,null,null,1,8,6,null,0,5,0,5,null,1,null,7,8,3,null,1,7,1,4,3,3,9,0,2,3,9,9,6,null,2,4,2,2,6,8,7,null,8,null,9,9,5,7,3,9,null,null,1,2,4,1,0,9,7,7,9,7,5,4,2,8,1,null,4,2,5,8,2,2,9,3,1,2,3,1,0,8,5,6,null,2,0,2,9,7,8,4,null,6,8,1,6,null,6,7,0,0,9,8,8,8,1,null,5,5,2,9,4,3,3,1,0,5,1,7,3,3,5,7,1,8,4,2,5,7,2,4,null,4,0,7,0,9,6,5,null,0,null,3,1,4,9,null,null,4,1,6,2,2,1,5,3,8,7,5,6,6,9,4,6,9,3,1,6,7,null,null,null,null,6,null,9,3,2,6,3,null,8,3,0,null,9,6,8,2,2,null,4,4,null,3,3,2,null,3,6,null,5,5,4,3,7,1,8,null,null,2,8,null,5,4,3,9,null,6,null,6,4,4,6,9,7,3,3,1,2,8,7,2,6,8,7,8,7,null,4,9,3,null,7,5,5,8,4,7,2,7,2,8,3,8,1,2,null,5,null,1,9,2,9,0,9,9,9,null,7,3,8,7,8,1,2,7,4,6,4,3,4,7,9,5,8,0,3,null,8,3,3,5,9,null,7,1,4,2,6,0,6,6,3,8,5,0,null,2,6,null,7,null,0,null,null,6,7,null,6,4,7,5,5,7,9,4,0,null,1,4,0,null,5,4,8,7,null,2,1,9,0,9,6,5,9,7,8,0,6,0,null,0,7,9,9,null,null,7,5,5,9,4,1,8,3,1,3,3,0,1,4,0,null,null,1,9,9,1,3,7,null,6,1,8,6,null,1,2,9,4,3,null,6,3,4,6,null,9,7,6,7,8,1,6,3,6,8,3,null,6,1,7,2,7,1,2,5,2,1,5,2,null,5,9,1,2,3,8,6,5,3,7,5,0,null,3,1,null,2,null,2,null,7,7,5,6,null,1,5,4,2,null,null,null,1,9,6,0,null,7,3,1,7,8,1,8,0,8,3,null,1,3,8,2,2,4,4,9,null,5,9,0,6,4,null,3,0,7,6,2,null,0,1,4,7,7,3,6,null,1,4,null,7,9,4,null,6,1,2,1,8,8,8,1,0,7,2,null,9,5,1,7,0,9,2,0,null,1,null,1,null,3,8,8,5,null,null,null,0,6,1,1,9,8,2,1,null,6,8,0,0,null,7,0,9,5,2,7,5,null,2,null,8,8,7,7,9,null,9,8,5,6,9,9,7,9,null,null,1,null,6,6,null,2,3,6,7,2,null,1,1,7,4,null,6,1,2,null,6,8,6,null,3,3,3,0,null,7,4,5,7,8,3,6,5,9,5,9,7,0,3,5,5,2,6,null,9,8,2,5,9,5,3,5,9,0,4,2,5,8,2,9,null,null,5,3,0,7,4,7,7,null,6,4,9,0,0,0,6,4,1,null,5,8,4,4,8,null,7,null,4,3,1,1,9,null,1,1,1,7,null,4,null,0,null,4,6,9,7,5,7,null,null,5,6,6,6,3,null,6,2,8,9,6,2,8,0,9,null,5,3,8,8,null,5,9,5,1,3,4,null,null,3,5,null,9,2,0,9,3,null,3,null,1,8,5,8,7,6,5,null,6,1,5,3,null,7,5,null,8,3,0,3,9,9,null,null,9,4,null,9,0,null,7,0,8,5,7,5,null,5,null,5,8,null,0,null,null,2,2,8,5,6,3,2,8,9,7,0,2,2,null,1,6,8,8,0,null,1,6,8,5,2,0,8,7,5,null,7,1,8,9,4,8,3,8,3,4,null,4,2,1,8,5,3,0,9,1,null,null,2,6,3,8,null,1,0,1,8,0,2,3,1,null,null,null,8,0,2,6,0,null,4,6,9,7,9,2,null,null,null,9,2,7,5,8,null,6,3,9,9,5,6,5,0,6,1,6,6,7,7,9,7,9,7,2,0,5,1,7,8,1,9,5,5,9,7,1,4,3,6,0,9,4,1,6,5,2,8,8,2,6,6,1,null,7,0,5,7,1,9,3,4,9,9,6,3,5,null,7,6,0,3,1,1,8,8,8,6,6,1,8,9,1,3,1,8,5,3,7,1,3,8,8,7,6,3,null,null,2,4,null,4,0,2,9,0,7,8,5,8,7,6,3,6,4,null,5,4,0,null,5,8,8,3,9,null,9,2,1,3,9,2,5,9,3,8,null,1,6,9,null,1,4,2,6,1,7,null,7,1,null,2,7,4,7,6,0,6,null,2,8,6,null,null,2,2,5,3,8,null,7,7,2,1,6,null,7,5,null,0,6,7,8,null,7,7,8,null,2,7,9,null,9,1,2,8,3,0,4,8,null,4,3,9,1,null,9,5,8,5,null,0,9,9,0,5,7,3,null,2,8,3,null,7,1,null,7,9,8,8,9,2,6,8,3,0,6,6,2,3,5,5,1,3,0,0,2,2,4,5,4,null,0,null,0,2,null,9,null,4,7,3,9,7,8,null,8,9,1,2,8,6,5,2,7,6,0,null,null,7,null,5,null,8,2,9,5,3,5,7,4,6,3,4,null,3,9,5,null,null,4,6,0,4,2,3,7,2,4,2,3,8,6,9,2,0,3,0,3,null,1,9,0,null,7,2,6,7,1,null,3,3,8,9,6,null,3,2,null,3,1,0,null,null,2,null,1,0,null,1,0,null,0,5,7,1,9,9,2,5,9,7,null,2,8,3,0,0,8,9,1,9,1,4,8,null,5,2,4,6,9,0,7,null,2,1,7,null,null,4,9,0,0,null,2,6,5,4,8,null,9,null,8,1,1,0,0,2,7,3,null,7,null,2,4,6,8,0,4,8,2,6,4,8,null,3,7,4,6,7,null,3,2,null,8,5,5,4,null,8,4,5,7,2,1,4,8,0,3,5,0,7,0,null,8,null,0,5,2,null,8,5,4,null,3,6,9,null,8,8,4,0,1,1,6,2,2,5,null,3,8,null,2,null,0,null,5,6,9,5,9,null,8,9,7,5,2,8,2,3,6,6,null,6,0,3,7,9,2,6,4,0,2,0,4,null,9,7,6,4,null,7,8,null,3,2,8,9,1,null,4,3,8,8,4,0,7,null,1,5,7,4,6,null,6,3,1,1,6,null,8,1,7,8,2,4,5,6,6,6,null,3,null,3,8,1,9,null,0,5,0,5,3,8,5,0,7,9,5,0,3,7,1,6,6,4,3,5,5,9,null,1,0,9,6,3,9,3,null,2,8,2,7,5,3,7,null,7,2,0,1,7,6,9,8,0,null,6,null,3,null,3,0,1,4,7,3,0,null,0,0,8,0,0,9,3,0,4,5,0,6,0,0,0,4,4,6,1,8,4,8,7,5,8,5,6,2,null,4,0,0,7,7,null,3,9,8,3,9,3,5,1,9,7,8,8,5,7,4,null,4,5,6,0,6,1,9,1,6,0,5,2,4,2,null,2,5,3,3,4,7,3,7,7,0,0,8,6,3,6,null,null,9,2,7,2,4,7,8,1,null,2,8,4,4,9,1,9,8,null,7,2,4,0,0,1,1,null,4,8,9,null,5,2,null,5,2,9,1,7,8,5,7,3,1,null,5,7,2,0,3,2,7,6,8,5,null,4,2,4,null,0,9,null,3,5,3,7,4,null,9,null,1,9,null,8,3,7,5,1,3,2,6,3,null,8,6,9,8,null,7,1,8,7,7,4,5,4,9,null,4,5,3,0,4,9,null,5,5,5,0,9,null,5,6,8,6,2,2,null,9,0,6,2,4,2,0,7,6,1,9,null,null,8,6,2,8,7,3,null,4,4,7,9,7,6,6,null,7,3,5,8,null,null,7,7,null,8,null,9,0,8,6,0,1,3,8,2,6,4,5,7,6,5,3,4,8,8,7,2,null,6,1,4,0,2,6,1,9,7,2,4,0,8,7,4,7,3,4,6,3,9,4,4,1,4,6,6,5,7,7,null,3,7,null,4,5,1,1,9,6,8,1,6,1,2,6,7,9,3,null,0,8,6,null,null,6,4,2,2,3,9,6,1,3,null,2,0,null,2,6,null,5,9,9,null,1,7,0,4,7,null,2,null,0,5,7,8,0,9,7,null,8,7,8,3,1,4,3,null,4,7,1,8,4,8,2,3,2,3,2,3,3,8,9,7,3,5,7,7,3,null,3,4,5,2,0,4,null,5,4,8,4,8,0,9,null,1,9,3,3,null,3,null,null,9,null,6,1,7,3,4,null,0,2,6,7,3,8,null,1,null,5,8,9,null,5,0,4,5,4,1,8,1,2,6,2,0,4,9,6,0,2,5,8,0,null,6,null,3,5,1,6,3,9,7,8,8,4,4,null,0,0,0,7,5,null,null,6,3,5,4,5,6,4,7,null,4,1,7,3,9,null,null,5,0,null,9,4,null,4,5,6,6,6,2,null,7,6,3,1,3,null,0,5,9,6,null,7,3,2,3,1,6,6,null,3,4,1,7,4,7,2,2,0,6,1,2,2,3,4,6,8,null,2,2,3,null,null,6,3,7,3,9,null,8,3,4,1,0,0,5,4,9,8,5,5,8,9,0,2,2,3,7,0,3,7,8,0,8,4,2,null,8,6,null,null,0,3,5,6,9,9,1,9,null,1,1,null,9,null,0,3,2,null,7,7,8,7,4,7,9,6,7,0,8,8,1,null,4,2,9,3,null,null,2,5,7,6,3,7,null,3,6,0,2,0,7,7,5,0,0,null,1,9,5,2,8,2,5,4,0,1,3,4,0,null,null,2,4,2,2,null,5,9,2,3,9,8,null,9,null,4,null,4,2,4,3,1,6,6,1,0,null,6,1,2,null,2,5,2,3,5,2,null,null,3,null,4,8,3,null,8,6,1,0,0,5,3,3,null,null,6,3,9,6,8,1,3,6,5,null,3,4,5,8,1,5,9,7,7,4,3,null,2,null,null,4,3,0,9,1,4,3,2,1,2,2,5,5,1,5,8,3,7,3,null,7,2,null,7,0,9,7,5,1,9,5,4,7,null,5,5,3,3,null,2,6,null,5,0,9,7,4,6,0,4,3,3,null,5,8,1,9,9,4,6,9,5,9,null,9,4,8,9,null,null,2,8,6,0,null,3,null,0,2,5,null,2,5,8,5,null,null,0,0,8,null,9,9,0,0,9,null,5,4,0,2,3,1,9,2,2,5,1,6,3,1,5,null,8,9,4,0,5,null,3,4,1,2,0,null,5,4,8,1,5,null,null,7,9,3,6,6,0,9,5,2,6,2,null,2,1,7,null,1,6,4,0,0,0,4,0,8,4,9,8,9,null,2,6,6,7,4,1,3,4,null,9,6,9,7,null,0,2,5,0,1,3,4,1,1,8,3,1,9,6,6,null,8,6,0,5,5,2,8,9,null,0,8,3,5,8,7,null,7,null,null,7,5,2,5,null,0,3,null,2,2,1,null,3,2,2,9,3,6,null,0,6,0,null,null,2,0,9,3,null,3,4,null,7,7,8,null,6,0,6,6,null,8,0,null,0,3,1,3,7,0,5,0,0,6,null,2,3,8,0,0,7,2,2,7,7,5,0,1,null,3,4,3,4,1,3,4,2,null,8,null,7,4,3,6,9,4,1,0,0,5,2,null,8,8,9,8,3,null,7,0,2,2,5,1,4,9,null,6,2,5,6,0,2,7,9,9,1,null,5,3,null,7,7,6,4,1,3,7,1,6,0,7,9,3,8,3,null,7,2,5,6,1,0,4,5,6,null,9,0,3,0,null,null,null,1,null,5,0,6,1,5,6,1,3,0,4,1,2,5,6,null,1,2,6,4,null,null,3,4,5,7,3,null,4,3,null,2,0,4,7,6,2,0,3,null,8,8,2,9,4,7,5,8,0,3,null,null,6,1,6,null,3,2,1,null,3,3,9,3,9,null,7,9,6,8,7,1,6,null,3,8,3,0,2,4,5,2,0,5,9,5,9,0,7,2,7,5,5,5,7,4,8,6,1,6,null,null,7,null,2,2,6,4,null,null,4,7,null,7,3,2,3,9,0,4,2,0,9,5,2,2,9,0,null,2,2,3,null,8,7,null,7,8,6,1,7,2,null,9,3,1,1,2,null,6,7,5,5,8,null,0,4,2,0,5,5,0,6,5,9,1,null,9,4,1,8,null,7,6,6,7,5,1,8,7,9,0,6,1,4,null,7,1,5,4,1,4,4,3,null,9,8,9,null,1,5,3,3,7,null,5,4,3,7,8,2,4,8,null,4,null,null,8,null,1,null,0,3,1,3,4,4,7,9,0,1,5,null,9,null,6,8,7,null,4,null,1,null,8,6,0,7,4,3,5,9,1,0,8,2,9,7,null,1,5,8,5,8,9,5,8,null,null,4,5,4,0,9,9,0,8,5,2,9,2,0,null,4,7,7,8,1,9,6,null,3,4,4,1,7,9,8,0,8,null,5,3,3,6,5,7,null,null,0,6,9,1,2,8,6,9,0,5,2,3,8,9,8,0,3,3,0,1,4,null,9,0,1,3,6,2,6,0,null,0,9,3,9,3,3,3,5,1,null,null,1,1,7,null,null,8,3,null,null,9,5,6,6,7,7,0,2,null,6,7,9,4,8,9,2,null,4,8,6,4,null,5,8,8,3,9,8,7,9,null,2,9,2,9,1,1,3,0,6,7,3,4,2,9,null,6,null,4,null,2,8,2,3,4,1,3,0,null,4,7,8,4,8,null,6,3,3,7,0,null,3,9,3,1,1,2,0,2,6,4,8,9,0,8,7,1,1,6,4,0,3,0,2,7,0,null,1,null,null,null,9,0,null,null,7,8,2,null,5,5,8,null,3,5,2,2,2,5,3,7,7,5,8,8,1,4,null,null,7,9,7,2,4,7,7,6,8,null,1,6,3,2,9,7,1,2,7,0,2,9,9,9,9,8,null,7,null,4,8,7,0,null,9,3,3,null,7,1,null,null,9,5,8,8,4,7,4,9,5,5,1,null,0,6,6,8,7,8,null,null,null,3,4,6,5,1,0,null,null,1,5,1,3,null,3,4,6,4,8,2,2,2,null,2,5,1,6,null,6,5,null,1,4,2,2,2,7,8,2,7,4,0,2,3,3,null,7,0,null,7,9,6,0,null,2,8,4,8,5,2,3,6,8,2,2,6,1,8,5,4,6,2,4,0,0,4,9,7,7,null,1,1,null,6,6,6,4,1,null,3,4,null,5,0,8,8,1,8,3,2,9,6,2,6,9,5,9,8,5,1,0,7,7,null,8,9,0,8,8,null,6,3,6,6,9,8,1,4,1,5,5,0,7,7,0,9,9,1,5,3,5,6,null,null,null,4,null,0,4,null,2,6,5,1,4,6,1,5,4,6,7,4,2,6,7,0,4,3,null,8,4,8,7,9,4,0,5,6,3,7,1,9,3,null,7,3,4,9,0,0,3,2,0,6,6,0,6,5,0,8,3,1,2,4,8,3,6,null,3,1,7,3,7,0,7,2,2,5,2,8,8,5,8,9,3,7,9,9,8,6,6,5,8,null,8,null,5,7,1,0,4,9,5,2,8,null,1,0,4,7,2,3,2,2,5,0,4,5,0,3,null,7,0,7,2,3,null,null,1,5,0,5,5,8,4,4,2,7,2,1,0,5,8,2,5,4,null,3,5,2,7,0,0,0,8,2,5,6,0,4,0,3,8,4,null,1,2,8,null,4,2,8,3,2,1,2,4,6,null,4,4,null,1,4,5,0,9,2,3,null,null,3,2,3,3,0,8,3,3,3,3,1,6,2,3,4,4,2,3,null,6,7,3,9,9,5,1,0,2,3,4,8,5,1,5,3,0,null,4,3,7,null,0,1,7,null,4,5,null,9,5,9,null,3,5,5,7,7,8,0,0,8,7,9,9,9,4,9,5,3,null,5,7,4,null,1,null,7,null,1,null,3,6,9,null,4,4,1,null,2,0,6,9,2,9,1,8,3,9,0,2,6,8,1,null,6,4,4,2,5,0,1,0,9,4,6,4,8,8,null,1,null,3,5,0,0,4,0,5,5,4,5,4,0,8,9,4,2,3,1,null,null,null,3,4,1,0,2,2,1,null,null,0,6,0,2,5,2,null,2,3,4,0,null,1,0,9,2,2,6,8,null,8,null,6,9,2,null,2,9,5,3,null,8,2,9,7,6,null,2,3,9,null,6,9,7,3,7,null,6,5,9,8,5,5,4,7,5,2,null,4,3,8,8,8,7,9,4,5,6,1,0,null,9,1,5,2,0,null,9,2,3,5,1,5,1,1,7,3,0,0,9,7,9,0,8,6,9,2,7,0,null,2,8,8,9,3,4,8,9,2,9,7,null,null,2,2,null,4,7,3,8,3,3,5,null,5,3,9,2,7,3,3,7,null,null,3,9,1,3,null,8,1,4,0,7,6,null,4,8,8,4,7,null,3,6,9,4,9,7,9,8,null,null,2,1,8,3,8,2,0,0,9,5,2,null,9,5,7,1,null,3,8,null,5,6,5,2,1,4,2,9,9,2,8,5,7,6,0,4,0,3,6,2]";
    TreeNode *eg2_t = stringToTreeNode(eg2);
    prettyPrintTree(eg2_t);
    // cout << treeNodeToString(test2.deserialize(eg2));
    cout << treeNodeToString(test2.deserialize(test2.serialize(stringToTreeNode(eg2))));
}


//
// Created by ASUS on 2025/2/20.
//
