#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        if (count(start.begin(), start.end(),'L') != count(end.begin(),end.end(),'L'))
            return false;
        string copy1 = start,copy2 = end;
        auto it1 = remove(copy1.begin(), copy1.end(),'X');
        auto it2 = remove(copy2.begin(), copy2.end(),'X');
        copy1.erase(it1,copy1.end());
        copy2.erase(it2,copy2.end());
        if (copy1 != copy2) return false;
        //    return false;
        // cout << start << endl;
        int first = 0,second = 0,n = start.size();
        while (first < n && second < n){
            int found = 0;
            while (first < n && start[first] != 'L') first++;
            while (second < n && end[second] != 'L') second++;
            if (first < second) return false;
            first++;
            second++;
        }
        // cout << "here" << endl;
        first = n - 1,second = n - 1;
        while (first >= 0 && second >= 0){
            // cout << first << " " << second << endl;
            while (first >= 0 && start[first] != 'R') first--;
            while (second >= 0 && end[second] != 'R') second--;
            if (first > second) return false;
            first--;
            second--;
        }
        return true;
    }
};


int main(){
    Solution test;
    cout << test.canTransform("RXXLRXRXL","XRLXXRRLX") << endl;
    cout << string(20,'-') << endl;
    cout << test.canTransform("X","L") << endl;
    cout << string(20,'-') << endl;
    cout << test.canTransform("RL","LR") << endl;
    string aaa = "aaasdf";
    auto it = remove(aaa.begin(), aaa.end(),'a');
    aaa.erase(it,aaa.end());
    cout << aaa << " --- "<< endl;
    // cout << count(aaa.begin(), aaa.end(),'a');

}
//
// Created by ASUS on 2023/6/22.
//
