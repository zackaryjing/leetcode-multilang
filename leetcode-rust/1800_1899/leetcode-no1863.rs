struct Solution;

impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for num in &nums {
            ans |= num;
        }
        ans << nums.len() - 1
    }
}

fn main() {
    println!("{}", Solution::subset_xor_sum(Vec::from([5, 1, 6])));
    println!("{}", Solution::subset_xor_sum(Vec::from([1, 3])));
    println!(
        "{}",
        Solution::subset_xor_sum(Vec::from([3, 4, 5, 6, 7, 8]))
    );
}
