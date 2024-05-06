#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int example1;
int guess(int num){
    if (num > example1) {
        return -1;
    } else if (num < example1) {
        return 1;
    } else {
        return 0;
    }
};

class Solution {
public:
    int guessNumber(int n) {
        long long left = 0,right = n,mid,res;
        mid = (left + right + 1) / 2;
        while ((res = guess(mid) ) != 0 && left <= n && right >= 0){
//             cout << left << " " << right << endl;
            if (res == 1){
                left = mid;
                mid = (left + right + 1) / 2;
            } else {
                right = mid - 1;
                mid = (left + right + 1) / 2;
            }
        };
        return (int)mid;
    }
};
int main(){
    Solution test;
    srand(time(nullptr));
    example1 = rand();
    cout << example1 << endl;
    cout << test.guessNumber(example1) << endl;
//    example1 = 1;
//    cout << test.guessNumber(example1) << endl;
}
//
// Created by ASUS on 2023/6/16.
//
