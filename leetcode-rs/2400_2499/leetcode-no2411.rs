// problem: https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut res = vec![0; n];
        let mut m_or = vec![0; n];
        m_or[n - 1] = nums[n - 1];
        for i in (0..n - 1).rev() {
            m_or[i] = m_or[i + 1] | nums[i];
        }
        let mut cur = 0;
        let mut right = 0;
        struct State {
            cur_v: Vec<i32>,
        }
        impl State {
            pub fn new() -> Self {
                Self { cur_v: vec![0; 32] }
            }
            pub fn add(&mut self, num: i32) {
                for i in 0..32 {
                    self.cur_v[i] += (num >> i) & 1;
                }
            }
            pub fn sub(&mut self, num: i32) -> i32 {
                let mut res = 0;
                for i in 0..32 {
                    self.cur_v[i] -= (num >> i) & 1;
                    if self.cur_v[i] > 0 {
                        res |= 1 << i;
                    }
                }
                res
            }
        }
        let mut s = State::new();
        for i in 0..n {
            while cur != m_or[i] {
                let num = nums[right];
                cur |= num;
                s.add(num);
                right += 1;
            }
            cur = s.sub(nums[i]);
            res[i] = max((right - i) as i32, 1);
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::smallest_subarrays(vec![1, 2, 3, 4]));
}

//
// Created by ASUS at 8/2/2025 6:49 PM
//
