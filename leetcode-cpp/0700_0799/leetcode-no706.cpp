#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Node {
    unique_ptr<Node> next = nullptr;
    int val;
    int key;

    Node(int key, int val): key(key), val(val) {
    }

    Node(int key, int val, Node *next): key(key), val(val), next(next) {
    }
};

class MyHashMap {
public:
    vector<unique_ptr<Node> > _data;
    const int size = 11173;

    MyHashMap() {
        _data.reserve(size);
        for (int i = 0; i < size; ++i) {
            _data.emplace_back(nullptr);
        }
    }

    void put(int key, int value) {
        int hash_key = key % size;
        if (_data[hash_key] != nullptr) {
            auto cur = _data[hash_key].get();
            while (cur->key != key and cur->next) {
                cur = cur->next.get();
            }

            if (cur->key == key) {
                cur->val = value;
                return;
            }
            cur->next = make_unique<Node>(key, value);
        } else {
            _data[hash_key] = make_unique<Node>(key, value);
        }
    }

    int get(int key) {
        int hash_key = key % size;
        if (_data[hash_key] != nullptr) {
            auto cur = _data[hash_key].get();
            while (cur->key != key and cur->next) {
                cur = cur->next.get();
            }
            if (cur->key == key) {
                return cur->val;
            }
            return -1;
        }
        return -1;
    }

    void remove(int key) {
        int hash_key = key % size;
        if (_data[hash_key] != nullptr) {
            auto last = _data[hash_key].get();
            auto cur = _data[hash_key].get();
            if (cur->key == key) {
                _data[hash_key] = move(cur->next);
                return;
            }
            while (cur->key != key and cur->next) {
                last = cur;
                cur = cur->next.get();
            }
            if (cur->key == key) {
                last->next = move(cur->next);
            }
        }
    }
};



/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char *argv[]) {
    MyHashMap test;
    test.put(10, 10);
    cout << test.get(10) << endl;;
    test.put(10, 11);
    cout << test.get(10) << endl;
    test.put(1010, 12);
    cout << test.get(10) << endl;
    cout << test.get(1010) << endl;
}


//
// Created by ASUS on 2025/3/8.
//
