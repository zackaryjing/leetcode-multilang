#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

//class Solution2 {
//public:
//    int getpos(vector<string>& from,string target){
//        auto pos = find(from.begin(),from.end(),target);
//        return distance(from.begin(),pos);
//    };
//    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
//        unordered_set<string> choice1(list1.begin(),list1.end());
//        unordered_set<string> choice2(list2.begin(),list2.end());
//        vector<string> res(list1.size()+list2.size());
//        auto iter = set_intersection(choice1.begin(),choice1.end(),choice2.begin(),choice2.end(),res.begin());
//        res.resize(iter - res.begin());
//        cout << res.size() << endl;
//
//        vector<string> ans;
//        int minpos = INT_MAX;
//        for (auto i : res) {
//            if (getpos(list1,i) + getpos(list2,i) == minpos){
//                ans.push_back(i);
//            } else if (getpos(list1,i) + getpos(list2,i) < minpos){
//                ans.clear();
//                ans.push_back(i);
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    int getpos(vector<string>& from,string target){
        auto pos = find(from.begin(),from.end(),target);
        return distance(from.begin(),pos);
    };
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        vector<string> l1(list1.size());
        l1.assign(list1.begin(),list1.end());
        sort(l1.begin(),l1.end());
        vector<string> l2(list1.size());
        l2.assign(list2.begin(),list2.end());
        sort(l2.begin(),l2.end());

        // for (auto i : l1) cout << i << " ";
        // cout << endl;
        // for (auto i : list1) cout << i << " ";
        // cout << endl;

        vector<string> res(l1.size()+l2.size());
        auto iter = set_intersection(l1.begin(),l1.end(),l2.begin(),l2.end(),res.begin());
        res.resize(iter - res.begin());
        // cout << res.size() << endl;
        vector<string> ans;
        int minpos = INT_MAX;
        for (auto i : res) {
            if (getpos(list1,i) + getpos(list2,i) == minpos){
                ans.push_back(i);
            } else if (getpos(list1,i) + getpos(list2,i) < minpos) {
                // cout << ans.size() << " ";
                ans.clear();
                // cout << ans.size() << endl;
                // cout << "tryed " << i << endl;
                ans.push_back(i);
                minpos = getpos(list1, i) + getpos(list2, i);
            }
        }
        return ans;
    }
};


int main() {
    Solution test;
    vector<string> t1, t2, s1, s2;
    t1 = {"asdf","asdf,","asdfaslk","dasdf","lll","Shogun", "Tapioca Express", "Burger King", "KFC", "lll"};
    t2 = {"Piatti", "The Grill at Torrey Pines", "lll", "Hungry Hunter Steakhouse", "Shogun", "KFC"};
    s1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    s2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> res = test.findRestaurant(t1, t2);
    // vector<string> res = test.findRestaurant(s1, s2);
    for (auto i : res) cout << i << " ";
}


//vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
//    vector<string> res(list1.size() + list2.size());
//    auto iter = set_intersection(list1.begin(),list1.end(),list2.begin(),list2.end(),res.begin());
//    for (auto i : res) cout << i << " ";
//    return res;
//}


/*
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> index;
        for (int i = 0;i < list1.size();i++){
            index[list1[i]] = i;
        }
        vector<string> ret;
        int indexSum = INT_MAX;
        for (int i = 0;i < list2.size();i++){
            if (index.count(list2[i]) > 0){
                int j = index[list2[i]];
                if (i + j < indexSum){
                    ret.clear();
                    ret.push_back(list2[i]);
                    indexSum = i + j;
                } else if (i + j == indexSum){
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};
*/
//
// Created by ASUS on 2023/6/17.
//
