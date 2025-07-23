// problem: https://leetcode.cn/problems/number-of-sub-arrays-with-odd-sum/description/

struct Solution;

impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        let mut zero_cnt = 0;
        let mut cnt = [0i64, 0i64];
        let mut cur = 0;
        for num in arr {
            if num % 2 == 0 {
                zero_cnt += 1;
            } else {
                cnt[cur] += zero_cnt + 1;
                cur ^= 1;
                zero_cnt = 0;
            }
        }
        cnt[cur] += zero_cnt + 1;
        (cnt[0] * cnt[1] % 1000_000_007) as i32
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::num_of_subarrays(vec![
            0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1
        ])
    );
}

//
// Created By Zackary At 2025/7/22 11:35
//
