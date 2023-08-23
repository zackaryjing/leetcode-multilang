#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main(){
    vector<int> eg3;
    vector<int> eg1 = {1,2};
    vector<int> eg2 = {3,2};
    vector<vector<int>> both = {eg1,eg2,eg3};
    vector<int> res = *min_element(both.begin(), both.end());
    cout << res.size() << endl;
    for (auto j : res) cout << j << " " ;
    cout << endl;
    cout << (eg1 > eg2) << endl;

}
//
// Created by ASUS on 2023/7/7.
//
