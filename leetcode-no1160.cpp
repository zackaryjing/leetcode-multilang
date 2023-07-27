#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> times(26);
        for (auto i : chars){
            times[i - 'a']++;
        }
        int ans = 0;
        for (auto word : words){
            vector<int> tmp(26);
            for (auto letter : word){
                tmp[letter - 'a']++;
            }
            int valid = 1;
            for (int k = 0;k < 26;k++){
                if (tmp[k] > times[k]){
                    valid = 0;
                    break;
                }
            }
            if (valid) {
//                cout << word.size() << endl;
                ans += word.size();
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<string> eg1 = {"cat","bt","hat","tree"};
    cout << test.countCharacters(eg1,"atach") << endl;
}
//
// Created by ASUS on 2023/7/19.
//
