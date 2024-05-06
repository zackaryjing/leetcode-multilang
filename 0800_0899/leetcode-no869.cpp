#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        ;
    }
};

int main(){
    long long tmp = 1;
    while ((1 << tmp) < 1e10){
        cout << (1 << tmp) << endl;
        tmp ++;
    }
//    for (long long i = 0;((1 << i) < 10e9);i++){
//        cout << (1 << i) << endl;
//    }
}