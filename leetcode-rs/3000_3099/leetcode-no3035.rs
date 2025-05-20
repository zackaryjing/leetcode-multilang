// problem: https://leetcode.cn/problems/maximum-palindromes-after-operations/
struct Solution;

impl Solution {
    pub fn max_palindromes_after_operations(words: Vec<String>) -> i32 {
        let n = words.len();
        let mut singular = 0;
        let mut paris = 0;
        let mut cnts = vec![0; 26];
        let mut sizes: Vec<usize> = Vec::with_capacity(n);
        for word in words {
            let word = word.as_bytes();
            sizes.push(word.len());
            for ch in word {
                cnts[(ch - b'a') as usize] += 1;
            }
        }
        for letter in cnts {
            if letter & 1 == 1 {
                singular += 1;
            }
            paris += letter / 2;
        }
        let mut res = 0;
        sizes.sort();
        for size in sizes {
            let p_cnts = size / 2;
            let s_cnts = size % 2;

            if s_cnts > 0 {
                if singular <= 0 {
                    singular += 1;
                    paris -= 1;
                } else {
                    singular -= 1;
                }
            }
            if paris >= p_cnts {
                paris -= p_cnts;
                res += 1;
            } else {
                break;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::max_palindromes_after_operations(vec!["abbb".to_string(),"ba".to_string(),"aa".to_string()]));
    println!("{:?}", Solution::max_palindromes_after_operations(vec!["abc".to_string(),"ab".to_string()]));
    println!("{:?}", Solution::max_palindromes_after_operations(vec!["cd".to_string(),"ef".to_string(),"a".to_string()]));
}

//
// Created by zhiya at 2025/5/16 16:14
//
