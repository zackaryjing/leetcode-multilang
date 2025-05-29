// problem: https://leetcode.cn/problems/parsing-a-boolean-expression/
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == ',') {
                stk.pop();
                char op = stk.top();
                stk.pop();
                switch (op) {
                    case '!':
                        stk.push(f == 1 ? 't' : 'f');
                        break;
                    case '&':
                        stk.push(f == 0 ? 't' : 'f');
                        break;
                    case '|':
                        stk.push(t > 0 ? 't' : 'f');
                        break;
                    default:
                        break;
                }
                continue;
            } else if (c != ')') {
                stk.push(c);
            } else {
                int t = 0, f = 0;
                while (stk.top() != '(') {
                    char val = stk.top();
                    stk.pop();
                    if (val == 't') {
                        t++;
                    } else {
                        f++;
                    }
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                switch (op) {
                    case '!':
                        stk.push(f == 1 ? 't' : 'f');
                        break;
                    case '&':
                        stk.push(f == 0 ? 't' : 'f');
                        break;
                    case '|':
                        stk.push(t > 0 ? 't' : 'f');
                        break;
                    default:
                        break;
                }
            }
        }
        return stk.top() == 't';
    }
};


class Solution2 {
    // [Pass] Performance not good.
    string expression;

public:
    bool parseBoolExpr(string expression) {
        this->expression = expression;
        return boolExpression(0).first;
    }

    pair<bool, int> boolExpression(int begin) {
        if (expression[begin] == 'f') {
            return {false, begin};
        }
        if (expression[begin] == 't') {
            return {true, begin};
        }

        if (expression[begin] == '!') {
            auto [res,pos] = boolExpression(begin + 2);
            return {not res, pos + 1};
        }
        if (expression[begin] == '&') {
            auto [res,b_end_pos] = boolExpression(begin + 2);
            if (expression[b_end_pos + 1] == ')') {
                return {res, b_end_pos + 1};
            }
            auto [chain,c_end_pos] = expressionChain(b_end_pos + 1);
            if (not res) {
                return {false, c_end_pos + 1};
            }
            for (auto item: chain) {
                if (not item) {
                    return {false, c_end_pos + 1};
                }
            }
            return {true, c_end_pos + 1};

        }
        if (expression[begin] == '|') {
            auto [res,b_end_pos] = boolExpression(begin + 2);
            if (expression[b_end_pos + 1] == ')') {
                return {res, b_end_pos + 1};
            }
            auto [chain,c_end_pos] = expressionChain(b_end_pos + 1);
            if (res) {
                return {true, c_end_pos + 1};
            }
            for (auto item: chain) {
                if (item) {
                    return {true, c_end_pos + 1};
                }
            }
            return {false, c_end_pos + 1};
        }
        return {true, begin};
    }

    pair<vector<bool>, int> expressionChain(int begin) {
        auto [res,e_end_pos] = boolExpression(begin + 1);
        if (expression[e_end_pos + 1] == ',') {
            auto [chain,c_end_pos] = expressionChain(e_end_pos + 1);
            chain.push_back(res);
            return {chain, c_end_pos};
        }
        return {{res}, e_end_pos};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // cout << test.parseBoolExpr("t") << " " << 1 << endl;
    // cout << test.parseBoolExpr("f") << " " << 0 << endl;
    // cout << test.parseBoolExpr("!(f)") << " " << 1 << endl;
    // cout << test.parseBoolExpr("!(t)") << " " << 0 << endl;
    // cout << test.parseBoolExpr("!(&(t,t))") << " " << 0 << endl;
    // cout << test.parseBoolExpr("!(&(t,f))") << " " << 1 << endl;
    // cout << test.parseBoolExpr("!(&(f,t))") << " " << 1 << endl;
    cout << test.parseBoolExpr("|(&(t,f,t),!(t))") << " " << endl;
    // cout << test.parseBoolExpr("&(t,f,t)") << " "  << endl;
    // cout << test.parseBoolExpr("|(&(t,f,t),f)") << " " << endl;
    // cout << test.parseBoolExpr("|(&(f,t),f)") << " " << endl;
    // cout << test.parseBoolExpr("|(&(t,f,t,f),f)") << " " << endl;

    // cout << test.parseBoolExpr("|(f,f,f,f,t)") << " " << 1 << endl;
    cout << "" << endl;
}

//
// Created By Zackary At 2025-05-28 19:41:22
//
