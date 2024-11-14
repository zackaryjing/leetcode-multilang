#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

const int N = 100001;
bool isPrime[N];
int init = []() {
    fill(begin(isPrime), end(isPrime), true);
    isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();

// 更新1素数筛
// update2: adjacent
//

class Solution {
private:
//    set<int> vis, nodes;
//    map<int, vector<int>> adjacent;
    vector<vector<int>> adjacent;
//    map<int, bool> prime_res;
    vector<int> primes;
public:
    void dfs(int src, int pre, vector<int> &seen) {
        seen.push_back(src);
        for (auto adj_node: adjacent[src]) {
            if (!isPrime[adj_node] and adj_node != pre) {
                dfs(adj_node, src, seen);
            }
        }
    }

    long long countPaths(int n, vector<vector<int>> &edges) {
        adjacent.resize(n + 1);
        for (auto edge: edges) {
//            nodes.insert(edge[0]), nodes.insert(edge[1]);
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
        }
        //cout << "Nodes.size():" << nodes.size() << endl;
//        for (int node = 1; node <= n; node++) {
//            isPrime[node] = is_prime(node);
//            if (isPrime[node]) {
//                primes.push_back(node);
//            }
//        }
//        cout << "Primes_size:" << isPrime.size() << endl;

        vector<int> seen;
        long long res = 0;
        vector<long long> count(n + 1, 0);
        for (int node = 1; node <= n; node++) {
            if (!isPrime[node]) {
                continue;
            }
            long long cur = 0;
            for (auto adj_node: adjacent[node]) {
                if (isPrime[adj_node]) {
                    continue;
                }
                if (count[adj_node] == 0) {
                    seen.clear();
                    dfs(adj_node, 0, seen);
                    long long cnt = seen.size();
//                    cout << "node:" << node << " " << seen.size() << "<-" << endl;
//                    for (auto k : seen) cout << k << " " ;
//                    cout << endl;
                    for (int k: seen) {
                        count[k] = cnt;
                    }
                }
                res += count[adj_node] * cur;
                cur += count[adj_node];
            }
            res += cur;
        }
        //cout << string(10, '-') << endl;
        return res;
    }
};

int main() {
    Solution test;
    vector<vector<int> > edges1 = {{1, 2},
                                   {1, 3},
                                   {2, 4},
                                   {2, 5}};
    cout << test.countPaths(5, edges1) << endl;
    Solution test2;
    vector<vector<int> > edges2 = {{1, 2},
                                   {1, 3},
                                   {2, 4},
                                   {3, 5},
                                   {3, 6}};
    cout << test2.countPaths(6, edges2) << endl;
    Solution test3;
    vector<vector<int> > edges3 = {{1, 2},
                                   {4, 1},
                                   {3, 4}};
    cout << test3.countPaths(4, edges3) << endl;
}
//
// Created by ASUS on 2024/2/27.
//




//int dfs(int src,int pre) {
//    vector<int> ways; // 代表不同的路的可行解的个数
//    // 920
//    for (auto adj_node: adjacent[src]) {
//        if (not isPrime[adj_node] and adj_node != pre) {
//            ways.push_back(dfs(adj_node,src));
//        }
//    }
//    if (not isPrime[src]) {
//        return accumulate(ways.begin(), ways.end(), 1);
//    } else {
//        int ans = 0;
//        for (int i = 0; i < ways.size(); ++i) {
//            for (int j = i + 1; j < ways.size(); ++j) {
//                ans += ways[i] * ways[j];
//            }
//        }
//        ans = accumulate(ways.begin(), ways.end(), ans);
//        return ans;
//    }
//}