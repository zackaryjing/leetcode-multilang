// problem:
struct Solution;

impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut nums_pos = (0..n)
            .into_iter()
            .map(|index| (nums[index], index))
            .collect::<Vec<(i32, usize)>>();
        nums_pos.sort();
        // println!("{:?}", nums_pos);
        let mut res = vec![0; n];
        let mut cur_len = 1;
        let mut diff_len = 0;
        for i in 1..n {
            if nums_pos[i].0 != nums_pos[i - 1].0 {
                res[nums_pos[i].1] = cur_len;
                diff_len = cur_len;
            } else {
                res[nums_pos[i].1] = diff_len;
            }
            cur_len += 1;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::smaller_numbers_than_current(vec![8, 1, 2, 2, 3])
    );
    println!(
        "{:?}",
        Solution::smaller_numbers_than_current(vec![7,7,7,7])
    );
}

//
// Created by jing at 2025-09-12 20:45
//
