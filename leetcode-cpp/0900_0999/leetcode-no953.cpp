#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Solution {
public:
    map<char,short> projection;
    bool comp(string &first,string &second){
        int n = first.length();
        int m = second.length();
        for (int i = 0;i < min(n,m);++i){
            if (projection[first[i]] < projection[second[i]]){
//                cout << i << endl;
//                cout << first[i] << " " << second[i] << endl;
                return true;
            } else if (projection[first[i]] > projection[second[i]]){
                return false;
            }
        }
        return (n <= m);
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0;i < order.size();++i){
            projection[order[i]] = (short) i;
        }
        int n = words.size();
        for (int i = 1;i < n;++i){
            if (not comp(words[i - 1],words[i])) return false;
        }
        return true;
    }
};

int main(){
    Solution test;
    vector<string> words1 = {"hello" ,"leetcode"};
    string order1 = "hlabcdefgijkmnopqrstuvwxyz";
    cout << test.isAlienSorted(words1,order1) << endl;
    vector<string> words2 = {"word","world,","row"};
    string order2 = "worldabcefghijkmnpqstuvxyz";
    cout << test.isAlienSorted(words2,order2) << endl;
    vector<string> words3 = {"apple","app"};
    string order3 = "abcdefghijklmnopqrstuvwxyz";
    cout << test.isAlienSorted(words3,order3) << endl;
}
//
// Created by ASUS on 2023/8/29.
//
