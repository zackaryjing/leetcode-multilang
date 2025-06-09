// problem: https://leetcode.cn/problems/design-an-atm-machine/
#include <iostream>
#include <vector>

using namespace std;

class ATM {
public:
    int remain[5] = {};
    static constexpr int types[] = {20, 50, 100, 200, 500};

    ATM() {
    }

    void deposit(const vector<int> &banknotesCount) {
        for (int i = 0; i < 5; i++) {
            remain[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        int cur = 4;
        vector<int> res(5);
        while (cur >= 0) {
            if (not remain[cur] == 0) {
                const int curType = types[cur];
                const int cnt = min(amount / curType, remain[cur]);
                res[cur] = cnt;
                amount -= curType * cnt;
            }
            cur--;
        }
        if (amount != 0) {
            return {-1};
        }
        for (int i = 0; i < 5; ++i) {
            remain[i] -= res[i];
        }
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

int main(int argc, char *argv[]) {
    ATM test;

    // test.deposit(temp_vector({1, 1, 1, 1, 1}));
    // show_vector(test.withdraw(70));

    // test.deposit(temp_vector({0, 10, 0, 3, 0}));
    // show_vector(test.withdraw(500));

}

//
// Created By Zackary At 2025-06-08 13:18:43
//
