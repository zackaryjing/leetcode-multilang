// problem: https://leetcode.cn/problems/last-substring-in-lexicographical-order/

struct Solution;

impl Solution {
    pub fn last_substring(s: String) -> String {
        let mut i = 0;
        let mut j = 1;
        let mut k = 0;
        let s = s.as_bytes();
        let n = s.len();
        while j + k < n {
            let ch1 = s[i + k];
            let ch2 = s[j + k];
            if ch1 > ch2 {
                j = j + k + 1;
                k = 0;
            } else if ch1 < ch2 {
                i += k + 1;
                k = 0;
                if i >= j {
                    j = i + 1;
                }
            } else {
                k += 1;
            }
        }
        String::from_utf8(s[i..].to_vec()).unwrap()
    }
}

impl Solution {
    // [TLE]
    pub fn last_substring_2(s: String) -> String {
        let s = s.as_bytes();
        let n = s.len();
        let mut candidate: Vec<usize> = Vec::new();
        let mut res: Vec<u8> = Vec::new();
        let mut last = u8::MIN;
        for i in 0..n {
            if s[i] >= last {
                if s[i] > last {
                    candidate.clear();
                    last = s[i];
                }
                candidate.push(i);
            }
        }
        let mut cur_len = 1;
        while candidate.len() != 1 {
            last = s[candidate[0] + cur_len];
            let mut new_candidate = Vec::new();
            for &c in &candidate {
                if c + cur_len < n && s[c + cur_len] >= last {
                    if s[c + cur_len] > last {
                        last = s[c + cur_len];
                        new_candidate.clear();
                    }
                    new_candidate.push(c);
                }
            }
            candidate = new_candidate;
            cur_len += 1;
        }

        String::from_utf8(s[candidate[0]..].to_vec()).unwrap()
    }
}

fn main() {
    println!("{:?}", Solution::last_substring("abab".to_string()));
    println!("{:?}", Solution::last_substring("leetcode".to_string()));
}

//
// Created By Zackary At 2025/7/4 10:21
//
