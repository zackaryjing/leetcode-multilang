#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
private:
    vector<NestedInteger> data;
    int val;
    bool isInt;
public:
    NestedInteger(int val) {
        this->val = val;
        this->isInt = true;
    }

//    NestedInteger(vector<NestedInteger> data) {
//        this->data = data;
//        this->isInt = false;
//    }

    NestedInteger(vector<int> data) {
        for (auto i: data) {
            data.emplace_back(i);
        }
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return isInt;
    };

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return val;
    };

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return data;
    };
};

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        return stk.top().first++->getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto &p = stk.top();
            if (p.first == p.second) {
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            auto &lst = p.first++->getList();
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


int main() {
    vector<NestedInteger> a = {1, NestedInteger({2, 3, 4})};
//    vector<NestedInteger> b = {1, vector<int>({2, 3, 4})};
//    vector<NestedInteger> a = {1};
    NestedIterator test(a);
    cout << test.next() << endl;
    cout << test.next() << endl;
    cout << test.next() << endl;
    cout << test.next() << endl;
    cout << test.next() << endl;
    cout << test.next() << endl;
    cout << test.next() << endl;
}
//
// Created by ASUS on 2024/8/10.
//
