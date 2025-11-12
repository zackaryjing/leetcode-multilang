// problem:  BEGIN
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> times(n, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                times[i + 1] = times[i] + 1;
            } else {
                times[i + 1] - times[i];
            }
        }
        int res = 0;
        int j = 0;
        for (int i = 1; i < n + 1; ++i) {
            j = i;
            while (j < n + 1) {
                int count = times[j] - times[i - 1];
                if (count > (j - i + 1) / 2) {
                    res++;
                } else {
                    j += (j - i + 1) - 2 * count;
                }
                j++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.countMajoritySubarrays(test.countMajoritySubarrays(temp_vector<int>({1,2,2,3}),2));
    test.countMajoritySubarrays(test.countMajoritySubarrays(temp_vector<int>({1,2,2,3}),2));
}
