#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

// 自定义比较器
auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first != b.first) {
        return a.first > b.first;  // 分数降序
    }
    return a.second < b.second;    // 字典序升序
};

// 定义 set 的别名，带默认构造的比较器
using SortedSet = set<pair<int, string>, decltype(cmp)>;

int main() {
    // 使用 unordered_map 存储 string -> SortedSet，sortedSet 是有自定义比较器的 set
    unordered_map<string, SortedSet> ctof;

    // 直接插入数据
    ctof["category1"].insert({2, "banana"});
    ctof["category1"].insert({1, "apple"});
    ctof["category1"].insert({2, "apple"});
    ctof["category1"].insert({3, "cherry"});
    ctof["category1"].insert({3, "blueberry"});

    // 遍历输出
    for (const auto& [key, valueSet] : ctof) {
        cout << "Category: " << key << "\n";
        for (const auto& [num, str] : valueSet) {
            cout << num << " - " << str << "\n";
        }
    }

    return 0;
}