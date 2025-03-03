#include <iostream>
#include <set>
#include <vector>
#include <pstl/execution_defs.h>

#include "../../utils/vector_helper.h"

using namespace std;


vector<long long> f = {1};
int init = []() {
    for (int i = 1; f.back() < 1e15; i++) {
        f.push_back(f.back() * i);
        f.push_back(f.back() * i);
    }
    return 0;
}();

class Solution_others {
public:
    vector<int> permute(int n, long long k) {
        k--;
        if (n < f.size() && k >= f[n] * (2 - n % 2)) {
            return {};
        }

        vector<int> cand[2];
        for (int i = 2; i < n; i += 2) {
            cand[0].push_back(i);
        }
        for (int i = 1; i <= n; i += 2) {
            cand[1].push_back(i);
        }
        vector<int> ans(n);
        int parity = 1;
        for (int i = 0; i < n; i++) {
            int j = 0;
            if (n - 1 - i < f.size()) {
                long long size = f[n - 1 - i];
                j = k / size;
                k %= size;
                if (n % 2 == 0 && i == 0) {
                    parity = 1 - j % 2;
                    j /= 2;
                }
            }
            ans[i] = cand[parity][j];
            cand[parity].erase(cand[parity].begin() + j);
            parity ^= 1;
        }
        return ans;
    }
};

class Solution {
    // 高清重制版
    // f**k , n等于26的时候，long long 就已经爆掉了。然而n <= 100. 受不了了。
    // 问题解决。n <= 100 但是 k无论如何，不会超过long long。 所以只需要计算阶乘到大于k就可以了。
    // 因为不论是 / 还是 %= ,只要 f > k ，就都是相通的。
    // 至于这一堆看上去很像的计算阶乘的函数，完全没优化过，很蠢
public:
    bool calc(int n, long long k) {
        long long ans = 1;
        for (int i = 2; i <= (n + 1) / 2; i++) {
            ans *= i;
            if (ans >= k) {
                return true;
            }
        }
        for (int i = 2; i <= n / 2; i++) {
            ans *= i;
            if (ans >= k) {
                return true;
            }
        }
        if (n % 2 == 0) {
            if (2 * ans >= k) {
                return true;
            }
        }
        return ans >= k;
    }

    long long my_factorial_square(int n, long long k) {
        long long ans = 1;
        for (int i = 2; i <= n / 2; i++) {
            ans *= i;
            if (ans > k) {
                return ans;
            }
        }
        for (int i = 2; i <= n / 2; i++) {
            ans *= i;
            if (ans > k) {
                return ans;
            }
        }
        return ans;
    }


    long long my_factorial_t(int n, long long k) {
        long long ans = 1;
        for (int i = 2; i <= n / 2; i++) {
            ans *= i;
            if (ans > k) {
                return ans;
            }
        }
        for (int i = 2; i <= n / 2 - 1; i++) {
            ans *= i;
            if (ans > k) {
                return ans;
            }
        }
        return ans;
    }

    vector<int> permute(int n, long long k) {
        if (not calc(n, k)) {
            return {};
        }
        k = k - 1;
        vector<int> odd, even;
        for (int i = 1; i <= n; i += 2) {
            odd.push_back(i);
        }
        for (int i = 2; i <= n; i += 2) {
            even.push_back(i);
        }
        vector<int> nums1 = std::move(odd);
        vector<int> nums2 = std::move(even);

        vector<int> ans;
        if (n % 2 == 0) {
            long long f = my_factorial_t(n, k);

            long long index = k / f;
            k = k % f;
            if (index % 2 == 0) {
                // 下标偶数，拿到了奇数
                swap(nums1, nums2);
            }
            ans.push_back(nums2[index / 2]);
            nums2.erase(nums2.begin() + index / 2);
            n -= 1;
        }
        while (n > 0) {
            if (n % 2) {
                long long f = my_factorial_square(n, k);
                const long long index = k / f;
                k %= f;
                int cur = nums1[index]; // 通过下标访问
                ans.push_back(cur);
                nums1.erase(nums1.begin() + static_cast<int>(index)); // 删除当前元素
                n -= 1;
            } else {
                const long long f = my_factorial_t(n, k);
                const long long index = k / f;
                k %= f;
                int cur = nums2[index];
                ans.push_back(cur);
                nums2.erase(nums2.begin() + static_cast<int>(index)); // 删除当前元素
                n -= 1;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.permute(27, 670623106831091));
    show_vector(test.permute(26, 276650956732892));
    show_vector(test.permute(2, 3));
    show_vector(test.permute(3, 2));
    show_vector(test.permute(4, 6));
    show_vector(test.permute(7, 50));
}


class Solution2 {
    // 赛场version，
public:
    unsigned long long factorial(int n) {
        unsigned long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
        }
        return ans;
    }

    vector<int> permute(int n, long long k) {
        vector<int> odd, even;

        // 将奇数和偶数分别加入到 vector 中
        for (int i = 1; i <= n; i += 2) {
            odd.push_back(i);
        }
        for (int i = 2; i <= n; i += 2) {
            even.push_back(i);
        }


        cout << "odd : ";
        show_vector(odd);
        cout << "even : ";
        show_vector(even);


        vector<int> ans;
        bool is_odd = false;

        if (n % 2 == 0) {
            unsigned long long f = factorial(n / 2);
            f = f * f;
            int index = (k - 1) / f;
            k = k % f;
            cout << "i " << index << " f " << f << " k " << k << endl;
            if (index % 2) {
                index = index / 2;
                int cur = even[index]; // 通过下标访问
                ans.push_back(cur);
                even.erase(even.begin() + index); // 删除当前元素
                n -= 1;
            } else {
                index = index / 2;
                int cur = odd[index]; // 通过下标访问
                ans.push_back(cur);
                odd.erase(odd.begin() + index); // 删除当前元素
                n -= 1;
                is_odd = true;
            }
        }
        if (is_odd) {
            while (n > 0) {
                if (n % 2) {
                    // 处理奇数序列
                    unsigned long long f = factorial(n / 2);
                    f = f * f;
                    int index = (k - 1) / f;
                    k = k % f;
                    // cout << "i" << index << "f" << f << " k " << k << endl;
                    int cur = even[index]; // 通过下标访问
                    ans.push_back(cur);
                    even.erase(even.begin() + index); // 删除当前元素
                    n -= 1;
                } else {
                    // 处理偶数序列
                    unsigned long long f = factorial(n / 2);
                    unsigned long long g = factorial(n / 2 - 1);
                    f = f * g;
                    int index = (k - 1) / f;
                    // cout << "i" << index << "f" << f << endl;
                    k = k % f;
                    int cur = odd[index]; // 通过下标访问
                    ans.push_back(cur);
                    odd.erase(odd.begin() + index); // 删除当前元素
                    n -= 1;
                }
            }
        } else {
            while (n > 0) {
                cout << "odd : ";
                show_vector(odd);
                cout << "even : ";
                show_vector(even);
                if (n % 2) {
                    // 处理奇数序列
                    unsigned long long f = factorial(n / 2);
                    f = f * f;
                    int index = (k - 1) / f;
                    k = k % f;
                    cout << "i " << index << " f " << f << " k " << k << endl;
                    int cur = odd[index]; // 通过下标访问
                    ans.push_back(cur);
                    odd.erase(odd.begin() + index); // 删除当前元素
                    n -= 1;
                } else {
                    // 处理偶数序列
                    unsigned long long f = factorial(n / 2);
                    unsigned long long g = factorial(n / 2 - 1);
                    f = f * g;
                    int index = (k - 1) / f;
                    // cout << "i" << index << "f" << f << endl;
                    k = k % f;
                    int cur = even[index]; // 通过下标访问
                    ans.push_back(cur);
                    even.erase(even.begin() + index); // 删除当前元素
                    n -= 1;
                }
            }

            // show_vector(ans);
        }
        return ans;
    }
};


//
// Created by ASUS on 2025/3/1.
//
