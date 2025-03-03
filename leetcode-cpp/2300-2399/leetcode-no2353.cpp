#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

auto cmp = [](const pair<int, string> &a, const pair<int, string> &b) {
    if (a.first != b.first) {
        return a.first > b.first; // 分数降序
    }
    return a.second < b.second; // 字典序升序
};
using SortedSet = set<pair<int, string>, decltype(cmp)>;

class FoodRatings {
public:
    unordered_map<string, SortedSet> ctof;
    unordered_map<string, pair<string, int> > ftocr;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            auto f = foods[i];
            auto c = cuisines[i];
            auto r = ratings[i];
            ctof[c].emplace(r, f);
            ftocr[f] = make_pair(c, r);
        }
    }

    void changeRating(string food, int newRating) {
        auto [c,r] = ftocr[food];
        ctof[c].erase(make_pair(r, food));
        ctof[c].insert(make_pair(newRating, food));
        ftocr[food] = make_pair(c, newRating);
    }

    void show() {
        for (auto const &[cu, val]: ctof) {
            cout << cu << ": ";
            for (const auto &[k,v]: val) {
                cout << k << " " << v << ", ";;
            }
            cout << endl;
        }
    }

    string highestRated(string cuisine) {
        return ctof[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main(int argc, char *argv[]) {
    vector<string> eg1 = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> eg2 = {
        "korean", "japanese", "japanese", "greek", "japanese", "korean"
    };
    vector<int> eg3 = {9, 12, 8, 15, 14, 7};
    FoodRatings test(eg1, eg2, eg3);
    cout << test.highestRated("korean") << endl;
    cout << test.highestRated("japanese") << endl;
    test.changeRating("sushi", 16);
    test.changeRating("sushi", 16);
    cout << test.highestRated("japanese") << endl;
    test.changeRating("ramen", 16);
    cout << test.highestRated("japanese") << endl;
    cout << endl;
    cout << endl;

    vector<string> eg21 = {"tjokfmxg", "xmiuwozpmj", "uqklk", "mnij", "iwntdyqxi", "cduc", "cm", "mzwfjk"};
    vector<string> eg22 =
            {"waxlau", "ldpiabqb", "ldpiabqb", "waxlau", "ldpiabqb", "waxlau", "waxlau", "waxlau"};
    vector<int> eg23 = {9, 13, 7, 16, 10, 17, 16, 17};
    FoodRatings test2(eg21, eg22, eg23);
    test2.show();
    test2.changeRating("tjokfmxg", 19);
    test2.show();
    cout << test2.highestRated("waxlau") << " <- " << endl;;
    test2.show();
    test2.changeRating("uqklk", 7);
    cout << test2.highestRated("waxlau") << " <- " << endl;;
    cout << test2.highestRated("waxlau") << " <- " << endl;;
    test2.changeRating("tjokfmxg", 14);
    test2.show();
    cout << test2.highestRated("waxlau") << " <- " << endl;;
    test2.changeRating("tjokfmxg", 4);
    cout << test2.highestRated("waxlau") << " <- " << endl;;
    test2.changeRating("mnij", 18);
    cout << test2.highestRated("waxlau") << " <- " << endl;;
}


//
// Created by ASUS on 2025/2/28.
//
