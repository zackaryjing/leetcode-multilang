
// problem: https://leetcode.cn/problems/reorganize-string/
struct Solution;

// time spent: 24:25
use std::collections::BinaryHeap;
impl Solution {
    pub fn reorganize_string(s: String) -> String {
        let n = s.len();
        let mut res: Vec<u8> = Vec::with_capacity(n);
        let mut cnt = vec![0; 26];
        for k in s.as_bytes() {
            cnt[(k - b'a') as usize] += 1;
        }
        let mut chars: BinaryHeap<(i32, u8)> = BinaryHeap::from(
            cnt.iter()
                .enumerate().filter(|item| *item.1 != 0)
                .map(|item| (*item.1, item.0 as u8 + b'a'))
                .collect::<Vec<(i32, u8)>>(),
        );
        while !chars.is_empty() {
            let first = chars.pop().unwrap();
            res.push(first.1);
            if let Some(second) = chars.pop() {
                res.push(second.1);
                if second.0 > 1 {
                    chars.push((second.0 - 1, second.1))
                }
            } else {
                let k = res.len();
                if k > 1 && res[k - 1] == res[k - 2]{
                    return "".to_string();
                }
            }
            if first.0 > 1 {
                chars.push((first.0 - 1, first.1));
            }
        }
        String::from_utf8(res).unwrap()
    }
}

fn main() {
    println!("{:?}", Solution::reorganize_string("aab".to_string()));
    println!("{:?}", Solution::reorganize_string("aaab".to_string()));
}

//
// Created by zhiya at 2025/5/26 13:57
//
