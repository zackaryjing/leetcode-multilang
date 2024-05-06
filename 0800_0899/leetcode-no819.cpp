#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctype.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> data;
        int start = 0, length = 0;
        for (auto i : paragraph){
            if (!isalpha(i)){
                string tmp = paragraph.substr(start,length);
                if (tmp != "") {
                    transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
                    data[tmp] ++;
                    //cout << tmp << " " << tmp.size() << endl;
                }
                start += length + 1;
                length = 0;
            } else {
                length++;
            }
        }
        string tmp = paragraph.substr(start,length);
        if (tmp != "") {
            transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
            data[tmp] ++;
            //cout << tmp << " " << tmp.size() << endl;
        }
        int maxtimes = 0;
        string ans;
        for (auto [key,value] : data){
            if (find(banned.begin(), banned.end(),key) == banned.end()){
                if (value > maxtimes) {
                    maxtimes = value;
                    ans = key;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<string> banned = {"hit"};
    vector<string> ban = {};
    cout << test.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.",banned) << endl;
    cout << test.mostCommonWord("Bob hit a ball,  the hit BALL flew,,, fa,,,r after it was hit.",banned) << endl;
    cout << test.mostCommonWord("Bob",ban) << endl;
}

//
// Created by ASUS on 2023/6/20.
//
