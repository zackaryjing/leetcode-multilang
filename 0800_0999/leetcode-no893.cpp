#include <utility>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;
class Solution2 {
public:
    int numSpecialEquivGroups(vector<string>& words) {
//        vector<map<char,int>> types;
        set<pair<map<char,int>,map<char,int>>> types;
        for (auto word : words){
            int n = word.size();
//            vector<int> eigen(26);
            map<char,int> eigen1,eigen2;
            for (int j = 0;j < n;j ++){
                char each = word[j];
                if (j % 2) eigen1[each] += 1;
                else eigen2[each] += 1;
            }
            types.insert(make_pair(eigen1,eigen2));
        }
        return types.size();
    }
};


class Solution3 {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<vector<int>> types;
        for (auto word : words){
            vector<int> eigen(52);
            for (int j = 0;j < word.size();j ++){
                eigen[word[j] - 'a' + (j % 2) * 26]++;
            }
            types.insert(eigen);
        }
        return types.size();
    }
};
int main(){
    Solution test;
    vector<string> eg1 = {"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    cout << test.numSpecialEquivGroups(eg1) << endl;
    vector<string> eg2 = {"abc","acb","bac","bca","cab","cba"};
    cout << test.numSpecialEquivGroups(eg2) << endl;

}

//
// Created by ASUS on 2023/7/16.
//
