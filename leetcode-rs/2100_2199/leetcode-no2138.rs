// problem: https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/?envType=daily-question&envId=2025-06-24
struct Solution;

impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let n = s.len();
        let s = s.as_bytes();
        let k = k as usize;
        let m = (n / k) + 1;
        let mut res = Vec::with_capacity(m);
        let mut temp = Vec::with_capacity(k);
        temp.push(s[0]);
        for i in 1..n {
            if i % k == 0 {
                res.push(String::from_utf8(temp).unwrap());
                temp = Vec::with_capacity(k);
            }
            temp.push(s[i]);
        }
        if temp.len() > 0 {
            if temp.len() < k {
                temp.append(&mut vec![fill as u8; k - temp.len()]);
            }
            res.push(String::from_utf8(temp).unwrap());
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::divide_string("abcdefghi".to_string(), 3, 'x')
    );
}

//
// Created by zhiya at 6/24/2025 4:12 PM
//
