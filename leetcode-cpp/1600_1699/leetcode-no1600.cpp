// problem: https://leetcode.cn/problems/throne-inheritance/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <deque>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class ThroneInheritance {
public:
    unordered_map<string, string> parent;
    unordered_map<string, bool> isDead;
    unordered_map<string, vector<string>> child;
    string head;
    int cnt = 1;
    ThroneInheritance(string kingName) { head = kingName; }

    void birth(string parentName, string childName) {
        parent[childName] = parentName;
        child[parentName].push_back(childName);
        cnt++;
    }


    void death(string name) {
        isDead[name] = true;
        cnt--;
    }

    vector<string> curOrder;

    void dfs(string cur) {
        for (const auto c: child[cur]) {
            if (not isDead[c]) {
                curOrder.push_back(c);
            }
            dfs(c);
        }
    }

    vector<string> getInheritanceOrder() {
        curOrder.clear();
        curOrder.reserve(cnt);
        if (not isDead[head]) {
            curOrder.push_back(head);
        }
        dfs(head);
        return curOrder;
    }
};


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(int argc, char *argv[]) {
    ThroneInheritance s("king");

    s.birth("king", "andy");
    s.birth("king", "bob");
    s.birth("king", "catherine");
    s.birth("andy", "matthew");
    s.birth("bob", "alex");
    s.birth("bob", "asha");

    // 第一次查询继承顺序
    vector<string> order1 = s.getInheritanceOrder();
    for (auto &name: order1)
        cout << name << " ";
    cout << endl;

    s.death("bob");

    // 第二次查询继承顺序
    vector<string> order2 = s.getInheritanceOrder();
    for (auto &name: order2)
        cout << name << " ";
    cout << endl;
}

//
// Created By jing At 2026-01-01 22:41
//
