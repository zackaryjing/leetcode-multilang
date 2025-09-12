// problem:
struct Solution;

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * struct CustomFunction;
 * impl CustomFunction {
 *    pub fn f(x:i32,y:i32)->i32{}
 * }
 */
struct CustomFunction;
impl CustomFunction {
    pub fn f(&self, x: i32, y: i32) -> i32 {
        x + y
    }
}

impl Solution {
    pub fn find_solution(customfunction: &CustomFunction, z: i32) -> Vec<Vec<i32>> {
        let n = 1000;
        let mut res = vec![];
        let mut x = 1000;
        for y in 1..=z {
            loop {
                let val = customfunction.f(x, y);
                if val > z {
                    x -= 1;
                } else if val == z {
                    if x <= 0 {
                        break;
                    }
                    res.push(vec![x, y]);
                    break;
                } else {
                    break;
                }
            }
            if x <= 0 {
                break;
            }
        }
        res
    }
}

impl Solution {
    pub fn find_solution_2(customfunction: &CustomFunction, z: i32) -> Vec<Vec<i32>> {
        let n = 1000;
        let mut res = vec![];
        for y in 1..=n {
            let mut left = 1;
            let mut right = 1000;
            while left < right {
                let x = (left + right) / 2;
                if customfunction.f(x, y) < z {
                    left = x + 1;
                } else {
                    right = x;
                }
            }
            if customfunction.f(left, y) == z {
                res.push(vec![left, y]);
            }
        }
        res
    }
}

fn main() {
    let test: CustomFunction = CustomFunction;
    println!("{:?}", Solution::find_solution(&test, 5));
}

//
// Created by jing at 2025-09-10 14:36
//
