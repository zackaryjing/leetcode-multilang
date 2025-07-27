// problem: https://leetcode.cn/problems/longest-uploaded-prefix/

use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct LUPrefix {
    uploaded: BinaryHeap<Reverse<i32>>,
    n: usize,
    longest_prefix: i32,
}

impl LUPrefix {
    fn new(n: i32) -> Self {
        Self {
            uploaded: BinaryHeap::with_capacity(n as usize),
            n: n as usize,
            longest_prefix: 0,
        }
    }

    fn upload(&mut self, video: i32) {
        // println!("{:?}", self.uploaded);
        if video == self.longest_prefix + 1 {
            let mut cur = video;

            while let Some(&Reverse(top)) = self.uploaded.peek() {
                if !self.uploaded.is_empty() && top == cur + 1 {
                    cur = cur + 1;
                    self.uploaded.pop();
                } else {
                    break;
                }
            }
            self.longest_prefix = cur;
        } else {
            self.uploaded.push(Reverse(video));
        }
    }

    fn longest(&self) -> i32 {
        self.longest_prefix
    }
}

struct LUPrefix2 {
    uploaded: Vec<bool>,
    n: usize,
    longest_prefix: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LUPrefix2 {
    fn new(n: i32) -> Self {
        Self {
            uploaded: vec![false; n as usize + 1],
            n: n as usize,
            longest_prefix: 0,
        }
    }

    fn upload(&mut self, video: i32) {
        self.uploaded[video as usize] = true;
        if video as usize == self.longest_prefix + 1 {
            let mut cur = self.longest_prefix + 1;
            while cur < self.n && self.uploaded[cur + 1] {
                cur += 1;
            }
            self.longest_prefix = cur;
        }
    }

    fn longest(&self) -> i32 {
        self.longest_prefix as i32
    }
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * let obj = LUPrefix::new(n);
 * obj.upload(video);
 * let ret_2: i32 = obj.longest();
 */

fn main() {
    // let mut test = LUPrefix::new(4);
    // test.upload(3);
    // println!("{:?}", test.longest());
    // test.upload(1);
    // println!("{:?}", test.longest());
    // test.upload(2);
    // println!("{:?}", test.longest());
    let mut test = LUPrefix::new(5);
    test.upload(1);
    println!("{:?}", test.longest());
    test.upload(5);
    println!("{:?}", test.longest());
}

//
// Created By Zackary At 2025/7/21 16:28
//
