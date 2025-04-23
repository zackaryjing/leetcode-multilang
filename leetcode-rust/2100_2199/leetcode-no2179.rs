// problem: https://leetcode.cn/problems/count-good-triplets-in-an-array/solutions/1277695/deng-jie-zhuan-huan-shu-zhuang-shu-zu-by-xmyd/?envType=daily-question&envId=2025-04-21

struct FenwickTree {
    tree: Vec<i64>,
}

impl FenwickTree {
    pub fn new(n: usize) -> Self {
        Self {
            tree: vec![0; n + 1],
        }
    }
    pub fn update(&mut self, mut i: i32, val: i32) {
        while i < self.tree.len() as i32 {
            self.tree[i as usize] += val as i64;
            i += i & -i;
        }
    }

    pub fn pre(&mut self, mut i: i32) -> i64 {
        let mut res = 0i64;
        while i > 0 {
            res += self.tree[i as usize];
            i &= i - 1;
        }
        res
    }
}

struct Solution;

impl Solution {
    // [Offical]
    pub fn good_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let n = nums1.len();
        let mut p = vec![0; n];
        for (i, x) in nums1.iter().enumerate() {
            p[*x as usize] = i;
        }
        let mut ans = 0i64;
        let mut t = FenwickTree::new(n);
        for (i, y) in nums2.iter().enumerate() {
            let y = p[*y as usize];
            let less = t.pre(y as i32);
            ans += less * (n - 1 - y - (i - less as usize)) as i64;
            t.update((y + 1) as i32, 1);
        }
        ans
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::good_triplets(vec![2, 0, 1, 3], vec![0, 1, 2, 3])
    );
    println!(
        "{:?}",
        Solution::good_triplets(vec![4, 0, 1, 3, 2], vec![4, 1, 1, 2, 3])
    );
}

//
// Created by zhiya at 2025/4/21 15:11
//
