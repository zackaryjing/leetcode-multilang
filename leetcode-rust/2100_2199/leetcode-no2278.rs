struct Solution;

impl Solution {
    pub fn percentage_letter(s: String, letter: char) -> i32 {
        let mut ans = 0;
        for ch in s.chars() {
            if ch == letter {
                ans += 1
            }
        }
        ans * 100 / s.len() as i32
    }
}

fn main() {
    println!(
        "{}",
        Solution::percentage_letter(String::from("foobar"), 'o')
    );
    println!("{}", Solution::percentage_letter(String::from("jjjj"), 'k'));
}
