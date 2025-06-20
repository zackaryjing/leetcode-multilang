// problem: https://leetcode.cn/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2025-06-18
struct Solution;

impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        nums.sort();
        let n = nums.len();
        let mut res = Vec::new();
        for i in (0..n - 2).step_by(3) {
            if (nums[i] - nums[i + 2]).abs() > k {
                return Vec::new();
            }
            res.push(vec![nums[i], nums[i + 1], nums[i + 2]]);
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::divide_array(vec![1, 3, 4, 8, 7, 9, 3, 5, 1], 2)
    );
    println!("{:?}", Solution::divide_array(vec![2, 4, 2, 2, 5, 2], 2));
    println!(
        "{:?}",
        Solution::divide_array(
            vec![4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11],
            14
        )
    );
}

//
// Created by zhiya at 6/18/2025 10:56 AM
//
