#include <iostream>
#include <vector>

class Solution {
public:
    bool divisorGame(int n) {
        return !(n &0x1U);
//        return n & (-1U - 1)
    }
};

using namespace std;

int main() {
    Solution test;
    cout << test.divisorGame(2) << endl;
    cout << test.divisorGame(3) << endl;
    cout << test.divisorGame(4) << endl;
    cout << test.divisorGame(5) << endl;
    cout << !(-2 & 0x1) << endl;
    cout << !(-2 & 0x1U) << endl;
    cout << (1 & ((unsigned )(-1) - 1)) << endl;
    cout << ((unsigned )(-1) - 1) << endl;
    cout << (-1U - 1) << endl;
    cout << (int)(-1U - 1) << endl;
    cout << (int)((unsigned )(-1) - 1) << endl;
}
