#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        vector<pair<char,int>> data;
        for (int i = 0;i < n;i++){
            if (isalpha(s[i])){
                data.emplace_back(s[i],i);
            }
        }
        int h = data.size();
        for (int j = 0;j < h;j++){
            s[data[h - j - 1].second] = data[j].first;
        }
        return s;
    }
};

int main(){
    Solution test;
    string eg1 = "ab-cd";
    string eg2 = "a-bC-dEf-ghIj";
    string eg3 = "j-Ih-gfE-dCba";
    cout << test.reverseOnlyLetters(eg1) << endl;
    cout << test.reverseOnlyLetters(eg2) << endl;
    cout << test.reverseOnlyLetters(eg3) << endl;
}
//
// Created by ASUS on 2023/7/16.
//
