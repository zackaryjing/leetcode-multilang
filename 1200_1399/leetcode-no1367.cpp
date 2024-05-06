#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool search(TreeNode* root,ListNode* head){
        bool leftres = false,rightres = false;
        if (root->val == head->val){
            if (root->left and head->next){
                leftres =  search(root->left,head->next);
            }
            if (root->right and head->next){
                rightres = search(root->right,head->next);
            }
            if (not head->next) {
                return true;
            }
        } else {
            return false;
        }
        return (leftres or rightres);
    }
    bool ans = false;
    bool isSubPath(ListNode* head, TreeNode* root) {
//        cout << head->val << " + + " << root->val << endl;
        if (ans) {
            return ans;
        }
        if (root->val == head->val){
            bool tmp = search(root,head);
//            cout << tmp << endl;
            if (tmp) {
                ans = true;
            }
        }
        if (root->left) {
            isSubPath(head,root->left);
        }
        if (root->right) {
            isSubPath(head,root->right);
        }
        return ans;
    }
};

int main(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(1);
    TreeNode* node7 = new TreeNode(6);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(1);
    TreeNode* node10 = new TreeNode(3);
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(8);
    n1->next = n2;
    n2->next = n3;
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->left = node5;
    node4->left = node6;
    node5->left = node7;
    node5->right = node8;
    node8->left = node9;
    node8->right = node10;

    Solution test;
    cout << test.search(node3,n1) << endl;
    cout << string(30,'-') << endl;
    cout << test.isSubPath(n1,node1) << " ans" << endl; // expect true
    cout << string(30,'-') << endl;
    Solution test2;
    cout << test2.isSubPath(n2,node5) << " ans" << endl; // expect true
    cout << string(30,'-') << endl;
    Solution test3;
    cout << test3.isSubPath(n1,node5) << " ans" << endl; // expect false
    cout << string(30,'-') << endl;
    Solution test4;
    cout << test4.isSubPath(n3,node10) << " ans" << endl; // expect false
    cout << string(30,'-') << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
    delete node9;
    delete node10;
}


//
// Created by ASUS on 2023/7/17.
//
