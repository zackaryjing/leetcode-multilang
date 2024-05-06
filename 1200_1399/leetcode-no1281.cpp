#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1,sum = 0;
        while (n > 0){
            mul *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return mul - sum;
    }
};

int main(){
    Solution test;
    cout << test.subtractProductAndSum(234) << endl;
}
//
// Created by ASUS on 2023/7/2.
//
