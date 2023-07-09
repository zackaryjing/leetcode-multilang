#include <vector>
#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> ans;
    void dfs(Node* root){
        for (auto i : root->children){
            ans.push_back(i->val);
            if (!(i->children.empty())){
                dfs(i);
            }
        }
    }
    vector<int> preorder(Node* root) {
        if (root){
            ans.push_back(root->val);
            if (!root->children.empty()){
                dfs(root);
            }
        }
        return ans;
    }
};
int main(){

}
//
// Created by ASUS on 2023/6/14.
//
