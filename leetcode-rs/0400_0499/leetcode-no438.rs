// problem: https://leetcode.cn/problems/find-all-anagrams-in-a-string/
struct Solution;

impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let n = s.len();
        let m = p.len();
        let s = s.as_bytes();
        let p = p.as_bytes();
        if n < m {
            return Vec::new();
        }
        let mut second = [0; 26];
        for i in 0..m {
            second[(p[i] - b'a') as usize] += 1;
        }
        let mut cnt = [0; 26];
        let mut res = vec![];
        for i in 0..m - 1{
            cnt[(s[i] - b'a') as usize] += 1;
        }
        for i in 0..=n - m {
            cnt[(s[i + m - 1] - b'a') as usize] += 1;
            if cnt == second {
                res.push(i as i32);
            }
            cnt[(s[i] - b'a') as usize] -= 1;
        }
        res
    }
}

struct Solution_2;
impl Solution_2 {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let n = s.len();
        let m = p.len();
        let s = s.as_bytes();
        let p = p.as_bytes();
        if n < m {
            return Vec::new();
        }
        let mut prefix = vec![vec![0; 26]; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i].clone();
            prefix[i + 1][(s[i] - b'a') as usize] += 1;
        }
        let mut second = vec![0; 26];
        for i in 0..m {
            second[(p[i] - b'a') as usize] += 1;
        }
        let mut res = vec![];
        for i in 0..=n - m {
            let mut valid = true;
            for j in 0..26 {
                // println!("{:?},{:?}", prefix[i + m][j] - prefix[i][j], second[j]);
                if prefix[i + m][j] - prefix[i][j] != second[j] {
                    valid = false;
                    break;
                }
            }
            if valid {
                res.push(i as i32);
                // println!();
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::find_anagrams("cbaebabacd".to_string(), "abc".to_string())
    );
    println!(
        "{:?}",
        Solution::find_anagrams("abab".to_string(), "ab".to_string())
    );
}

//
// Created by zhiya at 2025/5/26 22:18
//
