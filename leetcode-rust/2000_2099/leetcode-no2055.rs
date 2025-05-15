// problem: https://leetcode.cn/problems/plates-between-candles/
struct Solution;

impl Solution {
    pub fn plates_between_candles(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let s = s.as_bytes();
        let mut pos: Vec<usize> = Vec::new();
        for (index, ch) in s.iter().enumerate() {
            if *ch == b'|' {
                pos.push(index);
            }
        }
        let m = queries.len();
        let mut res: Vec<i32> = Vec::with_capacity(m);
        for query in queries {
            let left = query[0] as usize;
            let right = query[1] as usize;
            let pos1 = pos.partition_point(|num| *num < left);
            let pos2 = pos.partition_point(|num| *num <= right);
            if pos2 > pos1 + 1 {
                res.push((pos[pos2 - 1] - pos[pos1]) as i32 + 1 - (pos2 - pos1) as i32);
            } else {
                res.push(0);
            }
        }
        res
    }
}

impl Solution {
    // [Pass] Perf
    pub fn plates_between_candles_2(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let s = s.as_bytes();
        let mut cnt = 0;
        let mut pos: Vec<(usize, i32)> = Vec::new();
        for (index, ch) in s.iter().enumerate() {
            if *ch == b'|' {
                pos.push((index, cnt));
            } else {
                cnt += 1;
            }
        }
        let m = queries.len();
        let mut res: Vec<i32> = Vec::with_capacity(m);
        for query in queries {
            let left = query[0] as usize;
            let right = query[1] as usize;
            let pos1 = pos.partition_point(|num| num.0 < left);
            let mut pos2 = pos.partition_point(|num| num.0 <= right);
            if pos2 > pos1 + 1 {
                pos2 -= 1;
                res.push(pos[pos2].1 - pos[pos1].1);
            } else {
                res.push(0);
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::plates_between_candles(
            "***|**|*****|**||**|*".to_string(),
            vec![
                vec![1, 17],
                vec![4, 5],
                vec![14, 17],
                vec![5, 11],
                vec![15, 16]
            ]
        )
    );
    println!(
        "{:?}",
        Solution::plates_between_candles("**|**|***|".to_string(), vec![vec![2, 5], vec![5, 9]])
    );
}

//
// Created by zhiya at 2025/5/15 22:35
//
