// problem: https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal/description/
struct Solution;

impl Solution {
    pub fn make_strings_equal(s: String, target: String) -> bool {
        let s_any_one = s.as_bytes().iter().any(|&c| c == b'1');
        let t_any_one = target.as_bytes().iter().any(|&c| c == b'1');
        !(s_any_one ^ t_any_one)
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::make_strings_equal("1010".to_string(), "0110".to_string())
    );
}

//
// Created by jing at 2025-09-13 20:59
//
