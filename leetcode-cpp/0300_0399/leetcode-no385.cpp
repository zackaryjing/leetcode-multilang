// problem: https://leetcode.cn/problems/mini-parser/
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    vector<NestedInteger> children;
    int child;
    bool is_integer = false;

    NestedInteger() = default;

    // Constructor initializes a single integer.
    NestedInteger(int value): child(value), is_integer(true) {
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return is_integer; }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return child; };

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        child = value;
        children.clear();
        is_integer = true;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        children.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return children;
    };
    // 重载 << 运算符进行序列化
    friend ostream &operator<<(ostream &os, const NestedInteger &ni) {
        if (ni.isInteger()) {
            os << ni.getInteger(); // 如果是整数，直接输出值
        } else {
            os << "["; // 否则输出列表
            for (size_t i = 0; i < ni.children.size(); ++i) {
                if (i > 0) {
                    os << ", "; // 每个元素之间用逗号分隔
                }
                os << ni.children[i]; // 递归地输出子元素
            }
            os << "]"; // 结束方括号
        }
        return os;
    }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        vector<NestedInteger *> stack;
        NestedInteger dummy;
        NestedInteger *cur = &dummy;
        char *pos = s.data();
        while (*pos != '\0') {
            // cout << *pos << endl;
            if (std::isdigit(*pos) or *pos == '-') {
                int temp_val = strtol(pos, &pos, 10);
                cur->add(NestedInteger(temp_val));
            } else if (*pos == '[') {
                stack.push_back(cur);
                cur->add(NestedInteger());
                cur = const_cast<NestedInteger *>(&cur->getList().back());
                ++pos;
            } else if (*pos == ']') {
                cur = stack.back();
                stack.pop_back();
                ++pos;
            } else {
                ++pos;
            }
        }
        return dummy.getList().front();
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // cout << test.deserialize("1234") << endl;
    cout << test.deserialize("[123,[456,[789]]]") << endl;
}


//
// Created by ASUS on 2025/2/26.
//

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
