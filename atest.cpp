#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <type_traits>

using namespace std;

//template<typename Container>
//string to_string(const Container &container) {
//    string temp;
//    if (typename enable_if<is_same<Container, set<typename Container::value_type>>::value>::type) {
//        for (auto [i, j]: container) {
//            temp += to_string(i) + ":" + to_string(j) + ",";
//        }
//    }
//    else if (typename enable_if<is_same<Container, map<typename Container::key_type, typename Container::mapped_type>>::value>::type) {
//        for (auto i: container) {
//            temp += to_string(i) + ",";
//        }
//    }
//}


template<typename Container>
void printContainer(const Container& container) {
    // 使用enable_if来检查容器类型是否为std::map
    typename std::enable_if<std::is_same<Container, std::map<typename Container::key_type, typename Container::mapped_type>>::value>::type* is_map = nullptr;
    // 使用enable_if来检查容器类型是否为std::set
    typename std::enable_if<std::is_same<Container, std::set<typename Container::value_type>>::value>::type* is_set = nullptr;
    // 如果是std::map，则遍历并打印键值对
    if (is_map) {
        for (const auto& pair : container) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }
        // 如果是std::set，则遍历并打印值
    else if (is_set) {
        for (const auto& value : container) {
            std::cout << "Value: " << value << std::endl;
        }
    }
}

int main() {
    set<int> a;
    a.insert(4);
    a.insert(1);
     printContainer(a);
//    cout << to_string(a) << endl;
    a.insert(5);
    a.insert(4);
    a.insert(0);
//    cout << to_string(a) << endl;
}
//
// Created by ASUS on 2023/7/7.
//

//
// Created by ASUS on 2023/9/1.
//
