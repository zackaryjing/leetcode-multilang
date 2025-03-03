#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <set>


using namespace std;

class Solution2 {
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries) {
        map<int, int> times;
        map<int, set<int>> pos;
        vector<long long> ans;
        long long total = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            times[nums[i]]++;
            pos[nums[i]].insert(i);
        }
        for (auto query: queries) {
            int decrease = 0;
            int index = query[0];
            int k = query[1];
//            cout << endl;
//            cout << index << " " << k << " <-> ";
            if (times[nums[index]] != 0 and pos[nums[index]].find(index) == pos[nums[index]].end()) {
//                cout << "special" << nums[index] << " " << times[nums[index]] << endl;
                times[nums[index]]--;
                decrease += times[nums[index]];
                if (times[nums[index]] == 0) {
                    times.erase(nums[index]);
                    pos.erase(nums[index]);
                }
            } else {
                times.erase(nums[index]);
            }
            cout << " while :";
//            cout << times[1] << endl;
            cout << " begin " << times.begin()->first << " ," << times.begin()->second << "| ";
            while (k > 0) {
//                cout  << " k: " << k << " ";
//                cout << " begin " << times.begin()->first  << " ," << times.begin()->second << "| ";
                if (times.begin()->second > k) {
                    times.begin()->second -= k;
                    decrease += k * times.begin()->first;
                    k = 0;
                } else {
                    cout << " case 2 " << " ";
                    k -= times.begin()->second;
                    times.erase(times.begin()->first);
                    decrease += k * times.begin()->first;
                    times.erase(times.begin()->first);
                }
            }
            total -= decrease;
            ans.push_back(total);
        }
        return ans;
    }
};

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries) {
        map<int, set<int>> pos;
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].insert(i);
        }

        long long total = accumulate(nums.begin(), nums.end(), (long long)0);
        cout << "?" << endl;
        vector<long long> ans;
        for (auto query: queries) {
            long long decrease = 0;
            int index = query[0];
            int k = query[1];
//            cout << k << endl;
            int num = nums[index];
            if (pos[num].find(index) != pos[num].end()) {
                decrease += num;
//                cout << num << endl;
                pos[num].erase(index);
                if (pos[num].empty()) {
                    pos.erase(num);
                }
            } else if (pos[num].empty()) {
                pos.erase(num);
            }
//            cout << ":";
            while (k > 0) {
//                cout << k << " ";
//                cout << pos.begin()->first << " " << pos.begin()->second.size() << " ;";
                if (pos.empty()) {
                    break;
                }
                if (pos.begin()->second.empty()) {
                    pos.erase(pos.begin()->first);
                }
                if (pos.empty()) {
                    break;
                }
                decrease += pos.begin()->first;
//                cout << pos.begin()->first << endl;
                int smallest = *pos.begin()->second.begin();
                pos.begin()->second.erase(smallest);
                k--;
            }
//            cout << endl;
            total -= decrease;
            ans.push_back(total);
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums1 = {1, 2, 2, 1, 2, 3, 1};
    vector<vector<int> > queries1 = {{1, 2},
                                     {3, 3},
                                     {4, 2}};
    vector<long long> res1 = test.unmarkedSumArray(nums1, queries1);
//    cout << endl;
//    cout << res1.size() << endl;
    for (auto j: res1) {
        cout << j << " " << endl;
    }
    cout << endl;
}
//
// Created by ASUS on 2024/3/16.
//



