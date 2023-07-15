#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char,vector<int>> data = {{'a',{0,0}},{'b',{0,1}},{'c',{0,2}},{'d',{0,3}},{'e',{0,4}},{'f',{1,0}},{'g',{1,1}},{'h',{1,2}},{'i',{1,3}},{'j',{1,4}},
    {'k',{2,0}},{'l',{2,1}},{'m',{2,2}},{'n',{2,3}},{'o',{2,4}},{'p',{3,0}},{'q',{3,1}},{'r',{3,2}},{'s',{3,3}},{'t',{3,4}},
    {'u',{4,0}},{'v',{4,1}},{'w',{4,2}},{'x',{4,3}},{'y',{4,4}},{'z',{5,0}}};
    string alphabetBoardPath(string target) {
        vector<int> cur = {0,0};
        string ans;
        for (auto t : target){
//            cout << t << " -- " << endl;
            if (data[t] != cur){
                int dy = data[t][0] - cur[0],dx = data[t][1] - cur[1];
                if (dy > 0) {
                    if (dx > 0) {
                        ans += string(dx,'R');
                    } else {
                        ans += string(abs(dx),'L');
                    }
                    ans += string(dy,'D');
                } else {
                    ans += string(abs(dy),'U');
                    if (dx > 0) {
                        ans += string(dx,'R');
                    } else {
                        ans += string(abs(dx),'L');
                    }
                }
                cur = data[t];
            }
            ans += '!';
        }
        return ans;
    }
};

int main(){
    Solution test;
    cout << test.alphabetBoardPath("leet") << endl;
    cout << test.alphabetBoardPath("code") << endl;
    cout << test.alphabetBoardPath("zdz") << endl;
//    int pos = 0;
//    for (int i = 0;i < 6;i ++ ){
//        for (int j = 0;j < 5; j++){
//            cout << "{'" << (char)(pos + 'a') << "',{" << i << "," << j << "}},";
//            pos ++;
//        }
//    }
}
//
// Created by ASUS on 2023/7/14.
//
