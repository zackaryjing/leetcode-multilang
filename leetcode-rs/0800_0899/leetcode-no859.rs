use std::ffi::c_char;

// problem: https://leetcode.cn/problems/buddy-strings/
struct Solution;

impl Solution {
    pub fn buddy_strings(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            false
        } else {
            let mut cur = 0;
            let mut occur_twice = false;
            let n = s.len();
            let mut found = vec![false, false];
            let mut chs = vec![0u8, 0u8];
            for i in 0..n {
                let s: Vec<u8> = s.bytes().collect();
                let goal: Vec<u8> = goal.bytes().collect();
                let temp = s[i] - 'a' as u8;
                if !occur_twice {
                    if (cur >> temp) & 1 == 1 {
                        occur_twice = true;
                    } else {
                        cur |= 1 << (s[i] - 'a' as u8);
                    }
                }
                if s[i] != goal[i] {
                    if found[1] {
                        return false;
                    } else if found[0] {
                        if s[i] != chs[1] || goal[i] != chs[0] {
                            return false;
                        } else {
                            found[1] = true
                        }
                    } else {
                        found[0] = true;
                        chs[0] = s[i];
                        chs[1] = goal[i];
                    }
                }
            }
            if found[1] || (!found[0] && occur_twice) {
                true
            } else {
                false
            }
        }
    }
}

fn main() {
    println!(
        "{:?} false",
        Solution::buddy_strings(String::from("aa"), String::from("bb"))
    );
    println!(
        "{:?} true",
        Solution::buddy_strings(String::from("aa"), String::from("aa"))
    );
    println!(
        "{:?} true",
        Solution::buddy_strings(String::from("ab"), String::from("ba"))
    );
    println!(
        "{:?} false",
        Solution::buddy_strings(String::from("ab"), String::from("ab"))
    );
    println!(
        "{:?} true",
        Solution::buddy_strings(String::from("ahcdefg"), String::from("afcdehg"))
    );
}

//
// Created by zhiya at 2025/4/22 16:10
//
