#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getSteps(int curr,long n){
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last,n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;

    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0){
            int steps = getSteps(curr,n);
            if (steps <= k) {
                k -= steps;
                curr ++;
            } else {
                curr = curr * 10;
                k--;
            }
        }
        return curr;
    }
};

int main() {
    Solution test;
    cout << test.findKthNumber(96, 37) << endl;
    cout << endl;
    cout << test.findKthNumber(13, 2) << endl;
    cout << endl;
    cout << test.findKthNumber(1, 1) << endl;
    cout << endl;
}

//
// Created by ASUS on 2024/3/23.
//
class Solution2 {
public:
    vector<int> get_composition(int val) {
        int base = 1;
        while (val >= base) {
            base *= 10;
            base++;
        }
        cout << "base: " << base << endl;
        vector<int> res;
        while (base > 0) {
            int tmp;
            tmp = val / base;
            res.push_back(tmp);
            val %= base;
            base /= 10;
        }
        return res;
    }


    int findKthNumber(int n, int k) {
        vector<int> test = get_composition(k);
        for (auto j: test) cout << j << " ";
        cout << endl;
        return 0;
    }
};
