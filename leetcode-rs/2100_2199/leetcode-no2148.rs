// problem: https://leetcode.cn/problems/count-elements-with-strictly-smaller-and-greater-elements/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

impl Solution {
    pub fn count_elements(nums: Vec<i32>) -> i32 {
        let mn = *nums.iter().min().unwrap();
        let mx = *nums.iter().max().unwrap();
        let mut res = 0;
        for num in nums {
            if num != mn && num != mx {
                res += 1;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::count_elements(vec![11, 7, 2, 15]));
    println!("{:?}", Solution::count_elements(vec![-3, 3, 3, 90]));
}

//
// Created by jing at 2026-04-27 21:12
//
