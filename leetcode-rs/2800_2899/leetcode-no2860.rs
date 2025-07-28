// problem: https://leetcode.cn/problems/happy-students/
struct Solution;

use std::collections::HashSet;
impl Solution {
    pub fn count_ways(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let shown: HashSet<&i32> = HashSet::from_iter(nums.iter());
        let n = nums.len();
        let mut res = 0;
        if nums[0] != 0 {
            res += 1;
        }
        for i in 1..n {
            if !shown.contains(&(i as i32)) {
                if nums[i - 1] < i as i32 && nums[i] > i as i32 {
                    res += 1;
                }
            }
        }
        if nums[n - 1] < n as i32 {
            res += 1;
        }
        res
    }
}

fn main() {
    println!("{:?} e:2", Solution::count_ways(vec![1, 1]));
    println!("{:?} e:1", Solution::count_ways(vec![1, 1, 0, 1]));
    println!(
        "{:?} e:3",
        Solution::count_ways(vec![6, 0, 3, 3, 6, 7, 2, 7])
    );
}

//
// Created by zhiya at 7/27/2025 7:48 PM
//
