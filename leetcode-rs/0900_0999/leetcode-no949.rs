// problem: https://leetcode.cn/problems/largest-time-for-given-digits/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn largest_time_from_digits(mut arr: Vec<i32>) -> String {
        arr.sort();
        arr.reverse();
        for (index1, i) in arr.clone().iter().enumerate() {
            let mut p1 = arr.clone();
            p1.remove(index1);
            for (index2, j) in p1.clone().iter().enumerate() {
                let mut p2 = p1.clone();
                p2.remove(index2);
                if i * 10 + j < 24 {
                    let a = p2[0] * 10 + p2[1];
                    let b = p2[1] * 10 + p2[0];
                    if a < 60 && b < 60 {
                        return format!("{:02}:{:02}", i * 10 + j, max(a, b)).to_string();
                    } else if a < 60 {
                        return format!("{:02}:{a:02}", i * 10 + j).to_string();
                    } else if b < 60 {
                        return format!("{:02}:{b:02}", i * 10 + j).to_string();
                    }
                }
            }
        }
        "".to_string()
    }
}

fn main() {
    println!("{:?}", Solution::largest_time_from_digits(vec![1, 2, 3, 4]));
    println!("{:?}", Solution::largest_time_from_digits(vec![5, 5, 5, 5]));
    println!("{:?}", Solution::largest_time_from_digits(vec![0, 0, 0, 0]));
    println!("{:?}", Solution::largest_time_from_digits(vec![0, 0, 1, 0]));
    println!("{:?}", Solution::largest_time_from_digits(vec![2, 0, 6, 6]));
}

//
// Created by jing at 2026-04-29 18:11
//
