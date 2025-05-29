#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#include <vector>
#include <cstddef> // for ptrdiff_t

namespace std {
    template<>
    struct iterator_traits<std::vector<int>::iterator> {
        using difference_type = std::ptrdiff_t;               // 差值类型
        using value_type = uint64_t;                           // 你想替换成的类型
        using pointer = uint64_t*;                             // 指针类型
        using reference = uint64_t&;                           // 引用类型
        using iterator_category = std::random_access_iterator_tag; // 迭代器类别
    };
}



// namespace std{
//     template<>
//         struct iterator_traits<vector<int>::iterator> {
//         using value_type = uint64_t;
//     };
// }

int main() {
    vector<int> data = {536870915, 536870915, 536870915, 536870915, 536870915};
    vector<uint64_t> prefix(5);

    partial_sum(data.begin(), data.end(), prefix.begin());
    for (int i = 0; i < 5; i++) {
        cout << prefix[i] << endl;
    }
}
