// problem: https://leetcode.cn/problems/set-mismatch/

struct Solution;

impl Solution {
    // [Pass] Performance ordinary
    pub fn find_error_nums_2(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort();
        let mut first = 0;
        let mut last = 0;
        let mut s = 0;
        for &num in &nums {
            if num == last {
                first = num;
            }
            last = num;
            s += num;
        }
        let n = nums.len() as i32;
        vec![first, n * (n + 1) / 2 + first - s]
    }
}

impl Solution {
    pub fn find_error_nums(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        let mut cur = 0;
        let offset = 100000;
        let mut s = 0;
        for i in 0..n as usize {
            let num = nums[i];
            let k = (num % offset) as usize;
            if nums[k - 1] < offset {
                nums[k - 1] += offset;
            } else {
                cur = num % offset;
            }
            s += num % offset;
        }
        vec![cur, n * (n + 1) / 2 + cur - s]
    }
}

fn main() {
    println!("{:?}", Solution::find_error_nums(vec![1, 2, 2, 4]));
    println!("{:?}", Solution::find_error_nums(vec![1, 1]));
}

//
// Created By Zackary At 2025/7/11 11:59
//
