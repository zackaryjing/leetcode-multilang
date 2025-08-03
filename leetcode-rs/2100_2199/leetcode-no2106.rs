// problem: https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/?envType=daily-question&envId=2025-08-03
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn max_total_fruits(mut fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        let mid = fruits.partition_point(|f| f[0] < start_pos);
        if mid >= fruits.len() || fruits[mid][0] != start_pos {
            fruits.insert(mid, vec![start_pos, 0]);
        }
        let n = fruits.len();
        let limit = k / 3;
        let mut fix_sum = vec![0; n];
        for i in mid + 1..n {
            fix_sum[i] = fix_sum[i - 1] + fruits[i][1];
        }
        if mid > 0 {
            for i in (0..=mid - 1).rev() {
                fix_sum[i] = fix_sum[i + 1] + fruits[i][1];
            }
        }
        let mut res = 0;

        for j in mid..n {
            if fruits[j][0] - start_pos > limit {
                break;
            }
            let left_limit = start_pos - (k - 2 * (fruits[j][0] - start_pos));
            let left = fruits.partition_point(|f| f[0] < left_limit);
            res = max(res, fix_sum[left] + fix_sum[j]);
        }
        for j in (0..=mid).rev() {
            if start_pos - fruits[j][0] > limit {
                break;
            }
            let right_limit = start_pos + (k - 2 * (start_pos - fruits[j][0]));
            let right = fruits.partition_point(|f| f[0] <= right_limit) - 1;
            res = max(res, fix_sum[right] + fix_sum[j]);
        }
        res + fruits[mid][1]
    }
}

fn main() {
    println!(
        "{:?} e:9",
        Solution::max_total_fruits(vec![vec![2, 8], vec![6, 3], vec![8, 6]], 5, 4)
    );
    println!(
        "{:?} e:14",
        Solution::max_total_fruits(
            vec![
                vec![0, 9],
                vec![4, 1],
                vec![5, 7],
                vec![6, 2],
                vec![7, 4],
                vec![10, 9]
            ],
            5,
            4
        )
    );
    println!(
        "{:?} e:0",
        Solution::max_total_fruits(vec![vec![0, 3], vec![6, 4], vec![8, 5]], 3, 2)
    );
    println!(
        "{:?} e:10000",
        Solution::max_total_fruits(vec![vec![200000, 10000]], 200000, 20000)
    );
    println!(
        "{:?} e:10000",
        Solution::max_total_fruits(vec![vec![0, 10000]], 200000, 200000)
    );
}

//
// Created by zhiya at 8/3/2025 2:50 PM
//
