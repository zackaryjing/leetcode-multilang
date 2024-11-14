#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());
//        int left = max(accumulate(piles.begin(),piles.end(),0LL) / h,1LL);
        int left = accumulate(piles.begin(),piles.end(),0LL) / h;
        int candidate = right;
        int mid;
        while (right != left) {
            mid = (right + left + 1) / 2;
//            cout << left << " " << mid << " " << right << endl;
            int total = 0;
            for (auto pile : piles){
                total += ceil((double)pile / mid);
            }
//            cout << total << " " << endl;
            if (total > h) {
                left = mid;
            } else if (total < h) {
                candidate = min(candidate,mid);
                right = mid - 1;
            } else {
                right = mid - 1;
                candidate = min(candidate,mid);
            }
            if (mid == 0) return 1;
        }
        int total = 0;
        mid = (right + left + 1) / 2;
        for (auto pile : piles){
            total += ceil((double)pile / mid);
        }
//        cout << left << " " << mid << " " << right << endl;
        if (total == h) candidate = min(mid,candidate);
        return candidate;
    }
};

int main(){
    Solution test;
    vector<int> eg8 = {312884470};
    cout << test.minEatingSpeed(eg8,968709470) << " <-<< "<< endl;
    vector<int> eg7 = {1000000000};
    cout << test.minEatingSpeed(eg7,2) << " <-<< "<< endl;
    vector<int> eg6 = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    cout << test.minEatingSpeed(eg6,823855818) << " <-<< "<< endl;
    vector<int> eg5 = {312884470};
    cout << test.minEatingSpeed(eg5,312884469) << " <-<< "<< endl;
    vector<int> eg4 = {2,2};
    cout << test.minEatingSpeed(eg4,2) << " <-<< " << endl;
    vector<int> eg1 = {3,6,7,11};
    cout << test.minEatingSpeed(eg1,8) << " <-<< " << endl;
    vector<int> eg2 = {30,11,23,4,20};
    cout << test.minEatingSpeed(eg2,5) << " <-<< " << endl;
    vector<int> eg3 = {30,11,23,4,20};
    cout << test.minEatingSpeed(eg2,6) << " <- -<< " << endl;

}
//
// Created by ASUS on 2023/8/9.
//
