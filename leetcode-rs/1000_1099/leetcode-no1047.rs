// problem: https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
struct Solution;

impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut s: Vec<char> = s.chars().collect();
        let mut cur = 0i32;
        let mut nxt = 1;
        let n = s.len();
        while nxt < n {
            // println!("{:?} {:?}", cur, nxt);
            let v = s[cur as usize];
            if s[nxt] == v {
                cur -= 1;
                nxt += 1;
                if cur == -1 {
                    if nxt < n {
                        s[0] = s[nxt];
                        nxt += 1;
                        cur = 0;
                    } else {
                        break;
                    }
                }
            } else {
                cur += 1;
                s[cur as usize] = s[nxt];
                nxt += 1;
            }
        }
        if cur == -1 {
            String::new()
        } else {
            s[0..=cur as usize].iter().collect()
        }
    }
}

fn main() {
    println!("{:?}", Solution::remove_duplicates(String::from("aaaaaa")));
    println!("{:?}", Solution::remove_duplicates(String::from("aaaaaaa")));
    println!("{:?}", Solution::remove_duplicates(String::from("abbaca")));
    println!("{:?}", Solution::remove_duplicates(String::from("azxxzy")));
}

//
// Created by zhiya at 2025/4/18 20:20
//
