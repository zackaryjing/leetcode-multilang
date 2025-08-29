// problem: https://leetcode.cn/problems/diagonal-traverse/?envType=daily-question&envId=2025-08-25
struct Solution;

impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let n = mat.len() as i32;
        let m = mat[0].len() as i32;
        let length = (m * n) as usize;
        let mut res = vec![0; length];
        let mut curx = 0i32;
        let mut cury = 0i32;
        let mut diffx = 1i32;
        let mut diffy = -1i32;
        let mut pos = 0usize;
        let mut first = false;
        let mut second = false;
        let mut third = false;
        let mut forth = false;
        while pos != length {
            res[pos] = mat[cury as usize][curx as usize];
            first = curx == m - 1;
            second = cury == 0;
            third = cury == n - 1;
            forth = curx == 0;
            if (first || second) && diffx > 0 {
                if !first && second {
                    curx += 1;
                    cury -= 1;
                }
                curx += 1;
                diffy = 1;
                diffx = -1;
            } else if (third || forth) && diffy > 0 {
                if !third && forth {
                    cury += 1;
                    curx -= 1;
                }
                cury += 1;
                diffy = -1;
                diffx = 1;
            }
            curx += diffx;
            cury += diffy;
            pos += 1;
        }
        res
    }
}

impl Solution {
    // [Pass] perf ok, try to improve
    pub fn find_diagonal_order_2(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let n = mat.len() as i32;
        let m = mat[0].len() as i32;
        let length = (m * n) as usize;
        let mut res = vec![0; length];

        let mut curx = 0i32;
        let mut cury = 0i32;
        let mut diffx = 1i32;
        let mut diffy = -1i32;
        let mut pos = 0usize;
        while (pos != length) {
            res[pos] = mat[cury as usize][curx as usize];
            if (curx == m - 1 || cury == 0) && diffx > 0 {
                if curx != m - 1 && cury == 0 {
                    curx += 2;
                    cury -= 1;
                } else if curx == m - 1 {
                    curx += 1;
                }
                diffy = 1;
                diffx = -1;
            } else if (cury == n - 1 || curx == 0) && diffy > 0 {
                if cury != n - 1 && curx == 0 {
                    cury += 2;
                    curx -= 1;
                } else if cury == n - 1 {
                    cury += 1;
                }
                diffy = -1;
                diffx = 1;
            }
            curx += diffx;
            cury += diffy;
            pos += 1;
        }
        res
    }
}

fn main() {
    println!(
        "{:?} e:[1,2,4,7,5,3,6,8,9]",
        Solution::find_diagonal_order(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]])
    );
    println!(
        "{:?} e:[1,2,3,4]",
        Solution::find_diagonal_order(vec![vec![1, 2], vec![3, 4]])
    );
}

//
// Created by jing at 2025-08-25 20:42
//
