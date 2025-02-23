#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Solution {
public:
    int maxDistance(vector<vector<int> > &arrays) {
        int n = arrays.size();
        int min_num_old = arrays[0][0];
        int max_num_old = arrays[0].back();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            const auto &arr = arrays[i];
            ans = max(ans, max(arr.back() - min_num_old, max_num_old - arr[0]));
            min_num_old = min(min_num_old, arr[0]);
            max_num_old = max(max_num_old, arr.back());
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDistance(*make_unique<vector<vector<int> > >(vector<vector<int> >{{1, 2, 3}, {4, 5}, {1, 2, 3}})) <<
            endl;
    cout << test.maxDistance(*make_unique<vector<vector<int> > >(vector<vector<int> >{{1}, {1}})) <<
            endl;
    cout << test.maxDistance(*make_unique<vector<vector<int> > >(vector<vector<int> >{{1, 5}, {3, 4}})) <<
            endl;
    cout << test.maxDistance(*make_unique<vector<vector<int> > >(vector<vector<int> >{
                {-8, -7, -7, -5, 1, 1, 3, 4}, {-2}, {-10, -10, -7, 0, 1, 3}, {2}
            })) <<
            endl;
}


//
// Created by ASUS on 2025/2/19.
//
