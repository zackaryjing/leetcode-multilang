#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *newHead;
    unordered_map<Node *, Node *> coordinate;

    Node *copyRandomList(Node *head) {
//        cout << "0" << endl;
        if (not head) { return nullptr; }
        newHead = new Node(head->val);
        auto newHeadCopy = newHead;
        coordinate[head] = newHeadCopy;
        auto headcopy = head;
        head = head->next;
//        cout << "1" << endl;
        while (head) {
            newHeadCopy->next = new Node(head->val);
            newHeadCopy = newHeadCopy->next;
            coordinate[head] = newHeadCopy;
            head = head->next;
        }
//        cout << "2" << endl;
        head = headcopy;
        newHeadCopy = newHead;
        int index = 0;
        while (newHeadCopy) {
            index++;
            if (head->random) {
                newHeadCopy->random = coordinate[head->random];
            }
            head = head->next;
            newHeadCopy = newHeadCopy->next;
        }
        return newHead;
    }

//    ~Solution() {
//        while (this->newHead) {
//            auto nextNode = newHead->next;
//            delete this->newHead;
//            this->newHead = nextNode;
//        }
//    }
};

Node *examplefunc();


int main() {
    Solution test;
    auto testnode = examplefunc();
    auto res = test.copyRandomList(testnode);
    while (res) {
        cout << res->val << ": " << res->random << endl;
        res = res->next;
    }
}

Node *examplefunc() {
    Node *test1 = new Node(10);
    Node *test2 = new Node(8);
    Node *test3 = new Node(8);
    Node *test4 = new Node(12);
    Node *test5 = new Node(4);
    Node *test6 = new Node(16);
    Node *test7 = new Node(0);
    Node *test8 = new Node(16);
    Node *test9 = new Node(4);
    test1->next = test2;
    test2->next = test3;
    test3->next = test4;
    test4->next = test5;
    test5->next = test6;
    test6->next = test7;
    test7->next = test8;
    test8->next = test9;
    test7->random = test1;
    test3->random = test3;
    return test1;
}
//
// Created by ASUS on 2024/8/3.
//
