#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class NumArray {
public:
    vector<int> segmentTree;
    int n;

    void build(int node, int s, int e, vector<int> &nums) {
        if (s == e) {
            segmentTree[node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(node * 2 + 1, s, m, nums);
        build(node * 2 + 2, m + 1, e, nums);
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    void change(int index, int val, int node, int s, int e) {
        if (s == e) {
            // cout << node << endl;
            segmentTree[node] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            change(index, val, node * 2 + 1, s, m);
        } else {
            change(index, val, node * 2 + 2, m + 1, e);
        }
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    int range(int left, int right, int node, int s, int e) {
        if (left == s and right == e) {
            return segmentTree[node];
        }
        int m = s + (e - s) / 2;
        if (right <= m) {
            return range(left, right, node * 2 + 1, s, m);
        } else if (left > m) {
            return range(left, right, node * 2 + 2, m + 1, e);
        } else {
            return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
        }
    }

    NumArray(vector<int> &nums) {
        n = nums.size();
        segmentTree = vector<int>(n * 4, 0);
        build(0, 0, nums.size() - 1, nums);
    }

    void update(int index, int val) { change(index, val, 0, 0, n - 1); }

    int sumRange(int left, int right) { return range(left, right, 0, 0, n - 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


int main() {
    NumArray test(*make_unique<vector<int>>(vector{1, 3, 5}));
    cout << test.sumRange(0, 2) << endl;;
    test.update(1, 2);
    cout << test.sumRange(0, 2) << endl;;
}

//
// Created by ASUS on 2025/2/10.
//
