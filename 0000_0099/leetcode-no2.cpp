//
//* Definition for singly-linked list.
#include <math.h>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0,num2 = 0,times = 0,num3 = 0;
        static auto tmp1 = ListNode(0);
        ListNode *start = &tmp1;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 != nullptr) {
                num3 += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num3 += l2->val;
                l2 = l2->next;
            }
            times += 1;
            start->next = new ListNode(int(num3 % 10));
            start = start->next;
            num3 /= 10;
        }
        auto head = &tmp1;
        while (num3 > 0){
            start->next = new ListNode(int(num3 % 10));
            start = start->next;
            num3 /= 10;
            if (num3 == 0) {
                break;
            }
        }
        return tmp1.next;
    }
};



class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long long int num1 = 0,num2 = 0,times = 0;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 != nullptr) {
//                cout << l1->val << " from l1" << endl;
                num1 += pow(10,times) * l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
//                cout << l2->val << " from l2" << endl;
                num2 += pow(10,times) * l2->val;
                l2  = l2->next;
            }
            times += 1;
        }
        unsigned long long int num3 = num1 + num2;
//        cout << num1 << " " << num2 << " " << num3 << endl;
//        auto * test = new ListNode(0);
        static auto tmp1 = ListNode(0);
        auto head = &tmp1;
        ListNode *start = &tmp1;
        while (num3 >= 0){
            start->next = new ListNode(int(num3 % 10));
            start = start->next;
            num3 /= 10;
            if (num3 == 0) {
                break;
            }
        }
//        cout << "_____" << endl;
//        cout << start->val << endl;
//        cout << tmp1.val << endl;
//        cout << head->val << endl;
        return tmp1.next;
    }
};




int main(){
    Solution t;
    auto s1 = ListNode(3);
    auto s2 = ListNode(4,&s1);
    auto s3 = ListNode(2,&s2);
    auto b1 = ListNode(4);
    auto b2 = ListNode(6,&b1);
    auto b3 = ListNode(5,&b2);
    auto c1 = ListNode();
    auto c2 = ListNode();
    auto a = t.addTwoNumbers(&c1,&c2);
//    auto a = t.addTwoNumbers(&s3,&b3);
    cout << "*****" << endl;
//    cout << a->val << endl;
//    cout << a->next->val << endl;
    while (a != nullptr) {
        cout << a->val << " asd " << endl;
        a = a->next;
    }
}
//
// Created by ASUS on 2023/4/21.
//
