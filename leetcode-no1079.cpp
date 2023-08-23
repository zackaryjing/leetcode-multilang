#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;


map<int,long long> fact = {{0,1},{1,1},{2,2}};
long long factorial(int n){
    if (fact[n] == 0){
        long long tmp = n * factorial(n-1);
        fact[n] = tmp;
        return tmp;
    } else {
        return fact[n];
    }
}
map<multiset<int>,int> storage;
int calc(multiset<int> para){
    if (storage[para] != 0) {return storage[para];}
    long long total = 1;
    int sum = accumulate(para.begin(), para.end(),0);
    for (int i = 1;i < sum;++i){
        total *= i;
    }
    int ans = factorial(sum);
    for (auto each : para){
        ans /= factorial(each);
    }
    storage[para] = ans;
    return ans;
};

class Solution {
public:
    int ans = 0;
    void bfs(multiset<int> para,vector<int> each){
        if (each.size() == 0){
//            for (auto t : para) cout << t << " " ;
//            cout << endl << string(20,'-') << endl;
            ans += calc(para);
        } else {
            int last = each.back();
            each.pop_back();
            for (int i = 0;i <= last;++i){
                multiset<int> tmp = para;
                tmp.insert(i);
                bfs(tmp,each);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        map<char,int> times;
        for (auto ch : tiles){
            times[ch]++;
        }
        vector<int> data;
        for (auto [_,t] : times) {
            data.push_back(t);
        }
        multiset<int> origin;
        bfs(origin,data);
        return ans - 1;
    }
};

int main(){
    Solution test;
    cout << test.numTilePossibilities("AAB") << endl;
    test.ans = 0;
    cout << test.numTilePossibilities("AAABBC") << endl;
    test.ans = 0;
    cout << test.numTilePossibilities("V") << endl;
//    cout << factorial(10) << endl;
//    set<int> test1 = {1,2,3};
//    cout << calc(test1) << endl;
}
//
// Created by ASUS on 2023/8/14.
//
