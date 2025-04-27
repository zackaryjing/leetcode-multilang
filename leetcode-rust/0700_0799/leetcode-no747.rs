// problem: https://leetcode.cn/problems/largest-number-at-least-twice-of-others/
struct Solution;

impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        let mut m1 = i32::MIN;
        let mut m2 = i32::MIN;
        let mut mi = 0usize;
        for (i, &num) in nums.iter().enumerate() {
            if num >= m1 {
                m2 = m1;
                m1 = num;
                mi = i;
            } else if num > m2 {
                m2 = num;
            }
        }
        if m1 >= m2 * 2 { mi as i32 } else { -1 }
    }
}

fn main() {
    println!("{}", Solution::dominant_index(vec![3, 6, 1, 0]));
    println!("{}", Solution::dominant_index(vec![1, 2, 3, 4]));
}

//
// Created by ASUS at 2025/4/23 23:12
//
