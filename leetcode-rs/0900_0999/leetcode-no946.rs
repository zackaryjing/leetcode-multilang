// problem: https://leetcode.cn/problems/validate-stack-sequences/
struct Solution;

impl Solution {
    pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
        let mut st: Vec<i32> = Vec::with_capacity(pushed.len());
        let mut j = 0;
        for i in 0..popped.len() {
            if st.is_empty() || *st.last().unwrap() != popped[i] {
                if j == pushed.len() {
                    return false;
                }
                while j < pushed.len() && (st.is_empty() || *st.last().unwrap() != popped[i]) {
                    st.push(pushed[j]);
                    j += 1;
                }
            }
            st.pop();
        }
        true
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::validate_stack_sequences(vec![1, 2, 3, 4, 5], vec![4, 5, 3, 2, 1])
    );
}

//
// Created by jing at 2026-01-27 12:45
//
