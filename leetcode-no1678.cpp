#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        int n = command.size(),pos = 0;
        string ans;
        while (pos < n){
            char c = command[pos];
            if (c == 'G'){
                ans += 'G';
                pos ++;
            } else {
                char t = command[pos + 1];
                if (t == ')') {
                    ans += 'o';
                    pos += 2;
                } else {
                    ans += "al";
                    pos += 4;
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    string interpret(string command){
        string res;
        for (int i = 0;i < command.size();i++){
            if (command[i] == 'G'){
                res += "G";
            } else if (command[i] == '('){
                if (command[i + 1] == ')'){
                    res += "o";
                } else {
                    res += "al";
                }
            }
        }
        return res;
    }

};

int main(){
    Solution test;
    cout << test.interpret("(al)G(al)()()G") << endl;
    cout << test.interpret("G()()()(al)") << endl;
    cout << test.interpret("G()(al)") << endl;
}

//
// Created by ASUS on 2023/7/15.
//
