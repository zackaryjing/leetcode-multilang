// problem: https://leetcode.cn/problems/longest-happy-string/
struct Solution;
impl Solution {
    pub fn longest_diverse_string(a: i32, b: i32, c: i32) -> String {
        let mut chars = vec![(a, b'a'), (b, b'b'), (c, b'c')];
        let mut res: Vec<u8> = Vec::new();
        let mut index = 0usize;
        loop {
            chars.sort();
            chars.reverse();
            let mut has_next = false;
            for i in 0..3 {
                if chars[i].0 <= 0 {
                    break;
                }
                if index >= 2 && res[index - 1] == chars[i].1 && res[index - 2] == chars[i].1 {
                    continue;
                }
                has_next = true;
                res.push(chars[i].1);
                chars[i].0 -= 1;
                break;
            }
            index += 1;
            if !has_next {
                break;
            }
        }
        String::from_utf8(res).unwrap()
    }
}

impl Solution {
    // [Fatal] I just couldn't think of a rational enough solution.(:<)
    pub fn longest_diverse_string_2(a: i32, b: i32, c: i32) -> String {
        let mut chars = vec![b'a', b'b', b'c'];
        let mut nums = vec![a, b, c];
        for index in 0..nums.len() {
            let limit = (nums[(index + 1) % 3] + nums[(index + 2) % 3] + 1) * 2;
            if limit > nums[index] {
                nums[index] = limit;
            }
        }
        let mut res: Vec<u8> = vec![];
        for index in 0..nums.len() {
            let this = nums[index] + 1;
            let that = nums[(index + 1) % 3];
            let other = nums[(index + 1) % 3] + nums[(index + 2 % 3)];
            if this * 2 >= other && this <= other {
                for i in 0..other {
                    if i < that {
                        res.push(chars[(index + 1) % 3]);
                    } else {
                        res.push(chars[(index + 2) % 3])
                    }
                    if i % 2 == 1 {
                        res.push(chars[index]);
                    }
                }
            }
            if other * 2 >= this && other <= this {
                for i in 0..this {
                    res.push(chars[index]);
                    if i % 2 == 1 {
                        if i < that {}
                    }
                }
            }
        }

        "".to_string()
    }
}

fn main() {
    println!("{:?}", Solution::longest_diverse_string(1, 1, 7));
}

//
// Created by zhiya at 2025/5/15 23:09
//
