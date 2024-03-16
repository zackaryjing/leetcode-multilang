#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <vector>
using namespace std;

bool is_prime(int num) {
    if (num == 1) { return false; }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    for (int i = 1;i < 10000;i++){
        if (is_prime(i)) {
            cout << i << ",";
        }
    }
}