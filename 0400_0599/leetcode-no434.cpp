#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int n = s.size(),i = 0,ans = 0;
        while (i < n) {
            if (s[i] != ' '){
                ans ++;
                while (i < n && s[i] != ' '){
                    i++;
                }
            }
            i ++;
        }
        return ans;
    }
};
class Solution3 {
public:
    int countSegments(string s) {
        int n = s.size(),i = 0,ans = 0,lastisspace = 0;
        if (n == 0){
            return 0;
        }
        while (i < n){
            if (s[i] == ' ') {
                ans ++;
                while (s[i] == ' ') i++;
            }
            i ++;
        }
        return ans + 1;
    }
};
class Solution2 {
public:
    int countSegments(string s) {
        int n = s.size(),i = 0,ans = 0,lastend = 0;
        while (i < n){
            if (isspace(s[i])){
                if ((i - lastend) > 1) {
                    ans++;
                    lastend = i;
                }
            }
            i++;
        }
        cout << lastend << " " << i << endl;
        if ((i - lastend) > 1) {
            ans++;
        }
//        int n = s.size(),i = 0,ans = 0,lastend = 0;
//        while (i < n){
//            if (!isalpha(s[i])){
//                if ((i - lastend) > 1) {
//                    ans++;
//                    lastend = i;
//                }
//            }
//            i++;
//        }
//        if ((i - lastend) > 1) {
//            ans++;
//        }
        return ans;
//        for (auto i : s){
//            if (isdigit(i))
//        }
    }
};

int main(){
    Solution test;
    cout << test.countSegments("Hello, my name is John") << endl;
    cout << test.countSegments("love live! mu'sic forever") << endl;
    cout << test.countSegments("a") << endl;
    cout << test.countSegments("       ") << endl;
}
//
// Created by ASUS on 2023/6/22.
//
