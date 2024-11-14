#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
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
    TreeNode* Build(int start,int end,vector<int>& source){
        // cout << start << " " << end << endl;
        if (start == end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        return new TreeNode (source[mid], Build(start,mid,source),Build(mid + 1,end,source));
        //return &tmp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int length = nums.size();
        TreeNode* root = Build(0,length,nums);
        return root;

    }
};


int main(){

}
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        // cout << "here" << endl;
//    }
//};
//
// Created by ASUS on 2023/6/21.
//
