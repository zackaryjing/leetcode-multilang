// problem: https://leetcode.cn/problems/design-skiplist/
#include <functional>
#include <iostream>
#include <random>
#include <vector>

using namespace std;


constexpr int MAX_LEVEL = 32;
constexpr double P_FACTOR = 0.25;

struct SkiplistNode {
    int val;
    vector<SkiplistNode *> forward;

    SkiplistNode(int _val, int _maxLevel = MAX_LEVEL): val(_val), forward(_maxLevel, nullptr) {
    }
};

class Skiplist {
private:
    SkiplistNode *head;
    int level;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;

public:
    SkipList(): head(new SkiplistNode(-1), level(0), dis(0, 1)) {
    }

    bool search(int target) {
        SkiplistNode *curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        if (curr && curr->val == target) {
            return true;
        }
        return false;
    }

    void add(int num) {
        vector<SkiplistNode *> update(MAX_LEVEL, head);
        SkiplistNode *curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        int lv = randomLevel();
        level = max(level, lv);
        SkiplistNode *newNode = new SkiplistNode(num, lv);
        for (int i = 0; i < lv; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool erase(int num) {
        vector<SkiplistNode *> update(MAX_LEVEL, nullptr);
        SkiplistNode *curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        curr = curr->forward[0];
        if (!curr || curr->val != num) {
            return false;
        }
        for (int i = 0; i < level; i++) {
            if (update[i]->forward[i] != curr) {
                break;
            }
            update[i]->forward[i] = curr->forward[i];
        }
        delete curr;
        while (level > 1 && head->forward[level - 1] == nullptr) {
            level--;
        }
        return true;
    }

    int randomLevel() {
        int lv = 1;
        while (dis(gen) < P_FACTOR and lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }
};


template<typename T>
class SkipNode {
public:
    T val;
    SkipNode *right = nullptr;
    SkipNode *down = nullptr;
    SkipNode *up = nullptr;

    SkipNode(T val, SkipNode *right, SkipNode *down): val(val), right(right), down(down) {
    };

    SkipNode(T val, SkipNode *right): val(val), right(right) {
    };

    explicit SkipNode(T val): val(val) {
    };

    SkipNode() = default;
};

class Skiplist {
public:
    SkipNode<int> *start = nullptr;
    bool _empty = true;

    Skiplist() = default;

    bool search(int target) {
        if (_empty) {
            return false;
        }
        if (target < start->val) {
            return false;
        }
        auto cur = start;
        function<bool()> find_place = [&]()-> bool {
            if (cur->val == target) {
                return true;
            }
            if (cur->right) {
                if (cur->right->val <= target) {
                    cur = cur->right;
                    return find_place();
                }
            }
            if (cur->down) {
                cur = cur->down;
                return find_place();
            }
            return false;
        };
        return find_place();
    }

    void add(int num) {
        if (_empty) {
            start = new SkipNode(num);
            _empty = false;
            return;
        }
        if (num < start->val) {
            auto temp = start;
            while (temp->down) {
                temp = temp->down;
            }
            start = new SkipNode(num, temp);
            return;
        }
        auto cur = start;
        SkipNode<int> *upper = nullptr;
        function<void()> find_place = [&]()-> void {
            if (cur->val == num) {
                if (cur->up) {
                    while (cur->up) {
                        cur = cur->up;
                    }
                }
                // cout << cur->val <<" [asdf]" <<endl;
                auto temp = cur;
                SkipNode<int> *right = nullptr;
                while (temp) {
                    if (temp->up) {
                        right = temp->up;
                        break;
                    }
                    temp = temp->right;
                }
                cur->up = new SkipNode(num, right, cur);
                if (upper) {
                    upper->right = cur->up;
                }
                return;
            }
            if (cur->right) {
                if (cur->right->val <= num) {
                    cur = cur->right;
                    return find_place();
                }
            }
            if (cur->down) {
                upper = cur;
                cur = cur->down;
                return find_place();
            }
            cur->right = new SkipNode(num, cur->right, cur->down);
        };
        find_place();
    }


    bool erase(int num) {
        if (_empty) {
            return false;
        }
        if (num < start->val) {
            return false;
        }
        SkipNode<int> *left = nullptr;
        auto cur = start;
        function<bool()> find_place = [&]()-> bool {
            // cout << cur->val << " val " << endl;
            if (cur->val == num) {
                if (cur->up) {
                    while (cur->up) {
                        cur = cur->up;
                    }
                } else {
                    if (left) {
                        left->right = nullptr;
                    }
                }
                if (cur->down) {
                    cout << cur->down << endl;
                    cur->down->up = nullptr;
                    if (cur == start) {
                        start = cur->down;
                    }
                } else {
                    // cout << "5.1" << endl;
                    if (cur == start) {
                        start = nullptr;
                        _empty = true;
                    }
                }
                delete cur;
                return true;
            }
            if (cur->right) {
                // cout << "yes" << endl;
                if (cur->right->val <= num) {
                    left = cur;
                    cur = cur->right;
                    return find_place();
                }
            }
            if (cur->down) {
                cur = cur->down;
                return find_place();
            }
            return false;
        };
        return find_place();
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main() {
    Skiplist test;

    test.add(16);
    test.add(5);
    test.add(14);
    test.add(13);
    test.add(0);
    test.add(3);
    test.add(12);
    test.add(9);
    test.add(12);

    cout << "e: " << test.erase(3) << endl;
    cout << test.search(6) << endl;

    test.add(7);

    cout << "e: " << test.erase(0) << endl;
    cout << "e: " << test.erase(1) << endl;
    cout << "e: " << test.erase(10) << endl;

    test.add(5);

    cout << test.search(12) << "true" << endl;
    cout << test.search(7) << "true" << endl;
    cout << test.search(16) << "true" << endl;

    cout << "e: " << test.erase(7) << endl;
    cout << test.search(0) << endl;

    test.add(9);

    return 0;
}


//
// Created by ASUS on 2025/3/27.
//
