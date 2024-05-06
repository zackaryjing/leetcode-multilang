#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (auto h : address){
            if (h == '.'){
                ans += ("[.]");
            } else {
                ans += h;
            }
        }
        return ans;
    }
};


int main(){
    Solution test;
    cout << test.defangIPaddr("1.1.1.1") << endl;
    cout << test.defangIPaddr("255.100.50.0") << endl;
}

//
// Created by ASUS on 2023/7/18.
//
