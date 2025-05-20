// problem: https://leetcode.cn/problems/can-make-palindrome-from-substring/
struct Solution;
impl Solution {
    pub fn can_make_pali_queries(s: String, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = queries.len();
        let mut res = Vec::with_capacity(n);
        let mut cnts = vec![0i32; s.len() + 1];

        for (i, ch) in s.as_bytes().iter().enumerate() {
            cnts[i + 1] = cnts[i];
            cnts[i + 1] ^= 1 << (ch - b'a');
        }
        for query in queries {
            let mut cnt = 0;
            cnt += (cnts[query[1] as usize + 1] ^ cnts[query[0] as usize]).count_ones();
            res.push(if cnt / 2 > query[2] as u32 {
                false
            } else {
                true
            });
        }
        res
    }
}

impl Solution {
    // [Pass] perf
    pub fn can_make_pali_queries_2(s: String, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = queries.len();
        let mut res = Vec::with_capacity(n);

        let mut cnts = vec![vec![0i32; 26]; s.len() + 1];

        for (i, ch) in s.as_bytes().iter().enumerate() {
            for j in 0..26 {
                cnts[i + 1][j] = cnts[i][j];
            }
            cnts[i + 1][(ch - b'a') as usize] = cnts[i][(ch - b'a') as usize] + 1;
        }
        for query in queries {
            let mut cnt = 0;
            for j in 0..26 {
                cnt += (cnts[query[1] as usize + 1][j] - cnts[query[0] as usize][j]) & 1;
            }
            res.push(if cnt / 2 > query[2] { false } else { true });
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::can_make_pali_queries(
            "abcda".to_string(),
            vec![
                vec![3, 3, 0],
                vec![1, 2, 0],
                vec![0, 3, 1],
                vec![0, 3, 2],
                vec![0, 4, 1]
            ]
        )
    );
    println!(
        "{:?}",
        Solution::can_make_pali_queries("lyb".to_string(), vec![vec![0, 1, 0], vec![2, 2, 1]])
    );
}

//
// Created by zhiya at 2025/5/11 20:43
//
