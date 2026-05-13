// problem: https://leetcode.cn/problems/reorder-data-in-log-files/description/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        ranges::stable_sort(logs, [](const auto &a, const auto &b) -> bool {
            size_t sp1 = a.find(' ');
            size_t sp2 = b.find(' ');
            if (isalpha(a[sp1 + 1]) and isdigit(b[sp2 + 1])) {
                return true;
            }
            if (isalpha(a[sp1 + 1]) and isalpha(b[sp2 + 1])) {
                auto contenta = string_view(a.begin() + sp1 + 1, a.end());
                auto contentb = string_view(b.begin() + sp2 + 1, b.end());
                if (contenta == contentb) {
                    return string_view(a.data(), sp1) < string_view(b.data(), sp2);
                }
                return contenta < contentb;
            }
            return false;
        });
        return logs;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.reorderLogFiles(
    temp_vector({"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"})));
    show_vector(
    test.reorderLogFiles(temp_vector({"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"})));
}

//
// Created By jing At 2026-05-13 19:35
//
