#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int t = (int)sqrt(area);
        if (t * t == area){
            return {t,t};
        } else {
            int k = t;
            while ((area / k) * k != area){
                k --;
            }
            return {area / k,k};
        }
    }
};

int main(){
    Solution test;
    vector<int> h;
    h = test.constructRectangle(4);
    cout << h[0] << " " << h[1] << endl;
    h = test.constructRectangle(37);
    cout << h[0] << " " << h[1] << endl;
    h = test.constructRectangle(122122);
    cout << h[0] << " " << h[1] << endl;
}
//
// Created by ASUS on 2023/7/30.
//
