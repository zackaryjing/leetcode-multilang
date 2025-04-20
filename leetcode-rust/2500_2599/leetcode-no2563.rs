// problem: https://leetcode.cn/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2025-04-19
struct Solution;

impl Solution {
    pub fn count_fair_pairs(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        let mut nums = nums;
        nums.sort();
        let mut res = 0i64;
        let n = nums.len();
        let mut cur: usize = 0;
        let mut left: usize = 0;
        let mut right: usize = 0;
        for i in 2..n {
            if nums[i - 1] + nums[i] <= upper {
                cur = i;
                right = i - 1;
            } else {
                break;
            }
        }
        for j in 0..=cur {
            if nums[j] + nums[cur] >= lower {
                left = j;
                break;
            }
        }
        for c in cur..n {
            while right < n && nums[right] {}
            res += (right - left + 1) as i64;
        }
        0
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_fair_pairs(vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 9, 14)
    );
}

//
// Created by zhiya at 2025/4/20 13:27
//
