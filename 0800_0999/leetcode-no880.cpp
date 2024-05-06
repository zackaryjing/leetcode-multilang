#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution2 {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size(),tmpLength = 0;
        long long totalLength = 0;
        string tmpString;
        vector<tuple<string,long long,long long>> data;
        for (int i = 0;i < n;i++){
            if (isalpha(s[i])){
                tmpString += s[i];
                tmpLength++;
            } else {
                string tmpTimes;
                while (i < n and isdigit(s[i])){
                    tmpTimes += s[i++];
                }
                i--;
//                cout << tmpTimes << endl;
                if (tmpTimes.size() < 20){
                    if (tmpTimes.empty()) tmpTimes += "1";
                    auto [_, lastLength, lastTimes] = data.back();
                    data.emplace_back(tmpString,tmpLength + lastLength * lastTimes,stoll(tmpTimes));
                } else {
                    data.emplace_back(tmpString,tmpLength,LONG_LONG_MAX);
                }
                tmpString = "";
                tmpLength = 0;
            }
        }
        if (!tmpString.empty()) {
            data.emplace_back(tmpString,tmpLength,1);
        }
        for (auto &t : data){
            auto [a,b,c] = t;
            cout << a << endl;
//            cout << a << " " << b << " " << c << endl;
        }
        cout << totalLength << endl;
        string ans;
        if (k == 0) ans += s[n - 1];
        else {
            int h = 0;
            tmpLength = get<1>(data[h]);
            int tmpTimes = get<2>(data[h]);
            while (tmpLength * tmpTimes < k and tmpTimes * tmpLength > 0){
//                cout << get<0>(data[h]) << endl;
                k -= tmpLength * tmpTimes;
                h++;
            }
            int pos =  k % tmpLength;
            if (pos != 0) ans += get<0>(data[h])[pos - 1];
            else ans += get<0>(data[h])[tmpLength - 1];
        }
        return ans;
    }
};

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        int N = s.size();
        for (int i = 0;i < N;++i){
            if (isdigit(s[i]))
                size *= s[i] - '0';
            else
                size++;
        }
        for (int i = N - 1;i >= 0;--i){
            k %= size;
            if (k == 0 and isalpha(s[i]))
                return (string)"" + s[i];
            if (isdigit(s[i]))
                size /= s[i] - '0';
            else
                size --;
        }
        return "";
    }
};

int main(){
    Solution test;
    cout << test.decodeAtIndex("a2b3c4d5e6f7g8h9",9) << endl;
//    cout << test.decodeAtIndex("abc1",1) << endl;
//    cout << test.decodeAtIndex("abc",1) << endl;
//    cout << test.decodeAtIndex("leet2code3",10) << endl;
//    cout << test.decodeAtIndex("ha22",5) << endl;
//    cout << test.decodeAtIndex("a2345678999999999999999",1) << endl;

}


//
// Created by ASUS on 2023/7/29.
//
