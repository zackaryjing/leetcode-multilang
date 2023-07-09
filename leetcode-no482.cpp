#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:

    string licenseKeyFormatting(string s, int k) {
        string ans;
        int n = s.size();
        int times = 0;
        for (int j = n - 1; j>= 0 ;j --){
            if (s[j] != '-'){
                ans.push_back(toupper(s[j]));
                times += 1;
                if ((times % k) == 0){
                    ans.push_back('-');
                }
            }
        }
        int newn = ans.size() - 1;
        if (newn >= 0 && ans[newn] == '-'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution test;
    cout << test.licenseKeyFormatting("5F3Z-2e-9-w",4) << endl;
    Solution test2;
    cout << test2.licenseKeyFormatting("---",3) << endl;
}
//public:
//    string ans;
//    string licenseKeyFormatting(string s, int k) {
//        int n = s.size() - 1;
//        int times = 0;
//        for (int i = n;i>=0;i--){
//            if (s[i] != '-') {
//                ans.push_back(s[i]);
//                times += 1;
//            }
//            if (times % k == 0) ans.push_back('-');
//        }
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};


//
// Created by ASUS on 2023/6/13.
//
