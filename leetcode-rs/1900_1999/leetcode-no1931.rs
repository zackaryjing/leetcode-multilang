// problem: https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/?envType=daily-question&envId=2025-05-18
struct Solution;

use std::collections::HashMap;

const MOD: usize = 1_000_000_007;

struct Helper {
    valid: Vec<(usize, Vec<usize>)>,
    m: usize,
    n: usize,
    adjacent: HashMap<usize, Vec<usize>>,
}

impl Helper {
    pub fn new(m: usize, n: usize) -> Self {
        Self {
            valid: Vec::new(),
            m,
            n,
            adjacent: HashMap::new(),
        }
    }

    pub fn get_valid(&mut self) {
        let mm = 3usize.pow(self.m as u32);
        let color: Vec<(usize, Vec<usize>)> = (0..mm)
            .map(|mut mask| {
                (
                    mask,
                    (0..self.m)
                        .map(|_| {
                            let temp = mask % 3;
                            mask /= 3;
                            return temp;
                        })
                        .collect(),
                )
            })
            .collect();
        for c in color {
            let mut is_valid = true;
            for i in 1..self.m {
                if c.1[i] == c.1[i - 1] {
                    is_valid = false;
                    break;
                }
            }
            if is_valid {
                self.valid.push(c);
            }
        }
    }

    pub fn gen_adjacent(&mut self) {
        for c1 in &self.valid {
            let mut temp = self.adjacent.entry(c1.0).or_insert(Vec::new());
            for c2 in &self.valid {
                let mut is_valid = true;
                if c1.0 != c2.0 {
                    for i in 0..self.m {
                        if c1.1[i] == c2.1[i] {
                            is_valid = false;
                            break;
                        }
                    }
                    if is_valid {
                        temp.push(c2.0);
                    }
                }
            }
        }
    }

    pub fn gen_res(&self) -> i32 {
        let mut g: HashMap<usize, usize> = HashMap::new();
        for c in &self.valid {
            g.insert(c.0, 1);
        }
        for j in 1..self.n {
            let mut new_g: HashMap<usize, usize> = HashMap::new();
            for c in &g {
                for k in &self.adjacent[c.0] {
                    let mut temp = new_g.entry(*k).or_default();
                    *temp += c.1;
                    *temp %= MOD;
                }
            }
            g = new_g;
        }
        g.into_iter()
            .map(|c| return c.1)
            .collect::<Vec<usize>>()
            .into_iter()
            .reduce(|a, b| (a + b) % MOD)
            .unwrap()  as i32
    }
}

impl Solution {
    pub fn color_the_grid(m: i32, n: i32) -> i32 {
        let mut helper = Helper::new(m as usize, n as usize);
        helper.get_valid();
        helper.gen_adjacent();
        helper.gen_res()
    }
}

fn main() {
    println!("{:?}", Solution::color_the_grid(2, 37));
    println!("{:?}", Solution::color_the_grid(5, 5));
    println!("{:?}", Solution::color_the_grid(1, 1));
    println!("{:?}", Solution::color_the_grid(1, 2));
}

//
// Created by zhiya at 2025/5/18 22:20
//
