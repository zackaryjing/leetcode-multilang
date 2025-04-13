// problem: https://leetcode.cn/problems/basic-calculator/description/
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> stack;
        int cur = 0;
        int n = static_cast<int>(s.size());
        for (int i = 0; i <= n; ++i) {
            if (s[i] == '-') {
                stack.emplace_back("-");
            } else if (s[i] == '+') {
                stack.emplace_back("+");
            } else if (s[i] == '(') {
                stack.emplace_back("(");
            } else if (std::isdigit(s[i])) {
                int end = i;
                while (std::isdigit(s[end])) {
                    ++end;
                }
                stack.emplace_back(s.substr(i, end - i));
                i = end - 1;
            } else if (s[i] != ' ') {
                // show_vector(stack);
                if (not stack.empty()) {
                    cur = stoi(stack.back());
                    // cout << "cur: " << cur << endl;
                    stack.pop_back();
                    while (not stack.empty()) {
                        auto top = stack.back();
                        // cout << "top: " << top << endl;
                        stack.pop_back();
                        if (top == "(") {
                            stack.push_back(std::to_string(cur));
                            break;
                        } else if (top == "+") {
                            auto nx = stack.back();
                            stack.pop_back();
                            int sign = 1;
                            if (not stack.empty()) {
                                string sign_cdd = stack.back();
                                if (sign_cdd == "-") {
                                    sign = -1;
                                    stack.pop_back();
                                }
                            }
                            cur = sign * stoi(nx) + cur;
                        } else if (top == "-") {
                            cur = -cur;
                        } else {
                            int sign = 1;
                            if (not stack.empty()) {
                                string sign_cdd = stack.back();
                                if (sign_cdd == "-") {
                                    sign = -1;
                                    stack.pop_back();
                                }
                            }
                            cur += sign * stoi(top);
                        }
                    }
                }
            }
        }
        return cur;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << test.calculate("1 + 1") << endl;
    cout << test.calculate("2 - 1 + 2") << endl;
    cout << test.calculate("-2 - 2 -2 -2") << endl;
    cout << test.calculate("-2 - 2 + (-2 -2)") << endl;
    cout << test.calculate("-2 - 2 - (-2 -2)") << endl;
}


//
// Created by ASUS on 2025/4/11.
//
