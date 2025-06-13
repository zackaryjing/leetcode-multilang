class Solution1 {


    // int left = 不合法的最小值;
    // int right = 合法的最大值;
    //
    // while (left + 1 < right) {
    //     int mid = (left + right) / 2;
    //     if (check(mid))
    //         right = mid; // 缩小右边界，尝试更小的满足值
    //     else
    //         left = mid; // mid 不合法，向右试
    // }
    //
    // return right; // right 是第一个合法值
    //

    int search() {
        auto check = [](int num)-> bool {
            return false;
        };
        int n = 100;
        int left = -1;
        int right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
