#include <iostream>
#include <vector>

using namespace std;
class Solution2 {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        if (n < 2){
            return arr;
        }
        for (int i = n - 1;i >= 1;i--){
            if (arr[i] < arr[i - 1]){
                swap(arr[i],arr[i-1]);
                return arr;
            }
        }
        return arr;
    }
};

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        if (n < 2){
            return arr;
        }
        for (int i = n - 2;i >= 0;i--){
            if (arr[i] < arr[i + 1]) continue;
            for (int j = n - 1;j > i;j--){
                if (arr[i] > arr[j]){
                    if (arr[j] != arr[j - 1]) {
                        swap(arr[i],arr[j]);
                        return arr;
                    } else {
                        continue;
                    }
                }
            }
        }
        return arr;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {3,2,1};
    vector<int> res = test.prevPermOpt1(eg1);
    for (auto i : res) cout << i << " ";
    cout << endl;
    vector<int> eg2 = {1,1,5};
    res = test.prevPermOpt1(eg2);
    for (auto i : res) cout << i << " ";
    cout << endl;
    vector<int> eg3 = {1,9,4,6,7};
    res = test.prevPermOpt1(eg3);
    for (auto i : res) cout << i << " ";
    cout << endl;
    vector<int> eg4 = {3,1,1,3};
    res = test.prevPermOpt1(eg4);
    for (auto i : res) cout << i << " ";
    cout << endl;
}

//
// Created by ASUS on 2023/7/11.
//
