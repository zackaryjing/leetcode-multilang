#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0,late = 0;
        for (auto i : s){
            if (i == 'A'){
                late = 0;
                absent ++;
                if (absent >= 2) return false;
            } else if (i == 'L'){
                late ++;
                if (late >= 3) return false;
            } else {
                late = 0;
            }
        }
        return true;
    }
};
int main(){
    Solution test;
    test.checkRecord("LALL");
}
//
// Created by ASUS on 2023/6/29.
//
