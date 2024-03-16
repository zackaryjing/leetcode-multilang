#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>

using namespace std;

class LRUCache2 {
private:
    map<int, pair<int, int>> store;
    map<int, int> th_key;
    int total, th;
public:
    LRUCache2(int capacity) {
        total = capacity;
        th = 0;
    }

    int get(int key) {
        th++;
        if (store.find(key) == store.end()) {
            return -1;
        }
        th_key.erase(store[key].second);
        store[key].second = th;
        th_key[th] = key;
        return store[key].first;
    }

    void put(int key, int value) {
        th++;
        auto it = store.find(key);
        if (it != store.end()) {
            th_key.erase(it->second.second);
        }
        store[key] = {value, th};
        th_key[th] = key;
        if (store.size() > total) {
            store.erase(th_key.begin()->second);
            th_key.erase(th_key.begin());
        }
    }
};

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;

    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key,int _value): key(_key),value(_value),prev(nullptr),next()
};

class LRUCache {
private:
    unordered_map<int,DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity) : capacity(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (not cache.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (not cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key,value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }

    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }


};




int main() {
    LRUCache test(2);
//    cout << test.get(2) << endl;
//    test.put(2,6);
//    cout << test.get(1) << endl;
//    test.put(1,5);
//    test.put(1,2);
//    cout << test.get(1) << endl;
//   cout << test.get(2) << endl;

    test.put(1, 1);
    test.put(2, 2);
    cout << test.get(1) << endl;
    test.put(3, 3);
    cout << test.get(2) << endl;
    test.put(4, 4);
    cout << test.get(1) << endl;
    cout << test.get(3) << endl;
    cout << test.get(4) << endl;
}
//
// Created by ASUS on 2024/2/18.
//
