#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 */
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

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

ListNode *stringToListNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);

    if (input.empty() || input == "[]") {
        return nullptr;
    }

    input = input.substr(1, input.length() - 2);

    string item;
    stringstream ss(input);

    ListNode dummy;
    ListNode *cur = &dummy;

    while (getline(ss, item, ',')) {
        trimLeftTrailingSpaces(item);
        trimRightTrailingSpaces(item);

        if (item.empty()) {
            continue;
        }

        cur->next = new ListNode(stoi(item));
        cur = cur->next;
    }

    return dummy.next;
}

string listNodeToString(ListNode *head) {
    if (head == nullptr) {
        return "[]";
    }

    string output;

    while (head != nullptr) {
        output += to_string(head->val);
        output += ", ";
        head = head->next;
    }

    return "[" + output.substr(0, output.length() - 2) + "]";
}

void prettyPrintList(ListNode *head) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return;
    }

    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }

    cout << " -> nullptr\n";
}

void freeList(ListNode *head) {
    while (head != nullptr) {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

//
// Created By jing At 2026-06-04 19:55
//
