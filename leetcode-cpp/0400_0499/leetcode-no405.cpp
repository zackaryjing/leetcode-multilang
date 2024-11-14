#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        unsigned newnum = (unsigned int) num;
        string ans;
        vector<char> data = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while (newnum != 0){
            ans.push_back(data[newnum % 16]);
            newnum /= 16;
        }
        if (ans.empty()){
            ans.push_back('0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    unsigned int ttt = -1;
    cout << ttt << " " << ttt % 16 << endl;
    Solution test;
    cout << test.toHex(26) << endl;
    cout << test.toHex(-1) << endl;
}
//
// Created by ASUS on 2023/6/15.
//
