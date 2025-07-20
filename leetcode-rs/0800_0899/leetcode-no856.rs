// problem: https://leetcode.cn/problems/score-of-parentheses/
struct Solution;

impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut stack: Vec<i32> = Vec::with_capacity(n);
        for i in 0..n {
            if s[i] == b'(' {
                stack.push(-1);
            } else {
                let mut push_val = 1;
                if let Some(&back) = stack.last() {
                    if back != -1 {
                        stack.pop(); // pop number
                        push_val = back * 2;
                    }
                    stack.pop(); // pop '('
                }
                if let Some(&back) = stack.last() {
                    if back != -1 {
                        stack.pop(); // pop number
                        push_val += back;
                    }
                }
                stack.push(push_val);
            }
            // println!("{:?}", stack);
        }
        stack[0]
    }
}

fn main() {
    println!("{:?}", Solution::score_of_parentheses("()".to_string()));
    println!("{:?}", Solution::score_of_parentheses("(()((()))())()".to_string()));
}

//
// Created by zhiya at 7/3/2025 11:52 PM
//