// problem: https://leetcode.cn/problems/jewels-and-stones/
struct Solution;

impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut je = vec![false; (b'z' - b'A' + 1) as usize];
        for i in jewels.as_bytes() {
            je[(i - b'A') as usize] = true;
        }
        let mut res = 0;
        for j in stones.as_bytes() {
            if je[(j - b'A') as usize] {
                res += 1;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::num_jewels_in_stones("ab".to_string(),"asdfabababa".to_string()));
    println!("{:?}", Solution::num_jewels_in_stones("z".to_string(),"ZZ".to_string()));
}

//
// Created by zhiya at 2025/5/24 17:52
//
