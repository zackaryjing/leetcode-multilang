use std::u32;

struct Bitset {
    data: Vec<u32>,
    size: i32,
    cnt: i32, // 用于记录当前 1 的个数
}

impl Bitset {
    fn new(size: i32) -> Self {
        let n = ((size - 1) / 32) as usize + 1;
        Bitset {
            data: vec![0u32; n],
            size,
            cnt: 0, // 初始为 0
        }
    }

    fn fix(&mut self, idx: i32) {
        let k = (idx >> 5) as usize;
        let j = idx & 0b11111;

        // 只有当原位为 0 时，才更新 cnt
        if (self.data[k] & (1 << j)) == 0 {
            self.data[k] |= 1 << j;
            self.cnt += 1;
        }
    }

    fn unfix(&mut self, idx: i32) {
        let k = (idx >> 5) as usize;
        let j = idx & 0b11111;

        // 只有当原位为 1 时，才更新 cnt
        if (self.data[k] & (1 << j)) != 0 {
            self.data[k] &= !(1 << j);
            self.cnt -= 1;
        }
    }

    fn flip(&mut self) {
        for num in &mut self.data {
            *num = !*num;
        }
        // 更新 cnt 为当前位集大小减去原本的 cnt，因为全翻转
        self.cnt = (self.size - self.cnt) as i32;
    }

    fn all(&self) -> bool {
        self.cnt == self.size
    }

    fn one(&self) -> bool {
        self.cnt > 0
    }

    fn count(&self) -> i32 {
        self.cnt
    }

    fn to_string(&self) -> String {
        let mut res = vec!['0'; self.size as usize];
        let k = (self.size >> 5) as usize;
        for i in 0..k {
            let temp = self.data[i];
            for t in 0..32 {
                if (temp >> t) & 1 == 1 {
                    res[i * 32 + t] = '1';
                }
            }
        }

        let j = (self.size & 0b11111) as usize;
        if j > 0 {
            let temp = self.data[k];
            for t in 0..j {
                if (temp >> t) & 1 == 1 {
                    res[k * 32 + t] = '1';
                }
            }
        }
        res.iter().collect()
    }
}

/**
 * Your Bitset object will be instantiated and called as such:
 * let obj = Bitset::new(size);
 * obj.fix(idx);
 * obj.unfix(idx);
 * obj.flip();
 * let ret_4: bool = obj.all();
 * let ret_5: bool = obj.one();
 * let ret_6: i32 = obj.count();
 * let ret_7: String = obj.to_string();
 */

fn main() {
    let mut obj = Bitset::new(1);
    println!("After Bitset::new: actual: {}, expected: 0", obj.to_string());

    let res1 = obj.all();
}
//
// Created by zhiya at 2025/5/2 16:29
//
