#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> data;
    int findLucky(vector<int> &arr) {
        int ans = -1;
        for (auto num: arr) {
            data[num]++;
        }
        for (auto [key,val]: data) {
            if (key == val) {
                ans = max(ans, key);
            }
        }
        return ans;
    }
};


int main() {
    return 0;
}

//
// Created by ASUS on 2025/1/22.
//
