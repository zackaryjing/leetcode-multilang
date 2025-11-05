// problem: https://open.spotify.com/
struct Solution;

use std::arch::x86_64::_mm_undefined_si128;
use std::cmp::max;
use std::collections::VecDeque;
impl Solution {
    pub fn max_width_ramp(nums: Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = vec![i32::MAX];
        let mut pos_stack: Vec<usize> = vec![usize::MAX];
        let n = nums.len();
        let mut res = 0;
        for i in 0..n {
            if nums[i] < *stack.last().unwrap() {
                stack.push(nums[i]);
                pos_stack.push(i);
            }
        }
        let mut cur = *stack.last().unwrap();
        let mut find_pos = stack.len() - 1;
        let mut is_end = false;
        for j in (0..n).rev() {
            if nums[j] >= cur {
                let mut p = find_pos - 1;
                while nums[j] >= stack[p] {
                    find_pos = p;
                    if p == 0 {
                        is_end = true;
                        break;
                    }
                    p -= 1;
                }
                res = max(res, j - pos_stack[find_pos]);
                cur = nums[j];
                if is_end {
                    break;
                }
            }
        }
        res as i32
    }
}

impl Solution {
    pub fn max_width_ramp_2(nums: Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        let mut pos_stack: Vec<usize> = Vec::new();
        let n = nums.len();
        let mut res = 0;
        for i in 0..n {
            if !stack.is_empty() {
                if nums[i] < *stack.last().unwrap() {
                    stack.push(nums[i]);
                    pos_stack.push(i);
                } else {
                    let mut p = stack.len() - 1;
                    for j in (0..stack.len()).rev() {
                        if stack[j] <= nums[i] {
                            p = pos_stack[j];
                        }
                    }
                    res = max(res, i - p);
                }
            } else {
                stack.push(nums[i]);
                pos_stack.push(i);
            }
        }
        res as i32
    }
}


fn main() {
    println!("{:?}", Solution::max_width_ramp(vec![6, 0, 8, 1, 2, 5]));
    println!(
        "{:?}",
        Solution::max_width_ramp(vec![9, 8, 1, 0, 1, 9, 4, 0, 4, 1])
    );
}

//
// Created by jing at 2025-09-13 21:42
//
