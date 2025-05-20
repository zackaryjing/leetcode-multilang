// problem: https://leetcode.cn/problems/count-symmetric-integers/?envType=daily-question&envId=2025-04-11
struct Solution;

impl Solution {
    // 开摆，数据量很小，暴力遍历算了。
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut res = 0;
        for i in low..=high {
            let strnum = i.to_string();
            if strnum.len() % 2 == 0 {
                let num: Vec<i32> = strnum.chars().map(|a| (a as u8 - b'0') as i32).collect();
                let mid = num.len() / 2;
                res += if num[..mid].iter().sum::<i32>() == num[mid..].iter().sum::<i32>() {
                    1
                } else {
                    0
                }
            }
        }
        res
    }
}

impl Solution {
    // 题理解错了，不是真对称，而是前后之和相等
    pub fn count_symmetric_integers_2(low: i32, high: i32) -> i32 {
        let cnt_symmetric_lower = |num_o: i32| -> i32 {
            let num = num_o.to_string();
            let num: Vec<i32> = num.chars().map(|a| (a as u8 - b'0') as i32).collect();
            let mut n = num.len();
            let mut res = 0;
            let mut offset = 0;
            if n % 2 == 0 {
                let mut prefix_rev: i32 = 0;
                for i in 0..n / 2 {
                    let cur_num = num[i + offset];
                    if cur_num == 0 {
                        continue;
                    }
                    prefix_rev += cur_num * 10_i32.pow(i as u32);
                    if i == 0 {
                        res += (cur_num - 1) * 10_i32.pow((n / 2 - i - 1) as u32);
                        // println!("{res} first {cur_num} {n} {i} {offset} {num_o}");
                    } else {
                        res += cur_num * 10_i32.pow((n / 2 - i - 1) as u32);
                        // println!("{res} second");
                    }
                }
                if prefix_rev <= num_o % 10_i32.pow((n / 2) as u32) {
                    res += 1;
                }
                // println!("{res} {prefix_rev}");
                n -= 2;
            } else {
                n -= 1;
            }
            if n > 0 {
                res += 9 * 10_i32.pow((n / 2 - 1) as u32);
            }
            res
        };
        let a = cnt_symmetric_lower(high);
        // println!("{} <- ", a);
        let b = cnt_symmetric_lower(low - 1);
        // println!("{} <- ", b);
        a - b
    }
}

fn main() {
    println!("{}", Solution::count_symmetric_integers(1200, 1230));
    println!("{}", Solution::count_symmetric_integers(1, 100));
    println!("{}", Solution::count_symmetric_integers(1, 54321));
    println!("{}", Solution::count_symmetric_integers(1, 123456));
}

//
// Created by ASUS at 2025/4/11 11:36
//
