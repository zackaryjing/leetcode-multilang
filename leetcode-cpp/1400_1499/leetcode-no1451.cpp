#include <sstream>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    string arrangeWords(string text) {
        vector<std::string_view> words;
        text[0] = std::tolower(text[0]); // 将首字母转为小写
        size_t start = 0;
        size_t end = -1;
        int n = text.size();

        // 使用 string_view 避免额外内存分配
        while ((end = text.find(' ', end + 1)) != std::string::npos) {
            words.emplace_back(text.data() + start, end - start); // 直接使用 string_view
            start = end + 1;
        }
        words.emplace_back(text.data() + start, n - start); // 最后一个单词

        // 使用 stable_sort 确保相对顺序
        ranges::stable_sort(words, [](const auto &a, const auto &b) { return a.size() < b.size(); });

        // 首字母大写（但 string_view 不支持修改原字符，必须转换回 string）
        string ans;
        std::ostringstream oss;
        for (const auto &word: words) {
            if (!oss.str().empty()) oss << " "; // 添加空格
            oss << word; // 拼接单词
        }
        ans = oss.str();
        ans[0] = std::toupper(ans[0]); // 重新修改首字母大写

        return ans;
    }
};

class Solution2 {
    //超时
public:
    string arrangeWords(string text) {
        vector<string> words;
        text[0] = std::tolower(text[0]);

        size_t start = 0;
        std::size_t end = -1; // 初始位置
        int n = text.size();
        while ((end = text.find(' ', end + 1)) != std::string::npos) {
            words.push_back(text.substr(start, end - start));
            start = end + 1;
        }
        words.push_back(text.substr(start, n - start));
        ranges::stable_sort(words, [](const auto &a, const auto &b) { return a.size() < b.size(); });
        words[0][0] = std::toupper(words[0][0]);
        string ans = accumulate(words.begin(), words.end(), std::string(),
                                [](const std::string &a, const std::string &b) {
                                    return a.empty() ? b : a + " " + b;
                                });
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.arrangeWords("Leetcode is cool") << endl;
    cout << test.arrangeWords(
        "Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry"
        "") << endl;
}


//
// Created by ASUS on 2025/2/22.
//
