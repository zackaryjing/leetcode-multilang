#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int last = nums[0]+1;
        int times = 0;
        for (auto it = nums.begin(); it != nums.end();) {
//            cout << times << endl;
            times += 1;
            if (*it == last) {
                it = nums.erase(it);
            } else {
                last = *it;
                ++it;
            }
        }
//        for (auto it = nums.begin(); it != nums.end();) {
//            times += 1;
//            cout << times << endl;
//            if (*it == last) {
//                cout << "it is " << *it << endl;
//                cout << "rm " << *it << endl;
//                nums.erase(it);
//                it = nums.begin();
//            } else {
//                last = *it;
//                cout << "last = " << last << endl;
//                ++it;
//            }
//        }
        return nums.size();
    }
};
int main(){
    vector<int> test = {1,1,1,2,2,3,3,4,5,6,7,7};
    Solution t;
    cout << t.removeDuplicates(test) << endl;
    cout << "ans:" << endl;
    for (auto it = test.begin();it != test.end();){
        cout << *it << endl;
        ++it;
    }
}
//
// Created by ASUS on 2023/4/20.
//
