#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int min_num = nums[0];
        int max_num = nums[0];
        for (auto k: nums) {
            max_num = max(max_num, k);
            min_num = min(min_num, k);
        }
        int d = max(1, (max_num - min_num) / (n - 1));
        int bucket_size = (max_num - min_num) / d + 1;
        // cout << "size: " << d << endl;
        vector<pair<int, int> > bucket(bucket_size, {-1, -1});
        for (const auto &k: nums) {
            int pos = (k - min_num) / d;
            if (bucket[pos].first == -1) {
                bucket[pos].first = k;
                bucket[pos].second = k;
            }
            bucket[pos].first = min(bucket[pos].first, k);
            bucket[pos].second = max(bucket[pos].second, k);
        }

        // for (auto [f,s]: bucket) {
        //     cout << f << ", " << s << endl;
        // }

        int ans = 0;
        int i = 0;
        while (i < bucket_size - 1) {
            while (bucket[i].first == -1) {
                i++;
            }
            int j = i + 1;
            while (bucket[j].first == -1) {
                j++;
            }
            ans = max(ans, bucket[j].first - bucket[i].second);
            i = j;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumGap(*make_unique<vector<int> >(vector{3, 6, 9, 1})) << endl;;
    cout << test.maximumGap(*make_unique<vector<int> >(vector{0, 0, 0})) << endl;;
}


//
// Created by ASUS on 2025/2/16.
//
