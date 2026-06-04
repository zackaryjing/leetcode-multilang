// problem:
// https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
#include "../utils/listgenerator.h"
#include "../utils/vector_helper.h"


using namespace std;

/**
 * Definition for singly-linked list.
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {
//     }
//     ListNode(int x) : val(x), next(nullptr) {
//     }
//     ListNode(int x, ListNode *next) : val(x), next(next) {
//     }
// };


class Solution2 {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        unordered_map<int, vector<ListNode *>> pos;
        auto dummy = new ListNode(0, head);
        auto cur = dummy;
        pos[0].push_back(cur);
        int sum = 0;
        while (cur->next) {
            cur = cur->next;
            sum += cur->val;
            if (pos.contains(sum)) {
                for (auto each: pos[sum]) {
                    each->next = cur->next;
                }
            }
            pos[sum].push_back(cur);
        }
        return dummy->next;
    }
};
疼
class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        unordered_map<int, ListNode *> pos;
        auto dummy = new ListNode(0, head);
        auto cur = dummy;
        pos[0] = cur;
        int sum = 0;
        while (cur->next) {
            cur = cur->next;
            sum += cur->val;
            if (pos.contains(sum)) {
                int ts = sum;
                for (auto p = pos[sum]->next; p != cur; p = p->next) {
                    ts += p->val;
                    pos.erase(ts);
                }
                pos[sum]->next = cur->next;
            } else {
                pos[sum] = cur;
            }
        }
        return dummy->next;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    prettyPrintList(test.removeZeroSumSublists(stringToListNode("[0,0]")));
    prettyPrintList(test.removeZeroSumSublists(stringToListNode("[1,2,-3,3,1]")));
    prettyPrintList(test.removeZeroSumSublists(stringToListNode("[1,2,3,-3,4]")));
    prettyPrintList(test.removeZeroSumSublists(stringToListNode("[1,2,3,-3,-2]")));
}

//
// Created By jing At 2026-06-04 19:37
//
