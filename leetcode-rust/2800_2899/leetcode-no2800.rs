// problem: https://leetcode.cn/problems/shortest-string-that-contains-three-strings/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn minimum_string(a: String, b: String, c: String) -> String {
        let merge = |s: &str, t: &str| -> String {
            if s.contains(t) {
                return s.to_string();
            }
            if t.contains(s) {
                return t.to_string();
            }
            for i in (1..=min(s.len(), t.len())).rev() {
                if s[s.len() - i..] == t[..i] {
                    return s.to_string() + &t[i..];
                }
            }
            s.to_string() + t
        };
        let mut res = "".to_string();

        let a: &str = &a;
        let b: &str = &b;
        let c: &str = &c;
        let ways = vec![
            (&a, &b, &c),
            (&a, &c, &b),
            (&b, &c, &a),
            (&b, &a, &c),
            (&c, &b, &a),
            (&c, &a, &b),
        ];
        for (i, j, k) in ways {
            let s = merge(&merge(i, j), k);
            if res == "" || s.len() < res.len() || s.len() == res.len() && s < res {
                res = s;
            }
        }
        res.to_string()
    }
}

impl Solution {
    // [Fatal] Writing too much useless code recently...
    // Too bloated...
    pub fn minimum_string_2(a: String, b: String, c: String) -> String {
        let check = |a: &[u8], b: &[u8], c: &[u8]| -> Vec<u8> {
            let mut valid_offset_a = a.len();
            for offset_a in (0..a.len()).rev() {
                for i in offset_a..=a.len() {
                    if i == a.len() || i - offset_a >= b.len() {
                        valid_offset_a = offset_a;
                        break;
                    }
                    if a[i] != b[i - offset_a] {
                        break;
                    }
                }
            }

            let mut valid_offset_b = b.len();
            for offset_b in (0..b.len()).rev() {
                for i in offset_b..=b.len() {
                    if i == b.len() || i - offset_b >= c.len() {
                        valid_offset_b = offset_b;
                        break;
                    }
                    if b[i] != c[i - offset_b] {
                        break;
                    }
                }
            }

            let tot_size = max(
                valid_offset_a + valid_offset_b + c.len(),
                max(a.len(), valid_offset_a + b.len()),
            );
            println!("tot_size: {:?}", tot_size);
            let mut res: Vec<u8> = Vec::with_capacity(tot_size);
            for i in 0..tot_size {
                if i < valid_offset_a {
                    res.push(a[i]);
                } else if i < valid_offset_a + valid_offset_b {
                    res.push(b[i - valid_offset_a]);
                } else if i < valid_offset_a + valid_offset_b + c.len() {
                    res.push(c[i - valid_offset_a - valid_offset_b]);
                } else if i < valid_offset_a + b.len() {
                    res.push(b[i - valid_offset_a]);
                } else {
                    res.push(a[i]);
                }
            }
            res
        };

        let a = a.as_bytes();
        let b = b.as_bytes();
        let c = c.as_bytes();
        let ways = vec![
            (a, b, c),
            (a, c, b),
            (b, c, a),
            (b, a, c),
            (c, b, a),
            (c, a, b),
        ];
        let mut candidate: Vec<Vec<u8>> = vec![];
        let mut min_length = usize::MAX;
        for (i, j, k) in ways {
            let res = check(i, j, k);
            println!(
                "{:?} {:?}",
                String::from_utf8(res.clone()).unwrap(),
                res.len()
            );
            if res.len() < min_length {
                println!("{:?} {:?} 2", res.len(), min_length);
                candidate.clear();
                min_length = res.len();
                candidate.push(res);
            } else if res.len() == min_length {
                println!("{:?} {:?} 1", res.len(), min_length);
                candidate.push(res);
            }
        }
        for i in 0..min_length {
            println!(
                "{:?} {:?} <<",
                candidate.len(),
                candidate
                    .iter()
                    .map(|k| { String::from_utf8(k.clone()).unwrap() })
                    .collect::<Vec<String>>()
            );
            let mut first_ch = b'z';
            if candidate.len() == 1 {
                break;
            }
            for j in 0..candidate.len() {
                first_ch = min(candidate[j][i], first_ch);
            }
            for j in (0..candidate.len()).rev() {
                if (candidate[j][i] > first_ch) {
                    candidate.remove(j);
                }
            }
        }

        String::from_utf8(candidate[0].clone()).unwrap()
    }
}

fn main() {
    println!(
        "{:?} --- aac",
        Solution::minimum_string("aa".to_string(), "a".to_string(), "c".to_string())
    );
    println!(
        "{:?} --- aa",
        Solution::minimum_string("a".to_string(), "aa".to_string(), "a".to_string())
    );
    println!(
        "{:?} --- aaabca",
        Solution::minimum_string("abc".to_string(), "bca".to_string(), "aaa".to_string())
    );
    println!(
        "{:?} --- aba",
        Solution::minimum_string("ab".to_string(), "ba".to_string(), "aba".to_string())
    );
    println!(
        "{:?} --- xyyyzxzyzzz",
        Solution::minimum_string("xyyyz".to_string(), "xzyz".to_string(), "zzz".to_string())
    );
}

//
// Created by zhiya at 2025/5/16 20:46
//
