#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(),[](const auto &a,const auto &b){
            return (a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]));
        });
        vector<int> f = {envelopes[0][1]};
        for (int i = 0;i < n;++i){
            if (int num = envelopes[i][1];num > f.back()){
                f.push_back(num);
            } else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return (int)f.size();
    }

};

class Solution6 {
    public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),[](vector<int>&a,vector<int> &b){
            return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]);
        });
        //for (auto t : envelopes) cout << t[0] << " " << t[1] << endl;
        int n = envelopes.size();
        vector<int> f(n);
        f[0] = 0;
        int biggest = 1;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < i;j++){
                if (envelopes[i][1] > envelopes[j][1])
                f[i] = max(f[i],f[j]);
            }
            f[i]++;
        }
        return *max_element(f.begin(), f.end());
    }
};

int main(){
    // Ask on stackoverflow
    Solution test;
    vector<vector<int>> eg1 = {{5,4},{6,4},{6,7},{2,3}};
    cout << test.maxEnvelopes(eg1) << endl;
    cout << string(60,'-') << endl;
    vector<vector<int>> eg2 = {{5,4},{5,6},{6,7},{2,3}};
    cout << test.maxEnvelopes(eg2) << endl;
}

class Solution3 {
public:
    pair<int,int> getIntersection(int xi,int xj,int yi,int yj){
        pair<int,int> res = make_pair(max(xi,yi),max(xj,yj));
        return res;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        map<pair<int,int>,int> data;
        for (auto envelope : envelopes){
            for (auto [area,times] : data){
                pair<int,int> inter  = getIntersection(area.first,area.second,envelope[0] + 1,envelope[1] + 1);
                data[inter]++;
            }
            data[make_pair(envelope[0] + 1,envelope[1] + 1)]++;
        }
        for (auto [area,times] : data){
            cout << area.first << " " << area.second << "," << times << endl;
        }
    }
};
class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int maxi = 0,maxj = 0;
        for (auto envelop : envelopes){
            maxi = max(envelop[0],maxi);
            maxj = max(envelop[1],maxj);
        }
        vector<vector<int>> dp(maxi,vector<int>(maxj));
    }
};

//
// Created by ASUS on 2023/8/12.
//
// List-selectPreviousColumn