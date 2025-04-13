// problem: https://leetcode.cn/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13
struct Solution;

impl Solution {
    // 有待改进
    pub fn count_good_numbers2(n: i64) -> i32 {
        let _mod: i64 = (10_i32.pow(9) + 7) as i64;
        let mut res = 1;
        let mut po4 = vec![1; 51];
        let mut po5 = vec![1; 51];
        po4[0] = 4;
        po5[0] = 5;
        for i in 1..51 {
            po4[i] = (po4[i - 1] * po4[i - 1]) % _mod;
            po5[i] = (po5[i - 1] * po5[i - 1]) % _mod;
        }
        // println!("{:?}", po4);
        let times4 = n / 2;
        let times5 = (n + 1) / 2;
        for i in 0..64 {
            res = (res * if (times4 >> i) & 1 == 1 { po4[i] } else { 1 }) % _mod;
        }
        for i in 0..64 {
            res = (res * if (times5 >> i) & 1 == 1 { po5[i] } else { 1 }) % _mod;
        }
        res as i32
    }
}
impl Solution {
    pub fn count_good_numbers(n: i64) -> i32 {
        let _mod: i64 = (10_i32.pow(9) + 7) as i64;
        let mut res = 1;
        let times4 = n / 2;
        let times5 = (n + 1) / 2;
        let mut po4 = 4;
        let mut po5 = 5;
        for i in 0..64 {
            res = (res * if (times4 >> i) & 1 == 1 { po4 } else { 1 }) % _mod;
            po4 = po4 * po4 % _mod;
        }
        for i in 0..64 {
            res = (res * if (times5 >> i) & 1 == 1 { po5 } else { 1 }) % _mod;
            po5 = po5 * po5 % _mod;
        }
        res as i32
    }
}

fn main() {
    println!("{}", Solution::count_good_numbers(1));
    println!("{}", Solution::count_good_numbers(4));
    println!("{}", Solution::count_good_numbers(25));
    println!("{}", Solution::count_good_numbers(50));
}

//
// Created by ASUS at 2025/4/13 22:22
//
