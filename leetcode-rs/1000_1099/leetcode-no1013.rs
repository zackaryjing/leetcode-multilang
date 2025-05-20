// problem: https://leetcode.cn/problems/partition-array-into-three-parts-with-equal-sum/
struct Solution;

impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let tot: i32 = arr.iter().sum();
        if tot % 3 != 0 {
            return false;
        }
        let avg = tot / 3;
        let n = arr.len();
        let mut curs = 0;
        let mut has_first = false;
        let mut has_second = false;
        for i in 0..n {
            curs += arr[i];
            if has_first && curs == 2 * avg && i != n - 1 {
                has_second = true;
            }
            if curs == avg {
                has_first = true;
            }
        }
        has_second
    }
}

fn main() {
    println!("{:?}", Solution::can_three_parts_equal_sum(vec![0, 0, 0]));
    println!(
        "{:?}",
        Solution::can_three_parts_equal_sum(vec![1, -1, 1, -1])
    );
    println!(
        "{:?}",
        Solution::can_three_parts_equal_sum(vec![0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1])
    );
    println!(
        "{:?}",
        Solution::can_three_parts_equal_sum(vec![0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1])
    );

    println!(
        "{:?}",
        Solution::can_three_parts_equal_sum(vec![3, 3, 6, 5, -2, 2, 5, 1, -9, 4])
    );
}

//
// Created by zhiya at 2025/4/20 18:26
//
