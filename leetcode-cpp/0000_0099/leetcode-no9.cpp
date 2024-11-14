#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution3 {
public:
    bool isPalindrome2(int x) {
        string k = to_string(x);
        string t = k;
        reverse(t.begin(),t.end());
        if (t == k){
            return true;
        } else {
            return false;
        }
    }
};
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0){
            return false;
        }
        int revertedNumber = 0;
        while (x > revertedNumber){
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
//            cout << revertedNumber << " " << x << endl;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        string tmp = to_string(x);
        reverse(tmp.begin(),tmp.end());
        return (tmp == to_string(x));
    }
};

int main(){
    Solution t;
    cout << t.isPalindrome(12321) << endl;
//    cout << t.isPalindrome(100) << endl;
//    cout << t.isPalindrome(111) << endl;
//    cout << t.isPalindrome(101) << endl;
}

//
// Created by ASUS on 2023/4/18.
//
