#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
    int val;

    Test() = default;

    explicit Test(int val): val(val) {
    }
};


int main() {
    const vector<Test> bar = {Test(1)};
    const vector<Test> &foo = bar;
    const Test kkk = foo.back();
    kkk = Test();
}


// #include <iostream>
// #include <vector>
//
// class Test {
// public:
//     int val;
//
//     // 构造函数
//     explicit Test(int val) : val(val) {}
//
//     // 打印方法，方便查看 Test 的值
//     void print() const {
//         std::cout << "Test value: " << val << std::endl;
//     }
// };
//
// int main() {
//     // 创建一个包含 Test 对象的 vector
//     const std::vector<Test> vec = {Test(1), Test(2), Test(3)};
//
//     // 获取最后一个元素
//     const Test& t = vec.back();
//
//     // 打印值
//     t.print();
//
//     // 尝试修改 t 的值，应该会报错
//     t.val = 10;  // 错误: 不能修改 const 对象
//
//     return 0;
// }
