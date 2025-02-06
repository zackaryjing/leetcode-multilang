#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        ListNode *temp = node->next->next;
        delete node->next;
        node->next = temp;
    }
};

int main() {
    Solution test;
}

//
// Created by ASUS on 2025/1/23.
//
