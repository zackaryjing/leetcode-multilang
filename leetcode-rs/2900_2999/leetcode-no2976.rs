use std::cmp::min;
use std::collections::HashMap;

// problem: https://leetcode.cn/problems/minimum-cost-to-convert-string-i/
struct Solution;

// struct Graph {}

impl Solution {
    pub fn minimum_cost(
        source: String,
        target: String,
        original: Vec<char>,
        changed: Vec<char>,
        cost: Vec<i32>,
    ) -> i64 {
        let mut graph = vec![vec![i32::MAX; 26]; 26];
        let n = original.len();
        for i in 0..n {
            let from = (original[i] as u8 - b'a') as usize;
            let to = (changed[i] as u8 - b'a') as usize;
            graph[from][to] = graph[from][to].min(cost[i]);
        }
        for k in 0..26 {
            for i in 0..26 {
                for j in 0..26 {
                    let (e1, e2) = (graph[i][k], graph[k][j]);
                    if e1 != i32::MAX && e2 != i32::MAX {
                        graph[i][j] = graph[i][j].min(e1 + e2);
                    }
                }
            }
        }
        let m = source.len();
        let mut res = 0i64;
        let source = source.as_bytes();
        let target = target.as_bytes();
        for i in 0..m {
            let s = source[i] - b'a';
            let t = target[i] - b'a';
            let temp = graph[s as usize][t as usize];
            // println!("{:?} {:?} {:?}", s, t, temp);
            if s != t {
                if temp != i32::MAX {
                    res += temp as i64;
                } else {
                    return -1;
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::minimum_cost(
            "abcd".to_string(),
            "acbe".to_string(),
            vec!['a', 'b', 'c', 'c', 'e', 'd'],
            vec!['b', 'c', 'b', 'e', 'b', 'e'],
            vec![2, 5, 5, 1, 2, 20]
        )
    );
}

//
// Created by zhiya at 2025/5/21 15:23
//
