// problem: https://leetcode.cn/problems/type-of-triangle/?envType=daily-question&envId=2025-05-19
struct Solution;

impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        let mut equal = 0;
        if !(nums[0] + nums[1] > nums[2]
            && nums[2] + nums[1] > nums[0]
            && nums[0] + nums[2] > nums[1])
        {
            return "none".to_string();
        }
        if nums[0] == nums[1] {
            equal += 1;
        }
        if nums[1] == nums[2] {
            equal += 1;
        }
        if nums[0] == nums[2] {
            equal += 1;
        }
        match equal {
            0 => "scalene".to_string(),
            1 => "isosceles".to_string(),
            3 => "equilateral".to_string(),
            _ => "".to_string(),
        }
    }
}

fn main() {
    println!("{:?}", Solution::triangle_type(vec![3, 3, 3]));
}

//
// Created by zhiya at 2025/5/19 17:42
//
