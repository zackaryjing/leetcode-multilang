// problem: https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"
#include "../utils/treegenerator.h"


using namespace std;

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        auto dummy = head;
        auto second = head;
        ListNode *fprev, *sprev;
        for (int i = 0; i < k - 1; ++i) {
            fprev = head;
            head = head->next;
        }
        auto first = head;
        while (head->next != nullptr) {
            sprev = second;
            second = second->next;
            head = head->next;
        }
        if (k == 1) {
            if (sprev != nullptr) {
                sprev->next = first;
            }
            swap(second->next, first->next);
            return second;
        }
        if (second == dummy) {
            if (fprev == second) {
                first->next = second;
                second->next = nullptr;
            } else {
                swap(second->next, first->next);
                fprev->next = second;
            }
            return first;
        }
        if (sprev == first) {
            first->next = second->next;
            second->next = first;
            fprev->next = second;
        } else if (fprev == second) {
            second->next = first->next;
            first->next = second;
            sprev->next = first;
        } else {
            swap(second->next, first->next);
            swap(sprev->next, fprev->next);
        }
        return dummy;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto n5 = ListNode(5);
    auto n4 = ListNode(4, &n5);
    auto n3 = ListNode(3, &n4);
    auto n2 = ListNode(2, &n3);
    auto n1 = ListNode(1, &n2);
    auto head = &n1;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    test.swapNodes(&n5, 1);
    cout << endl;
    head = &n1;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//
// Created By ASUS At 2026-01-20 20:25
//
