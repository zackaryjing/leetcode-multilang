// problem: https://leetcode.cn/problems/largest-multiple-of-three/description/
struct Solution;

impl Solution {
    pub fn largest_multiple_of_three(digits: Vec<i32>) -> String {
        let mut digits = digits;
        digits.sort();
        let tot: i32 = digits.iter().sum();
        let mut modify_digits = |miss: i32| -> bool {
            let c1 = miss + 1;
            let c2 = (1 ^ miss) + 1;
            let mut found = false;
            for (index, num) in digits.iter_mut().enumerate() {
                if (*num % 3 == c1) {
                    digits.remove(index);
                    return true;
                }
            }
            let mut pos1 = -1;
            let mut pos2 = -1;
            for (index, num) in digits.iter_mut().enumerate() {
                if *num % 3 == c2 {
                    if (pos1 >= 0) {
                        pos2 = index as i32;
                        found = true;
                        break;
                    } else {
                        pos1 = index as i32;
                    }
                }
            }
            if (found) {
                digits.remove(pos2 as usize);
                digits.remove(pos1 as usize);
                return true;
            } else {
                return false;
            }
        };
        if (tot % 3 == 1) {
            if !modify_digits(0) {
                return "".to_string();
            }
        } else if (tot % 3 == 2) {
            if !modify_digits(1) {
                return "".to_string();
            }
        }
        if digits.is_empty() {
            return "".to_string();
        }
        while (*digits.last().unwrap() == 0 && digits.len() >= 2) {
            digits.pop();
        }
        String::from_utf8(
            digits
                .iter_mut()
                .map(|digit: &mut i32| -> u8 {
                    return *digit as u8 + b'0';
                })
                .rev()
                .collect::<Vec<u8>>(),
        ).unwrap()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::largest_multiple_of_three(vec![8, 6, 7, 1, 0])
    );
    println!("{:?}", Solution::largest_multiple_of_three(vec![0, 0, 0]));
    println!(
        "{:?}",
        Solution::largest_multiple_of_three(vec![1, 2, 3, 4])
    );
    println!("{:?}", Solution::largest_multiple_of_three(vec![1]));
    println!("{:?}", Solution::largest_multiple_of_three(vec![8, 1, 9]));
}

//
// Created by zhiya at 2025/5/15 20:00
//
