// problem: https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-05-13
struct Solution;

impl Solution {
    pub fn length_after_transformations(s: String, t: i32) -> i32 {
        let s = s.as_bytes();
        let t = t as usize;
        let extra = t % 26;
        let m = 10i64.pow(9) + 7;
        let mut raw_cnts = vec![0; 26];
        for ch in s {
            raw_cnts[(ch - b'a') as usize] += 1;
        }
        let mut cnts = vec![0; 26];
        for j in 0..26 {
            cnts[(j + extra) % 26] += raw_cnts[j];
        }
        for j in (26 - extra)..26 {
            cnts[(j + extra + 1) % 26] += raw_cnts[j];
        }
        let times = t / 26;
        let mut table = vec![vec![1i64; 26]; 2];
        for time in 1..=times {
            for i in 0..25 {
                table[time & 1][i] = (table[(time + 1) & 1][i + 1] + table[(time + 1) & 1][i]) % m;
            }
            table[time & 1][25] =
                (table[(time + 1) & 1][25] + table[(time + 1) & 1][0] + table[(time + 1) & 1][1])
                    % m;
        }
        // println!("times: {:?}", times);
        // println!("{:?}", table[0]);
        // println!("{:?}", table[1]);
        let mut res = 0;
        for i in 0..26 {
            res += table[times & 1][i] * cnts[i];
            res %= m;
        }
        res as i32
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::length_after_transformations("jqktcurgdvlibczdsvnsg".to_string(), 7517)
    );
    println!(
        "{:?}",
        Solution::length_after_transformations("abcyy".to_string(), 2)
    );
    println!(
        "{:?}",
        Solution::length_after_transformations("azbk".to_string(), 1)
    );
}

//
// Created by zhiya at 2025/5/13 10:09
//
