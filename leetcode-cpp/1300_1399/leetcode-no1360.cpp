#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> starts;
        for (auto& j : paths){
            starts.insert(j[0]);
        }
        for (auto& j : paths){
            int res = starts.erase(j[1]);
            if (res == 0){
                return j[1];
            }
        }
        return "";
    }
};

int main(){
    Solution test;
    vector<vector<string>> eg1 = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    cout << test.destCity(eg1) << endl;
    vector<vector<string>> eg2 = {{"B","C"},{"D","B"},{"C","A"}};
    cout << test.destCity(eg2) << endl;
}
//
// Created by ASUS on 2023/7/24.
//
