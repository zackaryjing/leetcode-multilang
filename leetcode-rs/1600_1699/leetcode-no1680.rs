// problem: https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/
struct Solution;

#[derive(Eq, PartialEq)]
struct OrdNum(i32);

const BASE: usize = 15;
const SIGN_MASK: i32 = (!(u32::MAX >> 1)) as i32;

fn aligment(mut num: i32) -> (i32, i32) {
    let mut rlength = 0;
    while num > 0 {
        num <<= 1;
        rlength += 1;
    }
    (rlength, num)
}
impl Ord for OrdNum {
    fn cmp(&self, other: &Self) -> Ordering {
        let all_zero1 = (self.0 & (self.0 + 1)) == 0;
        let all_zero2 = (other.0 & (other.0 + 1)) == 0;
        if all_zero1 & all_zero2 {
            Ordering::Equal
        } else if all_zero1 {
            Ordering::Greater
        } else if all_zero2 {
            Ordering::Less
        } else {
            // println!("m: {:?}", SIGN_MASK);
            let (first_r_len, first) = aligment(self.0 << BASE);
            let (second_r_len, second) = aligment(other.0 << BASE);
            for i in 0..32 - BASE {
                let sign1 = (first << i) & SIGN_MASK;
                let sign2 = (second << i) & SIGN_MASK;
                // println!("i: {:?} , s: {:?} {:?}", i, sign1, sign2,);
                if sign1 == sign2 {
                    continue;
                } else {
                    // println!("s: {:?} {:?}", sign1, sign2);
                    return sign2.cmp(&sign1);
                }
            }

            // println!("l: {:?} {:?}", first_r_len, second_r_len);
            first_r_len.cmp(&second_r_len)
        }
    }
}

impl PartialOrd for OrdNum {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn last_one(num: i32) -> i32 {
    for i in (0..=31).rev() {
        if (num >> i) & 0x1 == 1 {
            return i;
        }
    }
    0
}

use std::cmp::Ordering;
use std::collections::BinaryHeap;

const MOD: i64 = 1000_000_007;
impl Solution {
    pub fn concatenated_binary(n: i32) -> i32 {
        let mut nums: BinaryHeap<OrdNum> = BinaryHeap::new();
        let mut res: i64 = 0;

        let mut length = 0;

        for num in 1..=n {
            // if nums.len() >= 11 {
            //     nums.pop();
            // }
            nums.push(OrdNum(num));
        }

        let candidate = nums.into_sorted_vec();
        for c in &candidate {
            print!("{:b}, ", c.0);
        }
        println!();
        let mut index = 0;
        let mut shift = 0;
        while length < 32 && index < candidate.len() {
            let temp = (candidate[index].0 << length) as i64;
            println!("temp: {:b} length: {:?}", temp, length);
            res += temp;

            shift = last_one(candidate[index].0) + 1;
            println!("S: {:?} {:b}", shift, candidate[index].0);
            length += shift;
            index += 1;
        }
        println!("{:b}", res % MOD);
        (res % MOD) as i32
    }
}

fn main() {
    println!("{:?} 1", Solution::concatenated_binary(1));
    println!("{:?} 27", Solution::concatenated_binary(3));
    println!("{:?} 505379714", Solution::concatenated_binary(12));
}

//
// Created by zhiya at 7/8/2025 9:33 PM
//
