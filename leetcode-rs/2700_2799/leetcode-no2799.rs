// problem: https://leetcode.cn/problems/count-complete-subarrays-in-an-array/?envType=daily-question&envId=Invalid%20Date
struct Solution;

use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let cnt = nums.iter().cloned().collect::<HashSet<_>>().len();
        let mut right = 0;
        let mut occur: HashMap<i32, i32> = HashMap::new();

        let mut res = 0i32;
        for i in 0..n {
            let mut valid = true;
            while occur.len() < cnt {
                if right < n {
                    *occur.entry(nums[right]).or_insert(0) += 1;
                    right += 1;
                } else {
                    valid = false;
                    break;
                }
            }
            if !valid {
                break;
            }

            res += (n - right + 1) as i32;

            if let Some(count) = occur.get_mut(&nums[i]) {
                *count -= 1;
                if *count == 0 {
                    occur.remove(&nums[i]);
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_complete_subarrays(vec![1, 3, 1, 2, 2])
    );
    println!("{:?}", Solution::count_complete_subarrays(vec![5, 5, 5, 5]));
}

//
// Created by zhiya at 2025/4/24 12:41
//
