
// problem: https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-02
struct Solution;

use std::mem::swap;
impl Solution {
    pub fn number_of_pairs(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut res = 0;
        for i in 0..n {
            for j in i + 1..n {
                let (mut ix, mut iy) = (points[i][0], points[i][1]);
                let (mut jx, mut jy) = (points[j][0], points[j][1]);
                if (ix - jx) * (iy - jy) > 0 {
                    continue;
                }
                if ix > jx || jy > iy {
                    swap(&mut ix, &mut jx);
                    swap(&mut iy, &mut jy);
                }
                let mut valid = true;
                for k in 0..n {
                    if k == i || k == j {
                        continue;
                    }
                    let (kx, ky) = (points[k][0], points[k][1]);
                    if (ix <= kx && kx <= jx && jy <= ky && ky <= iy) {
                        valid = false;
                        break;
                    }
                }
                if valid {
                    res += 1;
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?} e:2",
        Solution::number_of_pairs(vec![vec![0,1],vec![0,2],vec![0,4]])
    );
    println!(
        "{:?} e:0",
        Solution::number_of_pairs(vec![vec![1,1],vec![2,2],vec![3,3]])
    );
    println!(
        "{:?} e:2",
        Solution::number_of_pairs(vec![vec![3, 1], vec![1, 3], vec![1, 1]])
    );
    println!(
        "{:?} e:2",
        Solution::number_of_pairs(vec![vec![6, 2], vec![4, 4], vec![2, 6]])
    );
}

//
// Created by jing at 2025-09-02 13:14
//
