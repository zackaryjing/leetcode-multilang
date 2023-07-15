#include <iostream>
#include <cmath>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>

using namespace std;
int main(){
    map<int,int> data;
    data.insert({1,2});
    data.insert({1,3});
    for (auto j : data) cout << j.first << " " << j.second << endl;
    cout << " end " ;

}
//
// Created by ASUS on 2023/7/7.
//
