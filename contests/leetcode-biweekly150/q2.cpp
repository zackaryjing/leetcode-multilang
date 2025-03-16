#include <iomanip>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <unordered_set>

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int> > &squares) {
        double tot_area = 0;
        int max_y = 0;
        for (auto &sq: squares) {
            tot_area += 1LL * sq[2] * sq[2];
            max_y = max(max_y, sq[1] + sq[2]);
        }

        const int M = 100'000;
        auto check = [&](long long multi_y) -> bool {
            double y = 1.0 * multi_y / M;
            double area = 0.;
            for (auto &sq: squares) {
                if (sq[1] < y) {
                    double l = sq[2];
                    area += l * min(y - sq[1], l);
                }
            }
            return area >= tot_area / 2;
        };
        long long left = 0, right = 1LL * max_y * M;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return 1.0 * right / M;
    }
};


class Solution2 {
    // QAQ还是太菜了，能用但是超时，[无奈]
    // 所以我到底是优化了个锤子，完全没用啊？
    // 不要过早优化
public:
    using Square = pair<pair<int64_t, int64_t>, int64_t>; // 改成 int64_t 类型

    // 哈希函数定义
    struct SquareHash {
        size_t operator()(const Square &sq) const {
            size_t hash1 = hash<int64_t>()(sq.first.first); // x
            size_t hash2 = hash<int64_t>()(sq.first.second); // y
            size_t hash3 = hash<int64_t>()(sq.second); // l
            return hash1 ^ (hash2 << 1) ^ (hash3 << 2);
        }
    };

    int find_index_up(const vector<Square> &squares, double mid) {
        int left = 0, right = squares.size();
        while (left < right) {
            int mid_idx = left + (right - left) / 2;
            if (squares[mid_idx].first.second >= mid) {
                right = mid_idx;
            } else {
                left = mid_idx + 1;
            }
        }
        return left; // `left` 指向第一个 `y >= mid` 的元素
    }

    int find_index_low(const vector<Square> &squares, double mid) {
        int left = 0, right = squares.size();
        while (left < right) {
            int mid_idx = left + (right - left) / 2;
            if (squares[mid_idx].first.second + squares[mid_idx].second <= mid) {
                left = mid_idx + 1;
            } else {
                right = mid_idx;
            }
        }
        return left - 1; // `left - 1` 指向最后一个 `y + l <= mid` 的元素
    }

    double separateSquares(vector<vector<int> > &squares) {
        double total_size = 0;
        vector<Square> squares_lower_order;
        for (auto s: squares) {
            squares_lower_order.emplace_back(make_pair(s[0], s[1]), s[2]);
            total_size += static_cast<double>(s[2]) * static_cast<double>(s[2]);
        }
        sort(squares_lower_order.begin(), squares_lower_order.end(), [](const Square &a, const Square &b) {
            return a.first.second < b.first.second;
        });
        vector<Square> squares_upper_order = squares_lower_order;
        sort(squares_upper_order.begin(), squares_upper_order.end(), [](const Square &a, const Square &b) {
            return a.first.second + a.second < b.first.second + b.second;
        });

        // 使用 unordered_multiset 替代 set
        unordered_multiset<Square, SquareHash> all_squares(squares_lower_order.begin(), squares_lower_order.end());

        double lower = squares_lower_order[0].first.second;
        Square temp = squares_upper_order.back();
        double upper = temp.first.second + temp.second;
        bool lower_test = true;

        bool need_find_middle = true;

        unordered_multiset<Square, SquareHash> middle_parts;
        double lower_size = 0;
        double upper_size = 0;
        double mid = static_cast<double>(lower + upper) / 2;
        while (fabs(upper - lower) > 1e-5) {
            mid = static_cast<double>(lower + upper) / 2;
            // cout << endl;
            // cout << "mid: " << mid << endl;

            if (need_find_middle) {
                middle_parts.clear();
                lower_size = 0;
                upper_size = 0;

                int index_up = find_index_up(squares_lower_order, mid);
                int index_low = find_index_low(squares_upper_order, mid);
                // cout << "index_up: " << index_up << " index_low: " << index_low << endl;

                unordered_multiset<Square, SquareHash> lower_parts;
                unordered_multiset<Square, SquareHash> upper_parts;


                for (int i = index_up; i < squares_lower_order.size(); i++) {
                    upper_parts.insert(squares_lower_order[i]);
                    upper_size += pow(squares_lower_order[i].second, 2); // 使用 int64_t 计算面积
                }
                for (int i = 0; i <= index_low; i++) {
                    lower_parts.insert(squares_upper_order[i]);
                    lower_size += pow(squares_upper_order[i].second, 2); // 使用 int64_t 计算面积
                }

                // cout << "lower_size: " << lower_size << " upper_size: " << upper_size << endl;

                unordered_multiset<Square, SquareHash> temp_parts;

                // 计算 all_squares - lower_parts
                for (const auto &sq: all_squares) {
                    if (lower_parts.find(sq) == lower_parts.end()) {
                        temp_parts.insert(sq);
                    }
                }

                // 计算 temp_parts - upper_parts
                for (const auto &sq: temp_parts) {
                    if (upper_parts.find(sq) == upper_parts.end()) {
                        middle_parts.insert(sq);
                    }
                }

                if (lower_test) {
                    if (middle_parts.size() == 0) {
                        lower_test = false;
                        auto last_upper = squares_upper_order[index_low];
                        mid = last_upper.first.second + last_upper.second;
                    }
                }
            }

            bool has_middle = true;
            double min_side = 0;
            if (middle_parts.size() != 0) {
                min_side = middle_parts.begin()->second;
                has_middle = false;
            }
            for (const auto &sq: middle_parts) {
                int64_t x = sq.first.first; // 改成 int64_t 类型
                int64_t y = sq.first.second; // 改成 int64_t 类型
                int64_t l = sq.second; // 改成 int64_t 类型

                if (y < mid && y + l > mid) {
                    auto u_temp = (mid - y);
                    auto l_temp = (y + l - mid);
                    min_side = min(min_side, min(u_temp, l_temp));
                    double lower_fraction = u_temp / static_cast<double>(l);
                    double upper_fraction = l_temp / static_cast<double>(l);
                    lower_size += lower_fraction * (l * l);
                    upper_size += upper_fraction * (l * l);
                    // cout << "\t\t" << "upper_size: " << upper_size << endl;
                    // cout << "\t\t" << "lower_size: " << lower_size << endl;
                }
            }


            cout << fixed << setprecision(10);
            // cout << "lower_size: " << lower_size << " upper_size: " << upper_size << endl;

            if (need_find_middle and has_middle) {
                // cout << "min_side: " << min_side << "upper: " << upper_size << "lower: " << lower << endl;
                if (upper - lower < min_side) {
                    need_find_middle = false;
                }
            }
            if (lower_size < upper_size) {
                lower = mid;
            } else {
                upper = mid;
            }
        }
        return mid;
    }
};


int main(int argc, char *argv[]) {
    Solution2 test;
    cout << test.separateSquares(*make_unique<vector<vector<int> > >(vector<vector<int> >{{0, 0, 1}, {2, 2, 1}})) <<
            endl;
    cout << endl;
    cout << test.separateSquares(*make_unique<vector<vector<int> > >(vector<vector<int> >{{0, 0, 2}, {1, 1, 1}})) <<
            endl;
    cout << endl;
    cout << test.separateSquares(*make_unique<vector<vector<int> > >(vector<vector<int> >{{2, 5, 3}, {8, 12, 4}})) <<
            endl;
    cout << endl;
    cout << test.separateSquares(*make_unique<vector<vector<int> > >(vector<vector<int> >{
                {26, 29, 6}, {6, 29, 4}, {3, 14, 5}, {6, 29, 4}
            })) <<
            endl;

    cout << endl;
    cout << test.separateSquares(*make_unique<vector<vector<int> > >(vector<vector<int> >{

                {
                    {522261215, 954313664, 461744743}, {628661372, 718610752, 21844764},
                    {619734768, 941310679, 91724451}, {352367502, 656774918, 591943726},
                    {860247066, 905800565, 853111524}, {817098516, 868361139, 817623995},
                    {580894327, 654069233, 691552059}, {182377086, 256660052, 911357},
                    {151104008, 908768329, 890809906}, {983970552, 992192635, 462847045}
                }
            })) <<
            endl;
}


//
// Created by ASUS on 2025/2/15.
//
