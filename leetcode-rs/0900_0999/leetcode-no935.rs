// problem: https://leetcode.cn/problems/knight-dialer/
struct Solution;

impl Solution {
    pub fn knight_dialer(n: i32) -> i32 {
        let _mod = 1000_000_007i64;
        let n = n as usize;
        let mut exchange = vec![
            vec![0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            vec![0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
            vec![1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
            vec![0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
            vec![0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 1, 0, 1, 0, 0, 0, 0, 0],
        ];

        // let from = vec![vec![4, 6], vec![6, 8], vec![7, 9], vec![4, 8],
        //                 vec![3,9], vec![], vec![1,7], vec![2, 6], vec![1, 3], vec![2, 4]];
        let state = vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
        let deduce = |vec: Vec<i64>, matrix: Vec<Vec<i64>>| -> Vec<i64> {
            let mut res = vec![0; 10];
            for i in 0..10 {
                for j in 0..10 {
                    res[i] += vec[j] * matrix[i][j];
                    res[i] %= _mod;
                }
            }
            res
        };
        let multi = |matrix1: &Vec<Vec<i64>>, matrix2: &Vec<Vec<i64>>| {
            let mut res = vec![vec![0i64; 10]; 10];
            for i in 0..10 {
                for j in 0..10 {
                    for k in 0..10 {
                        res[i][j] += matrix1[i][k] * matrix2[k][j];
                        res[i][j] %= _mod;
                    }
                }
            }
            res
        };
        let mut origin = vec![
            vec![1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
        ];

        let mut k = n - 1;
        while k > 0 {
            if k & 1 == 1 {
                origin = multi(&origin, &exchange);
            }
            exchange = multi(&exchange, &exchange);
            k >>= 1;
        }

        (deduce(state, origin).iter().fold(0, |a, &b| (a + b) % _mod) % _mod) as i32
    }
}


fn main() {
    println!("{:?}", Solution::knight_dialer(1));
    println!("{:?}", Solution::knight_dialer(2));
    println!("{:?}", Solution::knight_dialer(3131));
}

//
// Created by zhiya at 2025/5/21 17:31
//
