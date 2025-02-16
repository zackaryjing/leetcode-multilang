#include <iostream>
#include <vector>

using namespace std;

class MapNode {
public:
    int _val = 0;
    MapNode *children[26] = {nullptr};

    MapNode() {
    }

    MapNode(const string &key, const int index, const int val) {
        if (index < key.size()) {
            children[key[index] - 'a'] = new MapNode(key, index + 1, val);
        } else {
            _val = val;
        }
    }

    void update(const string &key, const int index, const int val) {
        if (index < key.size()) {
            if (children[key[index] - 'a'] != nullptr) {
                children[key[index] - 'a']->update(key, index + 1, val);
            } else {
                children[key[index] - 'a'] = new MapNode(key, index + 1, val);
            }
        } else {
            _val = val;
        }
    }

    int getSum(string key) {
        vector<MapNode *> toVis;
        int index = 0;
        const MapNode *root = this;
        bool valid = true;
        while (index < key.length()) {
            root = root->children[key[index] - 'a'];
            if (root == nullptr) {
                valid = false;
                break;
            }
            index++;
        }
        if (valid) {
            return sum(root);
        } else {
            return 0;
        }
    }

    int sum(const MapNode *root) {
        int res = 0;
        res += root->_val;
        for (auto child: root->children) {
            if (child != nullptr) {
                res += sum(child);
            }
        }
        return res;
    }


    ~MapNode() {
        for (auto child: children) {
            delete child;
        }
    }
};

class MapSum {
    MapNode _root = MapNode();

public:
    MapSum() {
    }

    void insert(string key, int val) {
        _root.update(key, 0, val);
    }

    int sum(string prefix) {
        return _root.getSum(prefix);
    }
};


int main() {
    MapSum test;
    test.insert("apple", 3);
    auto res1 = test.sum("apple");
    cout << "ans: " << res1 << endl;
    test.insert("app", 2);
    auto res2 = test.sum("ap");
    cout << "ans: " << res2 << endl;
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */


//
// Created by ASUS on 2025/2/6.
//
