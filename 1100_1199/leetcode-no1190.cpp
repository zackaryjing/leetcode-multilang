#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    string reverseParentheses(string s) {
        int sign = 0;
        string tmp,ans;
        for (auto chr : s){
            if (chr == '(' or chr == ')') {
                if (sign){
                    reverse(tmp.begin(),tmp.end());
                }
                ans += tmp;
                tmp.clear();
                sign = !sign;
            }
            else {
                tmp += chr;
            }
        }
        return ans;
    }
};

class Solution3 {
public:
    string dfs(int start,string & s,int direction){
        string tmp;
        for (int i = start;;i++){
            if (s[i] == '('){
                tmp += dfs(i + 1,s,!direction);
            } else if (s[i] == ')'){
                if (direction == 1){
                    reverse(tmp.begin(),tmp.end());
                    return tmp;
                } else {
                    return tmp;
                }
            } else {
                tmp += s[i];
            }
        }
    }
    string reverseParentheses(string s) {
        dfs(0,s,1);
    }
};

class Solution {
public:
    string reverseParentheses(string s) {
        if (s.empty()) return s;
        vector<string> stack = {""};
        int n = s.size();
        string tmp;
        for (int i = 0;i<n;i++){
//            cout << i << endl;
            if (s[i] == '('){
                stack.emplace_back("");
            } else if (s[i] == ')'){
                tmp = stack.back();
                reverse(tmp.begin(),tmp.end());
                stack.pop_back();
                stack.back() += tmp;
            } else {
                stack.back() += s[i];
            }
        }
        return stack.back();
//        return ((stack[0].empty()) ? tmp : stack[0]);
    }
};

int main(){
    Solution test;
    cout << test.reverseParentheses("(abcd)") << endl;
    cout << test.reverseParentheses("(u(love)i)") << endl;
    cout << test.reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    cout << test.reverseParentheses("co(de(fight)s)") << endl;
}
//
// Created by ASUS on 2023/7/12.
//
