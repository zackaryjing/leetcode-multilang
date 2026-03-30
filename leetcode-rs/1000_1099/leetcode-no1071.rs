// problem: https://leetcode.cn/problems/greatest-common-divisor-of-strings/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

use std::collections::HashSet;
use std::io::Read;
impl Solution {
    pub fn get_sub(mut str: &[u8]) -> HashSet<&[u8]> {
        let mut res = HashSet::new();
        let n = str.len();
        for i in 1..=n {
            if n % i != 0 {
                continue;
            }
            let mut valid = true;
            let mut s = i;
            while s < n {
                if str[0..i] != str[s..s + i] {
                    valid = false;
                    break;
                }
                if valid {
                    s += i;
                } else {
                    break;
                }
            }
            if valid {
                res.insert(&str[0..i]);
            }
        }
        res
    }
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        let a = str1.as_bytes();
        let b = str2.as_bytes();
        let suba = Self::get_sub(a);
        let subb = Self::get_sub(b);
        let ans = suba.intersection(&subb).max_by_key(|s| s.len());
        if let Some(res) = ans {
            return String::from_utf8(res.to_vec()).unwrap();
        }
        "".to_string()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::gcd_of_strings("ABCABC".to_string(), "ABC".to_string())
    );
    println!(
        "{:?}",
        Solution::gcd_of_strings("ABABAB".to_string(), "ABAB".to_string())
    );
}

//
// Created by jing at 2026-03-30 21:44
//
