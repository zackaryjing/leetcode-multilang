// problem: https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17
struct Solution;

impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut res = 0;
        let n = nums.len();
        for i in 0..n {
            for j in i + 1..n {
                if nums[i] == nums[j] && (i * j) % k as usize == 0 {
                    res += 1;
                }
            }
        }
        res
    }
}

fn main() {
    println!("{}", Solution::count_pairs(vec![3, 1, 2, 2, 2, 1, 3], 2));
    println!("{}", Solution::count_pairs(vec![1, 2, 3, 4], 1));
}

//
// Created by ASUS at 2025/4/17 10:55
//
