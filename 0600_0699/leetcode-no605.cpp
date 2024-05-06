#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int consist = 1,ans = 0;
        for (auto i : flowerbed){
            if (i == 0){
                consist ++;
            } else {
                ans += (consist - 1) / 2;
                consist = 0;
            }
        }
        ans += consist / 2;
        if (ans < n) {
            return false;
        } else {
            return true;
        }
    }
};

int main(){
    Solution test;
    vector<int> arr1 = {1,0,0,0,1};
    cout << test.canPlaceFlowers(arr1,1) << endl;
    cout << test.canPlaceFlowers(arr1,2) << endl;
    vector<int> arr2 = {0,0,1,0,1};
    vector<int> arr3 = {0,0,0,1,0,1};
    cout << test.canPlaceFlowers(arr2,1) << endl;
    cout << test.canPlaceFlowers(arr3,2) << endl;
    vector<int> arr4 = {1,0,0,0,1,0,0};
    cout << test.canPlaceFlowers(arr4,2) << endl;
}
//
// Created by ASUS on 2023/6/29.
//
