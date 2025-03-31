struct Solution;

impl Solution {
    pub fn add_spaces2(s: String, spaces: Vec<i32>) -> String {
        let sn = s.len();
        let vn = spaces.len();
        let n = sn + vn;
        let mut res = vec![' '; n];
        let mut target = 0;
        let mut iter = s.chars();
        for i in 0..vn {
            let end = spaces[i] as usize;
            while target < end {
                if let Some(c) = iter.next() {
                    res[target + i] = c;
                    target += 1;
                } else {
                    break;
                }
            }
        }
        while let Some(c) = iter.next() {
            res[target + vn] = c;
            target += 1;
        }
        String::from_iter(res)
    }
}

impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut res = String::with_capacity(s.len() + spaces.len());
        let mut j = 0;
        for i in 0..s.len() {
            if j < spaces.len() && i == spaces[j] as usize {
                res.push(' ');
                j += 1;
            }
            res.push(s.as_bytes()[i] as char);
        }
        res
    }
}

fn main() {
    println!(
        "{}",
        Solution::add_spaces(String::from("LeetcodeHelpsMeLearn"), vec![8, 13, 15])
    );
}
