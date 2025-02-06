#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution2 {
public:
    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values,
                                vector<vector<string> > &queries) {
        unordered_map<string, vector<pair<string, double> > > graph;
        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            graph[equation[0]].emplace_back(make_pair(equation[1], values[i]));
            graph[equation[1]].emplace_back(make_pair(equation[0], 1 / values[i]));
        }
    }
};

class Solution {
public:
    unordered_map<string, pair<string, double> > _parent;

    pair<string, double> find(string index) {
        if (_parent[index].first != index) {
            auto index_par = find(_parent[index].first);
            _parent[index] = make_pair(index_par.first, index_par.second * _parent[index].second);
        }
        return _parent[index];
    }

    void connect(string index1, string index2, double ratio) {
        auto index2_par = find(index2);
        auto index1_par = find(index1);
        _parent[index1_par.first] = make_pair(index2_par.first, ratio * index2_par.second / index1_par.second);
    }

    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values,
                                vector<vector<string> > &queries) {
        for (auto equation: equations) {
            _parent[equation[0]] = make_pair(equation[0], 1);
            _parent[equation[1]] = make_pair(equation[1], 1);
        }
        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            connect(equation[0], equation[1], values[i]);
        }
        for (auto [key,val]: _parent) {
            find(key);
        }
        vector<double> ans;
        ans.reserve(queries.size());
        for (auto query: queries) {
            if (_parent.find(query[0]) != _parent.end() and _parent.find(query[1]) != _parent.end()) {
                if (_parent[query[0]].first == _parent[query[1]].first) {
                    ans.push_back(_parent[query[0]].second / _parent[query[1]].second);
                } else {
                    ans.push_back(-1);
                }
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<string> > equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string> > queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    auto ans = test.calcEquation(equations, values, queries);
    for (auto item: ans) {
        cout << item << ", ";
    }
    cout << endl;
}

//
// Created by ASUS on 2025/2/3.
//
