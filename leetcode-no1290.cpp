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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head){
            if (head->val == 1) ans = ans * 2 + 1;
            else ans *= 2;
            head = head->next;
        }
        return ans;
    }
};

int main() {
    Solution test;
    ListNode node1(0);
    ListNode node2(0,&node1);
    ListNode node3(0,&node2);
    ListNode node4(0,&node3);
    ListNode node5(0,&node4);
    ListNode node6(0,&node5);
    ListNode node7(1,&node6);
    ListNode node8(1,&node7);
    ListNode node9(1,&node8);
    ListNode node10(0,&node9);
    ListNode node11(0,&node10);
    ListNode node12(1,&node11);
    ListNode node13(0,&node12);
    ListNode node14(0,&node13);
    ListNode node15(1,&node14);
    cout << test.getDecimalValue(&node15) << endl;
}
//
// Created by ASUS on 2023/7/15.
//
