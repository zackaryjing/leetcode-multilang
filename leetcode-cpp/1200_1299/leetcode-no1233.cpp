#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    vector<string> removeSubfolders(vector<string>& folder) {
//        sort(folder.begin(), folder.end());
//        // vector<string> copy = folder;
//        // unordered_set<string> copy(folder.begin(),folder.end());
//        // for (auto i : folder) cout << i << " " << endl;
//        // for (auto i : copy) cout << i << " " << endl;
//        vector<int> todel;
//        //cout << string(20,'-') << endl;
//        int n = folder.size();
//        for (int i = 1;i < n;i++){
//            if (folder[i].size() <= folder[i - 1].size()) continue;
//             //cout << folder[i] << " " << folder[i].substr(0,folder[i - 1].size()) << " " << folder[i - 1]  << endl;
//            if (folder[i].substr(0,folder[i - 1].size()) == folder[i - 1]){
//                if (folder[i][folder[i - 1].length()] == '/'){
//                    // cout << i << endl;
//                    todel.push_back(i);
//                }
//            }
//        }
//        for (int j = todel.size() - 1;j >= 0;j--){
//            folder.erase(folder.begin() + todel[j]);
//        }
//        return folder;
//    }
//};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
//        cout << endl << string(30,'+') << endl;
//        for (auto j : folder) cout << j << " ";
//        cout << endl << string(30,'+') << endl;
        vector<int> todel;
        int n = folder.size();
        int first = 0,second = 1;
        while (first < n and second < n){
            if (folder[second].size() <= folder[first].size()) {
                first = second;
                second ++;
                continue;
            }
            //cout << folder[second] << " " << folder[first] << endl;
            if (folder[second].substr(0,folder[first].size()) == folder[first]){
                if (folder[second][folder[first].length()] == '/'){
                    todel.push_back(second);
                    // first = second;
                    second++;
                } else {
                    first = second;
                    second++;
                }
            } else {
                first = second;
                second++;
            }
        };
        for (int j = todel.size() - 1;j >= 0;j--){
            folder.erase(folder.begin() + todel[j]);
        }
        return folder;
    }
};
int main(){
    Solution test;
    vector<string> example1 = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> example2 = {"/leet","/leetcode"};
    vector<string> example3 = {"/a","/a/b/c","/a/b/d"};
    vector<string> example4 = {"/aa/ab/ac/ad","/aa/aq/ay","/bf/bv/cd/ch/cj","/bf/bg","/aa/aq/ar","/bf","/aa/ab/aj/an/ao","/aa/aq/ay/az","/aa/aq/ay/bc","/bf/bg/bh/bi/bj","/bf/bv/bw/ca/cc","/bf/bg/bh/bl"};
    for (auto h : {example1,example2,example3,example4}){
        vector<string> res = test.removeSubfolders(h);
        cout << endl << string(20,'-') << endl;
        for (auto t : res) cout << t << " ";
        cout << endl << string(20,'-') << endl;
    }
}
//
// Created by ASUS on 2023/6/25.
//
