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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while (dummy->next){
//            cout << head->val << endl;
            if (dummy->next->val == val){
                dummy->next = dummy->next->next;
            } else {
                dummy = dummy->next;
            }
        }
        return p->next;
    }
};

int main(){
    Solution test;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next= new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next= new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    ListNode* ans = test.removeElements(head,6);
    while (ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
}
//
// Created by ASUS on 2023/7/28.
//
