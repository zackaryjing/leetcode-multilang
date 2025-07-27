// problem: https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/
struct Solution;

impl Solution {
    // Just try to change order to make it concise
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut cur = 0i32;
        let mut res = 0i32;
        for &letter in s.as_bytes() {
            if letter != b'(' {
                cur -= 1;
            } else if cur < 0 {
                res += -cur;
                cur = 1;
            } else {
                cur += 1;
            }
        }
        res += cur.abs();
        res
    }
}

impl Solution {
    // [Pass]
    pub fn min_add_to_make_valid_2(s: String) -> i32 {
        let mut cur = 0i32;
        let mut res = 0i32;
        for &letter in s.as_bytes() {
            if letter == b'(' {
                if cur < 0 {
                    res += -cur;
                    cur = 1;
                } else {
                    cur += 1;
                }
            } else {
                cur -= 1;
            }
        }
        res += cur.abs();
        res
    }
}

fn main() {
    println!("{:?} 3", Solution::min_add_to_make_valid("(((".to_string()));
    println!(
        "{:?} 4",
        Solution::min_add_to_make_valid("()))((".to_string())
    );
}

//
// Created by zhiya at 7/15/2025 10:55 AM
//
