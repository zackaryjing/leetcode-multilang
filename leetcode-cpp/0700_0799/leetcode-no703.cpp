#include <iostream>
#include <deque>
#include <memory>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class KthLargest {
    // 和官解有轻微出入
public:
    priority_queue<int, vector<int>, greater<int> > data;
    int _k;

    KthLargest(int k, vector<int> &nums) {
        _k = k;
        data = priority_queue<int, vector<int>, greater<int> >(nums.begin(), nums.end());
    }

    int add(int val) {
        data.push(val);
        while (data.size() > _k) {
            data.pop();
        }
        return data.top();
    }
};


class KthLargest_old {
    // 应该使用堆，堆能够更快的维护只需要知道最大值的解构。
    // 同时由于这道题只需要实现add，也就是说不会删除元素，所以我们可以不保存处于_k堆外的元素
public:
    multiset<int> data;
    int _k;

    KthLargest_old(int k, vector<int> &nums) {
        _k = k;
        data = multiset(nums.begin(), nums.end());
    }

    int add(int val) {
        data.insert(val);
        return *(prev(data.end(), _k));
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char *argv[]) {
    KthLargest test = KthLargest(3, *make_unique<vector<int> >(vector{4, 5, 8, 2}));
    cout << test.add(3) << endl;
    cout << test.add(5) << endl;
    cout << test.add(10) << endl;
    cout << test.add(9) << endl;
    cout << test.add(4) << endl;
}


//
// Created by ASUS on 2025/2/17.
//
