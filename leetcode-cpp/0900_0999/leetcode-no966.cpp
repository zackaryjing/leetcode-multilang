// problem: https://leetcode.cn/problems/vowel-spellchecker/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


class Solution {
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
        auto hash_r = [](auto &&r) { return ranges::fold_left(r, 0zu, [](auto a, auto &&c) { return a << 7 | c; }); };
        auto hs1 = [&](auto &&s) { return hash_r(s | views::transform(::tolower)); };
        auto hs2 = [&](auto &&s) {
            return hash_r(s | views::transform(::tolower)
                          | views::transform([](auto c) { return "aeiou"sv.find(c) != -1 ? '*' : c; }));
        };
        auto cmp = [](auto &&a, auto &&b) { return true; };
        unordered_set<string_view> dict1{wordlist.begin(), wordlist.end()};
        unordered_set dict2{wordlist.begin(), wordlist.end(), wordlist.size(), hs1, cmp};
        unordered_set dict3{wordlist.begin(), wordlist.end(), wordlist.size(), hs2, cmp};

        ranges::transform(queries, queries.begin(), [&](auto &&s) {
            return dict1.contains(s)
                       ? s
                       : dict2.contains(s)
                             ? *dict2.find(s)
                             : dict3.contains(s)
                                   ? *dict3.find(s)
                                   : ""s;
        });
        return queries;
    }
};

class Solution2 {
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
        auto hash_r = [](auto &&r) { return ranges::fold_left(r, 0zu, [](auto a, auto &&c) { return a << 7 | c; }); };
        unordered_map<string, vector<string>, decltype(hash_r)> dict({}, hash_r);
        unordered_map<string, string, decltype(hash_r)> vowelDict({}, hash_r);
        const auto toLower = [](string &s) {
            for (char &i: s) {
                if ('A' <= i and i <= 'Z') {
                    i += 'a' - 'A';
                }
            }
        };
        const auto rmVowel = [](string &s) {
            for (char &i: s) {
                switch (i) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        i = '*';
                    default: ;
                }
            }
        };
        for (const auto &word: wordlist) {
            auto s = word;
            toLower(s);
            dict[s].push_back(word);
            rmVowel(s);
            if (not vowelDict.contains(s)) {
                vowelDict[s] = word;
            }
        }
        vector<string> res;
        res.reserve(queries.size());
        for (const auto &query: queries) {
            auto s = query;
            toLower(s);
            if (dict.contains(s)) {
                bool candidate = false;
                for (const auto &c: dict[s]) {
                    if (c == query) {
                        res.push_back(query);
                        candidate = true;
                        break;
                    }
                }
                if (not candidate)
                    res.push_back(dict[s][0]);
            } else if (rmVowel(s); vowelDict.contains(s)) {
                res.push_back(vowelDict[s]);
            } else {
                res.emplace_back();
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.spellchecker(temp_vector({"KiTe", "kite", "hare", "Hare"}),
                                  temp_vector({
                                      "kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"
                                  })
    ));
}

//
// Created By ASUS At 2026-02-08 20:51
//
