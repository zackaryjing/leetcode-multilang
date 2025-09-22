// problem: https://leetcode.cn/problems/iterator-for-combination/

struct CombinationIterator {
    limit: Vec<usize>,
    pos: Vec<usize>,
    characters: String,
    m: usize,
    have_next: bool,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl CombinationIterator {
    fn new(characters: String, combinationLength: i32) -> Self {
        let n = characters.len();
        let combinationLength = combinationLength as usize;
        Self {
            limit: (0..combinationLength)
                .rev()
                .into_iter()
                .map(|num| n - num - 1)
                .collect::<Vec<usize>>(),
            pos: (0..combinationLength).collect(),
            characters,
            m: combinationLength,
            have_next: true,
        }
    }

    fn get_last(&mut self, index: usize) -> usize {
        if index == 0 && self.limit[0] == self.pos[0] {
            self.have_next = false;
            return self.limit[0];
        }
        if self.pos[index] == self.limit[index] {
            let last = self.get_last(index - 1);
            self.pos[index] = last + 1;
            last + 1
        } else {
            self.pos[index] += 1;
            self.pos[index]
        }
    }
    fn next(&mut self) -> String {
        let mut res = String::new();
        for i in 0..self.m {
            let p = self.pos[i];
            res += &self.characters[p..p + 1];
        }
        self.get_last(self.m - 1);
        res
    }

    fn has_next(&self) -> bool {
        self.have_next
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * let obj = CombinationIterator::new(characters, combinationLength);
 * let ret_1: String = obj.next();
 * let ret_2: bool = obj.has_next();
 */

fn main() {
    // let mut c = CombinationIterator::new("abcdefghi".to_string(), 5);
    let mut c = CombinationIterator::new("abc".to_string(), 2);
    println!("{:?}", c.limit);
    println!("{:?}", c.pos);
    println!("{:?}", c.has_next());
    for i in (0..3) {
        println!("{:?}", c.next());
        println!("{:?}", c.pos);
        println!("{:?}", c.has_next());
    }
}

//
// Created by jing at 2025-09-13 14:31
//
