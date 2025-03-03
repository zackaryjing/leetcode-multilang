#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // 使用 insert 插入键值对，设置默认值
    myMap.insert({1, "Default"});

    // 输出默认值
    std::cout << "Value for key 1: " << myMap[1] << std::endl;

    // 试图访问不存在的键，将插入默认值
    std::cout << "Value for key 2: " << myMap[2] << std::endl;

    return 0;
}
