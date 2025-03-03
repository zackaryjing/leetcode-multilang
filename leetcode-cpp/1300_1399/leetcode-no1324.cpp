#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string_view> data;
        size_t start = 0, end;
        constexpr char delimiter = ' ';
        while ((end = s.find(delimiter, start)) != string_view::npos) {
            if (end > start) {
                data.emplace_back(s.data() + start, end - start);
            }
            start = end + 1;
        }
        if (start < s.size()) {
            data.emplace_back(s.data() + start);
        }

        const int n = static_cast<int>(data.size());
        vector<string> ans;
        int max_len = 0;
        for (int i = n - 1; i >= 0; i--) {
            const int cur_len = max(max_len, static_cast<int>(data[i].size()));
            for (int j = 0; j < cur_len - max_len; j++) {
                ans.emplace_back(i + 1, ' ');
            }
            max_len = cur_len;
        }

        for (int i = 0; i < n; i++) {
            string_view &str = data[i];
            for (int j = 0; j < str.size(); j++) {
                ans[j][i] = str[j];
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.printVertically("HOW ARE YOU"));
    show_vector(test.printVertically("TO BE OR NOT TO BE"));
    show_vector(test.printVertically("CONTEST IS COMING"));
}


//
// Created by ASUS on 2025/2/25.
//
