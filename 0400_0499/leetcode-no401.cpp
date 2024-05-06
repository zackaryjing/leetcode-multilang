#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkValid(int num){
        if ((num >> 6) >= 12){
            return false;
        }
        if ((num & 63) >= 60){
            return false;
        }
        return true;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0;i<1024;i ++){
            int digits = 0;
            for (int j = 0;j < 10;j++){
                digits += ((i >> j) & 1) ? 1 : 0;
            }
            if (digits == turnedOn){
                if (checkValid(i)) {
                    string tmp;
                    tmp = to_string(i >> 6) + ":" + (((i & 63) < 10) ? "0" : "") + to_string(i & 63);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<string> res = test.readBinaryWatch(1);
    for (auto  i : res) {
        cout << i << " ";
    }
}
//
// Created by ASUS on 2023/6/11.
//
