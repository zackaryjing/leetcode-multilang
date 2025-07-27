// problem: https://leetcode.cn/problems/decode-xored-array/

struct Solution;

impl Solution {
    pub fn decode(encoded: Vec<i32>, mut first: i32) -> Vec<i32> {
        let mut res = vec![first];
        for num in encoded {
            first = first ^ num;
            res.push(first);
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::decode(vec![1, 2, 3], 1));
    println!("{:?}", Solution::decode(vec![6, 2, 7, 3], 4));
}

//
// Created By Zackary At 2025/7/21 10:11
//
