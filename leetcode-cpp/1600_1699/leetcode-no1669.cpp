// problem: https://leetcode.cn/problems/merge-in-between-linked-lists/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <list>
#include <vector>
#include "../utils/vector_helper.h"


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
    ListNode *mergeInBetween(ListNode *list1, const int a, const int b, ListNode *list2) {
        const auto dummy1 = list1;
        const auto dummy2 = list2;
        for (int i = 0; i < a - 1; ++i) list1 = list1->next;
        while (list2->next) list2 = list2->next;
        const auto mid = list1;
        for (int j = a - 1; j <= b; ++j) list1 = list1->next;
        mid->next = dummy2;
        list2->next = list1;
        return dummy1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto a6 = ListNode(6);
    auto a5 = ListNode(5, &a6);
    auto a4 = ListNode(4, &a5);
    auto a3 = ListNode(3, &a4);
    auto a2 = ListNode(2, &a3);
    auto a1 = ListNode(1, &a2);
    auto a0 = ListNode(0, &a1);

    auto b11 = ListNode(110);
    auto b10 = ListNode(100, &b11);
    auto b9 = ListNode(90, &b10);
    auto b8 = ListNode(80, &b9);
    auto b7 = ListNode(70, &b8);

    auto t = test.mergeInBetween(&a1, 2, 5, &b7);
    cout << string(20, '-') << endl;
    while (t) {
        cout << t->val << endl;
        t = t->next;
    }
}

//
// Created By ASUS At 2026-02-04 23:23
//
