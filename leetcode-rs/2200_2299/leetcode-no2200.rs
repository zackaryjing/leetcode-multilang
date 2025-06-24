// problem: https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/?envType=daily-question&envId=2025-06-24
struct Solution;

use std::collections::VecDeque;
impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();
        let k = k as usize;
        let n = nums.len();
        let mut buffer = VecDeque::new();
        let mut allowed_cnt = 0;
        for i in 0..n {
            if nums[i] == key {
                buffer.push_back(i as i32);
                while !buffer.is_empty() {
                    res.push(buffer.pop_front().unwrap());
                }
                allowed_cnt = k;
            } else {
                if allowed_cnt > 0 {
                    res.push(i as i32);
                    allowed_cnt -= 1;
                } else {
                    buffer.push_back(i as i32);
                    if buffer.len() > k {
                        buffer.pop_front();
                    }
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::find_k_distant_indices(vec![3, 4, 9, 1, 3, 9, 5], 9, 1)
    );
    println!(
        "{:?}",
        Solution::find_k_distant_indices(vec![2, 2, 2, 2, 2], 2, 2)
    );
    println!(
        "{:?}",
        Solution::find_k_distant_indices(vec![1,2,3,4,5,6,7,8,9,10], 2, 5)
    );
}

//
// Created by zhiya at 6/24/2025 3:43 PM
//
