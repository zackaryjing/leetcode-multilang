#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

vector<int> getdone(int n,int m,int first,int second,vector<int> &nums1,vector<int> &nums2){
    multiset<int> s1(nums1.begin(), nums1.begin() + (n - first + 1));
    multiset<int> s2(nums2.begin(), nums2.begin() + (m - second + 1));
//    for (auto each : s1) cout << each << " " ;
//    cout << endl;
//    for (auto each : s2) cout << each << " " ;
//    cout << endl;
    vector<int> ans;
    int i = n - first + 1,j = m - second + 1;
    while (i <= n or j <= m){
//        cout << i << "(" << nums1[i] << ")" <<" <-> " << j << "(" << nums2[j] << ")" << endl;
        if (((i <= n and j <= m) and (*s1.rbegin() > *s2.rbegin())) or (i <= n and j == m + 1)){
            ans.push_back(*s1.rbegin());
//            s1.erase(ans.back());
//            cout << "first" << endl;
            auto pos = find(nums1.begin(), nums1.end(),ans.back());
            if (i != n){
                s1 = multiset(pos + 1, nums1.begin() + i + 1);
            }
            ++i;
        } else if (((i <= n and j <= m) and *s1.rbegin() <= *s2.rbegin()) or (i == n + 1 and j <= m)){
            ans.push_back(*s2.rbegin());
//            cout << "second" << endl;
            auto pos = find(nums2.begin(), nums2.end(),ans.back());
            if (j != m){
                s2 = multiset(pos + 1, nums2.begin() + j + 1);
            }
            ++j;
        }
    }
    return ans;
}

int main(){
    vector<int> eg3 = {3, 4, 6, 5};
    vector<int> eg4 = {9, 1, 2, 5, 8, 3};
    vector<int> res2 = getdone(4,6,2,3,eg3,eg4);
    for (auto k : res2) cout << k << " ";
    cout << endl << string(20,'-') << endl;
    vector<int> eg1 = {1,3,8,6,5,2,9};
    vector<int> eg2 = {7,6,8};
    vector<int> res1 = getdone(7,3,3,2,eg1,eg2);
    for (auto k : res1) cout << k << " ";
}
//
// Created by ASUS on 2023/8/11.
//
