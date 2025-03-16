#include <iostream>
#include <map>

using namespace std;

int main() {
    int i = 0;
    int n = 10;
    for (; i < n; i++) {
        if (i == 0) {
            break;
        }
    }
    cout << i << endl;
    return 0;
}
