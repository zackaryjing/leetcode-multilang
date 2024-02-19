#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ans;
    int gcd(int a,int b){
        while (a != 0) {
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return b;
    }
    vector<int> addFraction(vector<int> data,int sign){
        int upper = ans[0],lowwer = ans[1];
        ans[1] = lowwer * data[1];
        if (sign == 1){
            ans[0] = upper * data[1] + lowwer * data[0];
        } else if (sign == -1) {
            ans[0] = upper * data[1] - lowwer * data[0];
        }
        int cd = gcd(ans[0],ans[1]);
        ans[0] /= cd;
        ans[1] /= cd;
    }
    string fractionAddition(string expression) {
        ans = {0,1};
        int sign = 1;
        vector<int> whole = {0,1};
        int pos = 0;
        for (int i = 0;i < expression.size();i++){
            cout << i << endl;
            if (expression[i] == '-' or expression[i] == '+') {
                addFraction(whole,sign);
                pos = 0;
                whole = {0,0};
                cout << " 1 <-" << endl;
                if (expression[i] == '-'){
                    sign = -1;
                } else if (expression[i] == '+'){
                    sign = 1;
                }
            } else if (expression[i] != '/'){
                whole[pos] *= 10;
                whole[pos] += expression[i] - '0';
                cout << " 1 <-" << endl;
            } else if (expression[i] == '/'){
                pos += 1;
                cout << " 1 <-" << endl;
            }
        }
        return to_string(ans[0]) + "/" + to_string(ans[1]);
    }
};

int main(){
    Solution test;
    cout << test.fractionAddition("-1/2+1/2") << endl;
    cout << test.fractionAddition("-1/2+1/2+1/3") << endl;
}
//
// Created by ASUS on 2023/8/31.
//
