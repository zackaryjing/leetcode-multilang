// problem: https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/?envType=daily-question&envId=2025-06-24
struct Solution;

impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let n = s.len();
        let s = s.as_bytes();
        let k = k as usize;
        let m = (n / k) + 1;
        let mut res = Vec::with_capacity(m);
        let mut temp = Vec::with_capacity(k);
        for i in 0..n {
            if i % k == 0 {
                res.push(String::from_utf8(temp).unwrap());
                temp = Vec::with_capacity(k);
            } else {
                temp.push(s[i]);
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::);
}

//
// Created by zhiya at 6/24/2025 4:12 PM
//