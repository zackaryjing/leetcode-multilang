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

class Solution2 {
public:
    ListNode* begin,*mid;
    void dfs(ListNode* head,int isodd){
        cout << head->val << endl;
        if (isodd) mid = mid->next;
        if (head->next){
            dfs(head->next,~isodd);
        }
        if (begin == mid){
//            if (begin == head){
//                mid->next = nullptr;
//            } else {
////                mid->next->next = nullptr;
//            }
            cout << "begin " << begin->val << " mid " << mid->val << " head " <<head->val << endl;
            mid->next = nullptr;
            cout << "in the mid" << endl;
            return;
        }
        cout << "this is begin " << begin->val << " " << head->val <<  " " << mid->val << endl;
        head->next = begin->next;
        begin->next = head;
        begin = head->next;
        cout << "the next of begin is " << begin->next->val << endl;
        cout << "the next of head is " << head->next->val << endl;
    }
    void reorderList(ListNode* head) {
        begin = head;
        mid = head;
        dfs(head,0);
    }
};

class Solution {
public:
    ListNode* last,*mid;
    void dfs(ListNode* from,int isodd){
        if (isodd){
            mid = mid->next;
        }
        if (from->next){
            dfs(from->next,~isodd);
        }
        if (last == mid){
//            cout << mid->val << " " << from->val << " " << last->val << endl;
//            cout << " THIS IS FUCKING MID " << mid->val << endl;
//            cout << " AND THIS IS FUCKING MID NEXT " << mid->next->val << endl;
            mid->next = nullptr;
            return;
        }
        from->next = last->next;
        last->next = from;
        last = from->next;
    }
    void reorderList(ListNode* head) {
        last = head,mid = head;
        dfs(head,0);
    }
};

int main(){
    Solution test;
    ListNode n6(6);
    ListNode n5(5,&n6);
    ListNode n4(4,&n5);
    ListNode n3(3,&n4);
    ListNode n2(2,&n3);
    ListNode n1(1,&n2);
    test.reorderList(&n1);
    cout << "end" << endl;
    ListNode * cur = &n1;
    cout << cur->val << " " << cur->next->val << " " << cur->next->next->val << endl;
    while (cur){
        cout << cur->val << " " ;
        cur = cur->next;
    }
}
//
// Created by ASUS on 2023/7/26.
//
