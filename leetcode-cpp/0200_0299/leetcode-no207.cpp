#include <iostream>
#include <set>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
private:
    vector<vector<int> > edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};


class Solution2 {
    // 效率很低，为什么呢？
private:
    set<int> path;
    set<int> vis;
    set<int> total;
    unordered_map<int, vector<int> > graph;

    bool explore(int cur) {
        vis.insert(cur);
        path.insert(cur);
        for (auto child: graph[cur]) {
            if (path.contains(child)) {
                return false;
            } else {
                if (not vis.contains(child)) {
                    if (not explore(child)) {
                        return false;
                    }
                }
            }
        }
        path.erase(cur);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
        for (auto rule: prerequisites) {
            total.insert(rule[0]);
            graph[rule[0]].push_back(rule[1]);
        }
        while (true) {
            erase_if(total, [&](int x) { return vis.count(x); });
            if (total.empty()) {
                break;
            } else {
                if (not explore(*total.begin())) {
                    return false;
                };
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canFinish(2, *make_unique<vector<vector<int> > >(vector<vector<int> >{{1, 0}, {0, 1}})) << endl;;
    cout << test.canFinish(2, *make_unique<vector<vector<int> > >(vector<vector<int> >{{1, 0}, {0, -1}})) << endl;;
}


//
// Created by ASUS on 2025/2/17.
//
