#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    unordered_map<int,Node*> last;
    void dfs(Node* root,int lvl){
        //cout << lvl << " --- " << endl;
        if (last[lvl] == nullptr){
            //cout << " test " << endl;
            last[lvl] = root;
        } else {
            last[lvl]->next = root;
            last[lvl] = root;
        }
        if (root->left) {
            dfs(root->left,lvl + 1);
        }
        if (root->right) {
            dfs(root->right,lvl + 1);
        }
    }
    Node* connect(Node* root) {
        if (not root) {
            return root;
        }
        //cout << "1" << endl;
        dfs(root,0);
        //cout << "2" << endl;
        return root;
    }
};
int main(){
    Solution test;

    Node node7(7, nullptr, nullptr, nullptr);
    Node node3(3, nullptr, &node7, nullptr);
    //Node node1(0, nullptr, nullptr, nullptr);
    Node node4(4, nullptr, nullptr, nullptr);
    Node node5(5, nullptr, nullptr, nullptr);
    Node node2(2, &node4, &node5, nullptr);
    Node node1(1,&node2,&node3, nullptr);

//    unordered_map<int,Node*> test2;
//    cout << test2[0]->val << endl;
    Node* ans = test.connect(&node1);
    cout << ans->left->next->val << " + + " << endl;
    cout << ans->left->left->next->val << " + + " << endl;
}
//
// Created by ASUS on 2023/6/28.
//
