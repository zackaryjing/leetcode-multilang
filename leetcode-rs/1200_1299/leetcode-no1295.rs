// problem: https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30
struct Solution;

impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        for mut num in nums {
            let mut times = 0;
            while num > 0 {
                num /= 10;
                times += 1;
            }
            if times % 2 == 0 {
                res += 1;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::find_numbers(vec![12,345,2,6,7896]));
    println!("{:?}", Solution::find_numbers(vec![555,901,482,1771]));
}

//
// Created by zhiya at 2025/4/30 14:14
//