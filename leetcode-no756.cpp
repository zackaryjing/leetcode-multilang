#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Solution2 {
private:
    map<string, vector<string>> ways;
    vector<vector<string>> pyramid;
    set<string> seen;
    int N;
public:
    void show() {
        for (const auto &item: pyramid) {
            for (const auto &c: item) {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << string(10, '-') << endl;
    }

    void create(vector<string> &allowed) {
        for (auto const &str: allowed) {
            ways[str.substr(0, 2)].push_back(str.substr(2, 1));
        }
    }

    int build(int lvl, int pos) {
        vector<string> &directions = ways[pyramid[lvl][pos] + pyramid[lvl][pos + 1]];
        if (lvl == N - 1 and not directions.empty()) {
            return 1;
        } else if (directions.empty()) {
            return 0;
        }
        for (const string &direction: directions) {
            if (pos >= 1) {
                if (ways[pyramid[lvl + 1][pos - 1] + direction].empty()) {
                    continue;
                }
            }
            pyramid[lvl + 1][pos] = direction;
            if (pos < N - lvl - 2) {
                int res = build(lvl, pos + 1);
                if (res) {
                    return 1;
                }
            } else {
                int res = build(lvl + 1, 0);
                if (res == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed) {
        N = bottom.length();
        create(allowed);
        pyramid.resize(N, vector<string>(N));
        for (int k = 0; k < N; ++k) {
            pyramid[0][k] = bottom[k];
        }
        build(0, 0);
        if (pyramid[N - 1][0].empty()) {
            return false;
        }
        cout << pyramid[N - 1][0] << endl;
        return true;
    }
};

class Solution {
private:
    map<string, vector<string>> ways;
    map<pair<string,string>,bool> seen;
public:
    void create(vector<string> &allowed) {
        for (auto const &str: allowed) {
            ways[str.substr(0, 2)].push_back(str.substr(2, 1));
        }
    }

    bool search(const string &a, string b) {
        if (seen.find({a,b}) != seen.end()){
            return seen[{a,b}];
        }
        if (b.size() == 2) {
            if (not search(b,"")){
                seen[{a,b}] = false;
                return false;
            }
        }
        if (a.size() == 2) {
            if (b.empty()) {
                return not ways[a].empty();
            } else {
                if (any_of(ways[a].begin(), ways[a].end(), [&](const string &t) {
                    return search(b + t, "");
                })) {
                    seen[{a,b}] = true;
                    return true;
                } else {
                    seen[{a,b}] = false;
                    return false;
                }
            }
        } else {
            if (any_of(ways[a.substr(0, 2)].begin(), ways[a.substr(0, 2)].end(), [&](const string &t) {
                return search(a.substr(1),b + t);
            })) {
                seen[{a,b}] = true;
                return true;
            } else {
                seen[{a,b}] = false;
                return false;
            }
        }
    }

    bool pyramidTransition(string bottom, vector<string> &allowed) {
        create(allowed);
        return search(bottom, "");
    }
};

int main() {
    Solution test;
    string b1 = "BCD";
    vector<string> al1 = {"BCC", "CDE", "CEA", "FFF"};
    cout << test.pyramidTransition(b1, al1) << endl;
    Solution test2;
    string b2 = "AAAA";
    vector<string> al2 = {"AAB", "AAC", "BCD", "BBE", "DEF"};
    cout << test2.pyramidTransition(b2, al2) << endl;
    Solution test3;
    string b3 = "BBDCDA";
    vector<string> al3 = {"CAB", "ACB", "ACA", "AAA", "AAC", "AAB", "CDB", "BCA", "CBB", "BCC", "BAB", "BAC", "BAA",
                          "CCD", "CAA", "CCA", "CCC", "CCB", "DAD", "DAA", "DAC", "ACD", "DCB", "DCC", "DCA", "CAD",
                          "ACC", "ABA", "ABB", "ABD", "BBD", "BBB", "BBA", "ADD", "ADB", "ADC", "DDC", "DDB", "DDA",
                          "DDD", "CDD", "CBC", "CBA", "CDA", "CBD", "CDC", "DBC", "DBD", "BDA"};
    cout << test3.pyramidTransition(b3, al3) << endl;
    Solution test4;
    string b4 = "BBDCDA";
    vector<string> al4 = {"ACC", "ACA", "AAB", "BCA", "BCB", "BAC", "BAA", "CAC", "BDA", "CAA", "CCA", "CCC", "CCB",
                          "DAD", "CCD", "DAB", "ACD", "DCA", "CAD", "CBB", "ABB", "ABC", "ABD", "BDB", "BBC", "BBA",
                          "DDA", "CDD", "CBC", "CBA", "CDA", "DBA", "ABA"};
    cout << test4.pyramidTransition(b4, al4) << endl;
}
//
// Created by ASUS on 2024/3/30.
//
