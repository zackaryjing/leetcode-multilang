#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // int intLength = 5;
    int intLength = 9;
    bool isOdd = intLength & 1;
    auto reverse = [&](int num) {
        int ans = pow(10, intLength / 2) * num;
        if (isOdd) {
            num /= 10;
        }
        int right = 0;
        while (num > 0) {
            right *= 10;
            right += num % 10;
            num /= 10;
        }
        return ans + right;
    };
    cout << reverse(12345) << endl;
}
