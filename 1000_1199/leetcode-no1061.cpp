#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    vector<int> parent = vector<int>(26);
    Solution() {
        int start = 0;
        generate(parent.begin(),parent.end(),[&start](){return start++;});
    }
    int tofind(int index){
//        cout << "that" << endl;
        if (index != parent[index]){
            parent[index] = tofind(parent[index]);
        }
        return parent[index];
    }
    void uni(int node1,int node2){
//        cout << "this" << endl;
        parent[tofind(node1)] = tofind(node2);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for (int i = 0;i < n;i++){
//            cout << s1[i] << " " << s2[i] << endl;
            if (tofind(s1[i] - 'a') != tofind(s2[i] - 'a')){
                uni(s1[i] - 'a',s2[i] - 'a');
            }
        }
        for (int i = 0;i < 26;i++){
            parent[i] = tofind(i);
        }
        string ans;
        map<int,char> data;
        for (int pos = 0 ;pos < 26;pos ++){
//            cout << parent[pos] << endl;
            data.insert({parent[pos],'a' + pos});
        }
//        for (auto [h,m] : data) cout << h << " " << m << endl;
        for (auto k : baseStr){
            ans += data[parent[k - 'a']];
        }
//        for (auto j : "abcdefghijklmnopqrstuvwxyz") cout << setw(3) << j << "";
//        cout << endl;
//        for (auto j : parent) cout << setw(3) << j << "";
        return ans;
//        return "asfd";
    }
};

int main(){
    Solution test;
    cout << test.smallestEquivalentString("parker","morris","parser") << endl;
    return 0;
}

//        int n = s1.size();
//        map<char,set<char>> relation;
//        for (int i = 0;i < n;i ++){
//            relation[s1[i]].insert(s2[i]);
//        }

//
// Created by ASUS on 2023/7/14.
//
