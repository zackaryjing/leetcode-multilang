#include <iostream>
#include <vector>
#include <bits/stl_list.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        if (not head) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (true) {
            if (fast->next) {
                fast = fast->next;
            } else {
                return slow;
            }
            slow = slow->next;
            if (fast->next) {
                fast = fast->next;
            } else {
                return slow;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(3, &node2);
    ListNode node4(4, &node3);
    ListNode node5(5, &node4);
    ListNode node6(6, &node5);
    cout << test.middleNode(&node2)->val << endl;;
}


//
// Created by ASUS on 2025/2/17.
//
