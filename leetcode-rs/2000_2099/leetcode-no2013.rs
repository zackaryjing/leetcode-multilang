// problem: https://leetcode.cn/problems/detect-squares/
struct Solution;

use std::collections::{HashMap, HashSet};
struct DetectSquares {
    y_to_x: HashMap<i32, HashMap<i32, i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl DetectSquares {
    // [Pass] This one is actually ok.
    fn new() -> Self {
        Self {
            y_to_x: HashMap::new(),
        }
    }

    fn add(&mut self, point: Vec<i32>) {
        self.y_to_x
            .entry(point[1])
            .or_default()
            .entry(point[0])
            .and_modify(|e| *e += 1)
            .or_insert(1);
    }

    fn count(&self, point: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let x1 = point[0];
        let y1 = point[1];

        if let Some(x2_list) = self.y_to_x.get(&y1) {
            for (x2, _cnt_first) in x2_list {
                let length = (x2 - x1).abs();
                if length > 0 {
                    for y2 in [y1 + length, y1 - length] {
                        if let Some(_x1_list) = self.y_to_x.get(&y2) {
                            cnt += _cnt_first
                                * _x1_list.get(x2).unwrap_or(&0)
                                * _x1_list.get(&x1).unwrap_or(&0);
                        }
                    }
                }
            }
        }

        cnt
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * let obj = DetectSquares::new();
 * obj.add(point);
 * let ret_2: i32 = obj.count(point);
 */

fn main() {
    let mut ds = DetectSquares_2::new();
    ds.add(vec![3, 10]);
    ds.add(vec![11, 2]);
    ds.add(vec![3, 2]);
    println!("count([11, 10]) = {}, expected = 1", ds.count(vec![11, 10]));
    println!("count([14, 8]) = {}, expected = 0", ds.count(vec![14, 8]));
    ds.add(vec![11, 2]);
    println!("count([11, 10]) = {}, expected = 2", ds.count(vec![11, 10]));
}

//
// Created by zhiya at 2025/5/17 17:51
//

struct DetectSquares_2 {
    points: HashMap<(i32, i32), i32>,
    x_to_y: HashMap<i32, HashSet<i32>>,
    y_to_x: HashMap<i32, HashSet<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl DetectSquares_2 {
    // [Pass] but f**king too slow...
    fn new() -> Self {
        Self {
            points: HashMap::new(),
            x_to_y: HashMap::new(),
            y_to_x: HashMap::new(),
        }
    }

    fn add(&mut self, point: Vec<i32>) {
        let x1 = point[0];
        let y1 = point[1];
        *self.points.entry((x1, y1)).or_insert(0) += 1;
        self.x_to_y.entry(x1).or_insert(HashSet::new()).insert(y1);
        self.y_to_x.entry(y1).or_insert(HashSet::new()).insert(x1);
    }

    fn count(&self, point: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let x1 = point[0];
        let y1 = point[1];
        // let mut base = *self.points.get(&(x1, y1)).unwrap_or(&0);
        // if base == 0 {
        //     base = 1;
        // }

        for x2 in self.y_to_x.get(&y1).unwrap_or(&HashSet::new()) {
            let length = (x2 - x1).abs();
            if length == 0 {
                continue;
            }
            for y2 in [y1 + length, y1 - length] {
                if self.x_to_y[x2].contains(&y2) {
                    if self.y_to_x[&y2].contains(&x1) {
                        println!(
                            "{:?},{:?},{:?},",
                            self.points[&(*x2, y1)],
                            self.points[&(*x2, y2)],
                            self.points[&(x1, y2)]
                        );
                        cnt += self.points[&(*x2, y1)]
                            * self.points[&(*x2, y2)]
                            * self.points[&(x1, y2)];
                    }
                }
            }
        }
        cnt
    }
}
