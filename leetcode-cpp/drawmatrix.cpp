#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> &data){
    int maxum = data[0];
    for (auto i : data){
        if (maxum < i){
            maxum = i;
        }
    }
    return maxum;
}
int main(){

}
//
// Created by ASUS on 2023/5/24.
//
