#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(),satisfy = 0;
        for (int i = 0;i < n;i++){
            if (grumpy[i] == 0){
                satisfy += customers[i];
                customers[i] = 0;
            }
        }
        int right = minutes,total = 0;
        for (int i = 0;i < minutes;i++){
            total += customers[i];
        }
        int toadd = total;
        for (int i = 0;i + right < n;i ++){
            total -= customers[i];
            total += customers[i + right];
            if (total > toadd){
                toadd = total;
            };
        }
        return toadd + satisfy;
    }
};

int main(){
    Solution test;
    vector<int> eg11 = {1,0,1,2,1,1,7,5};
    vector<int> eg12 = {0,1,0,1,0,1,0,1};
    cout << test.maxSatisfied(eg11,eg12,3) << endl;
}


//
// Created by ASUS on 2023/7/11.
//
