// problem: NAME
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int numberOfComponents(vector<vector<int>> &properties, int k) {
        int n = properties.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<bitset<100>> cnts(n);
        for (int i = 0; i < n; i++) {
            for (int num: properties[i]) {
                cnts[i].set(num - 1);
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((cnts[i] & cnts[j]).count() >= k) {
                    unionSets(i, j);
                }
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                components++;
            }
        }
        return components;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int>> eg1 = {{1, 2}, {1, 1}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    cout << test.numberOfComponents(eg1, 1) << endl;
    vector<vector<int>> eg2 = {{1,2,3},{2,3,4},{4,3,5}};
    cout << test.numberOfComponents(eg2, 2) << endl;

}


//
// Created by ASUS on 2025/3/23.
//
