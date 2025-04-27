#include <iostream>
#include <vector>
#include "../utils/treegenerator.h"
#include "../utils/vector_helper.h"

using namespace std;


int main() {
    int left = 0;
    int right = 7;
    vector<int> nums = {2, 1, 7, 1, 7, 1, 5};
    int minK = 1;
    int maxK = 7;
    pair cnts = {0, 0};
    int res = 0;


    int start = left;
    int end = left;
    show_vector(nums);
    cout << end << "<" << right << endl;
    while (end < right) {
        cout << "start: " << start << ", end: " << end << endl;
        if (nums[end] == minK) {
            cnts.first++;
        } else if (nums[end] == maxK) {
            cnts.second++;
        }
        while (cnts.first and cnts.second) {
            cout << "\t start: " << start << ", end: " << end << endl;
            res += right - end;
            if (nums[start] == minK) {
                cnts.first--;
            } else if (nums[start] == maxK) {
                cnts.second--;
            }
            start++;
        }
        end++;
    }
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
