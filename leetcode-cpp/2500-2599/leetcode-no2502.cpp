#include <iostream>
#include <map>
#include <vector>
#include <pstl/algorithm_fwd.h>

using namespace std;

struct Node {
    int begin;
    int end;
    int size;
    bool is_available = true;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node() {
    };

    Node(int begin, int end) : begin(begin), end(end) {
        size = end - begin + 1;
    }

    Node(int begin, int end, bool is_available) : begin(begin), end(end), is_available(is_available) {
        size = end - begin + 1;
    }


    void set_begin(int val) {
        begin = val;
        size = end - begin + 1;
    }

    void set_end(int val) {
        end = val;
        size = end - begin + 1;
    }
};

class Allocator {
public:
    Node *blocks{};
    map<int, vector<Node *> > pos;

    Allocator(int n) {
        blocks = new Node(0, n - 1);
    }

    int allocate(int size, int mID) {
        // cout << "allocating size: " << size << endl;
        Node *cur = blocks;
        while (cur) {
            if (cur->is_available and cur->size >= size) {
                if (cur->size > size) {
                    Node *temp = new Node(cur->begin + size, cur->end);
                    // cout << temp->is_available << endl;
                    cur->set_end(cur->begin + size - 1);
                    if (cur->next) {
                        cur->next->prev = temp;
                    }
                    temp->next = cur->next;
                    cur->next = temp;
                    temp->prev = cur;
                }
                cur->is_available = false;
                pos[mID].push_back(cur);
                break;
            }
            cur = cur->next;
        }
        // show();
        if (not cur) {
            return -1;
        }
        return cur->begin;
    }

    int freeMemory(int mID) {
        auto all_block = pos[mID];
        int res = 0;
        if (not all_block.empty()) {
            for (auto &block: all_block) {
                block->is_available = true;
                res += block->size;
                if (block->next and block->next->is_available) {
                    block->set_end(block->next->end);
                    Node *temp = block->next;
                    block->next = block->next->next;
                    if (block->next) {
                        block->next->prev = block;
                    }
                    delete temp;
                }
                if (block->prev and block->prev->is_available) {
                    block->set_begin(block->prev->begin);
                    Node *temp = block->prev;
                    block->prev = block->prev->prev;
                    if (not block->prev) {
                        blocks = block;
                    }
                    if (block->prev) {
                        block->prev->next = block;
                    }
                    delete temp;
                }
                // show();
            }
        }
        pos.erase(mID);
        return res;
    }

    void show() {
        Node *temp = blocks;
        while (temp) {
            cout << "[" << temp->begin << "," << temp->end << "," << temp->size << (temp->is_available ? "A]" : "N]") <<
                    " - ";
            // cout << temp->is_available;
            temp = temp->next;
        }
        cout << " | " << endl;
    }
};

int main(int argc, char *argv[]) {
    Allocator test(10);
    test.allocate(1, 1);
    test.allocate(1, 2);
    test.allocate(1, 3);
    test.freeMemory(2);
    test.allocate(3, 4);
    test.allocate(1, 1);
    test.allocate(1, 1);
    test.freeMemory(1);
    test.allocate(10, 2);
    test.freeMemory(7);
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */


//
// Created by ASUS on 2025/2/25.
//
