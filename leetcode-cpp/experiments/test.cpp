#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include <ranges>
#include <algorithm>


using namespace std;


int main() {
    vector test = {1, 3, 5, 7, 9, 11};
    int t = 4;
    cout << *ranges::lower_bound(test, t, [](const int &a, const int &b) { return a < b; }) << endl;
    cout << *ranges::upper_bound(test, t, [](const int &a, const int &b) { return a <= b; }) << endl;


}
