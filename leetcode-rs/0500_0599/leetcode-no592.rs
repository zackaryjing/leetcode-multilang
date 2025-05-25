// problem: https://leetcode.cn/problems/fraction-addition-and-subtraction/
struct Solution;

impl Solution {
    pub fn gcd(mut a: i32, mut b: i32) -> i32 {
        let mut a = a.abs();
        let mut b = b.abs();
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }
    pub fn fraction_addition(expression: String) -> String {
        let mut i = 0;
        let expression = expression.as_bytes();
        let n = expression.len();
        let mut cur_val = 0;
        let mut sign = 1;
        let mut denominator = 1;
        let mut numerator = 1;
        let mut temp_numerator = 0;
        while i < n {
            if expression[i].is_ascii_digit() {
                cur_val *= 10;
                cur_val += (expression[i] - b'0') as i32;
            } else {
                if expression[i] == b'/' {
                    temp_numerator = cur_val;
                    cur_val = 0;
                } else if temp_numerator != 0 {
                    numerator = numerator * cur_val + (sign * temp_numerator * denominator);
                    denominator = denominator * cur_val;
                    let cd = Self::gcd(numerator, denominator);
                    numerator /= cd;
                    denominator /= cd;
                    cur_val = 0;
                    temp_numerator = 0;
                } else {
                    cur_val = 0;
                }
                if expression[i] == b'-' {
                    sign = -1;
                } else if expression[i] == b'+' {
                    sign = 1;
                }
            }
            i += 1;
        }
        if temp_numerator != 0 {
            numerator = numerator * cur_val + (sign * temp_numerator * denominator);
            denominator = denominator * cur_val;
            let cd = Self::gcd(numerator, denominator);
            numerator /= cd;
            denominator /= cd;
        }
        (numerator - denominator).to_string() + "/" + &denominator.to_string()
    }
}

fn main() {
    println!("{:?}", Solution::fraction_addition("2/1-6/2".to_string()));
    println!("{:?}", Solution::fraction_addition("0/3-0/2".to_string()));
    println!("{:?}", Solution::fraction_addition("0/2".to_string()));
    println!("{:?}", Solution::fraction_addition("-0/2".to_string()));
    println!("{:?}", Solution::fraction_addition("-1/2-1/2".to_string()));
    println!("{:?}", Solution::fraction_addition("1/6+2/6".to_string()));
    println!("{:?}", Solution::fraction_addition("2/5-1/1-2/1".to_string()));

}

//
// Created by zhiya at 2025/5/25 18:49
//
