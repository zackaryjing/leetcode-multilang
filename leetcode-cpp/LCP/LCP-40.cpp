#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxmiumScore(vector<int> cards, int cnt) {
//    int maxmiumScore(vector<int> &cards, int cnt) {
        if (cards.size() < cnt) {
            return 0;
        }
        std::sort(cards.begin(), cards.end(), [](int item1, int item2) { return item1 > item2; });
        for (auto card: cards) {
//            cout << card << ", ";
        }
//        cout << endl;
        int ans = 0;
        int minOdd = INT_MAX, minEven = INT_MAX;
        int i;
        for (i = 0; i < cnt; ++i) {
            ans += cards[i];
            if (cards[i] % 2 == 1) {
                minOdd = cards[i];
            } else {
                minEven = cards[i];
            }
        }
        if (ans % 2 == 0) {
            return ans;
        } else {
            int temp1 = ans;
            temp1 -= minOdd;
            for (int j = i; j < cards.size(); ++j) {
                if (cards[j] % 2 == 0) {
                    temp1 += cards[j];
                    break;
                }
            }
            if (temp1 == ans - minOdd) {
                temp1 = 0;
            }
            int temp2 = ans;
            if (minEven != INT_MAX) {
                temp2 -= minEven;
                for (int j = i; j < cards.size(); ++j) {
                    if (cards[j] % 2 == 1) {
                        temp2 += cards[j];
                        break;
                    }
                }
                if (temp2 == ans - minEven) {
                    temp2 = 0;
                }
            } else {
                temp2 = 0;
            }
            return max(temp1, temp2);
        }
    }
};

int main() {
    Solution test;
    cout << test.maxmiumScore({3, 3, 1}, 1) << endl;
    cout << test.maxmiumScore({1,2,8,9}, 3) << endl;
}
//
// Created by ASUS on 2024/8/3.
//
