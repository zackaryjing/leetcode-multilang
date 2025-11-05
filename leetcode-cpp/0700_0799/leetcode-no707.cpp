// problem: https://leetcode.cn/problems/design-linked-list/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node *next = nullptr;
    Node *prev = nullptr;
    int val;
    Node(int val) : val(val) {};
    Node(int val, Node *next, Node *prev) : val(val), next(next), prev(prev) {};
};

class MyLinkedList {
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    MyLinkedList() {}

    int get(int index) {
        if (size <= index) {
            return -1;
        }
        auto cur = head;
        for (int i = 0; i < index; ++i) {
            if (cur->next) {
                cur = cur->next;
            }
        }
        return cur->val;
    }

    void addAtHead(int val) {
        const auto temp = new Node(val, head, nullptr);
        if (size != 0) {
            head->prev = temp;
        } else {
            tail = temp;
        }
        head = temp;
        size += 1;
    }

    void addAtTail(int val) {
        const auto temp = new Node(val, nullptr, tail);
        if (size != 0) {
            tail->next = temp;
        } else {
            head = temp;
        }
        tail = temp;
        size += 1;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node *cur = head;
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            cur->next = new Node(val, cur->next, cur);
            cur->next->next->prev = cur->next;
            size += 1;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        if (index == 0) {
            const Node *temp = head;
            head = head->next;
            if (size == 1) {
                tail = nullptr;
            } else {
                head->prev = nullptr;
            }
            delete temp;
        } else if (index == size - 1) {
            const Node *temp = tail;
            tail = tail->prev;
            if (size == 1) {
                head = nullptr;
            } else {
                tail->next = nullptr;
            }
            delete temp;
        } else {
            Node *cur = head;
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            const Node *temp = cur->next;
            cur->next = cur->next->next;
            cur->next->prev = cur;
            delete temp;
        }
        size -= 1;
    }
    void show() {
        Node *cur = head;
        cout << "prev: ";
        while (cur) {
            if (not cur->prev) {
                cout << "  ";
            } else {
                cout << cur->prev->val << " ";
            }
            cur = cur->next;
        }
        cout << endl;

        cur = head;
        cout << "curr: ";
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;

        cur = head;
        cout << "next: ";
        while (cur) {
            if (not cur->next) {
                cout << "  ";
            } else {
                cout << cur->next->val << " ";
            }
            cur = cur->next;
        }
        cout << endl;
        if (tail) {
            cout << "tail: " << tail->val << endl;
        }
        if (head) {
            cout << "head: " << head->val << endl;
        }
        cout << "size: " << size << endl << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char *argv[]) {
    MyLinkedList test;
    test.addAtHead(1);
    test.addAtTail(3);
    test.addAtIndex(1, 2);
    cout << test.get(1) << endl;
    test.deleteAtIndex(1);
    cout << test.get(1) << endl;
    cout << "end" << endl;

    MyLinkedList test2;
    test2.addAtHead(7);
    test2.show();
    test2.addAtHead(2);
    test2.show();
    test2.addAtHead(1);
    test2.show();
    test2.addAtIndex(3, 0);
    test2.show();
    test2.deleteAtIndex(2);
    test2.show();
    test2.addAtHead(6);
    test2.show();
    test2.addAtTail(4);
    test2.show();
    cout << test2.get(4) << endl;
    test2.addAtHead(4);
    test2.show();
    test2.addAtIndex(5, 0);
    // test2.addAtHead(6);
    cout << "end" << endl;

    MyLinkedList test3;
    test3.addAtHead(2);
    test3.deleteAtIndex(1);
    test3.addAtHead(2);
    test3.addAtHead(7);
    test3.addAtHead(3);
    test3.addAtHead(2);
    test3.addAtHead(5);
    test3.addAtTail(5);
    cout << test3.get(5) << endl;
    test3.show();
    test3.deleteAtIndex(6);
    test3.deleteAtIndex(4);
    cout << "end" << endl;


    MyLinkedList test4;
    test4.addAtHead(0);
    test4.addAtIndex(1, 4);
    test4.addAtTail(8);
    test4.addAtHead(5);
    test4.addAtIndex(4, 3);
    test4.addAtTail(0);
    test4.show();
    test4.addAtTail(5);
    test4.show();
    test4.addAtIndex(6, 3);
    test4.show();
    test4.deleteAtIndex(7);
    test4.show();
    test4.deleteAtIndex(5);
    test4.show();
    test4.addAtTail(4);
    cout << "end" << endl;
}

//
// Created By jing At 2025-10-22 16:45
//
