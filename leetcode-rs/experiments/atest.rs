// use std::cell::RefCell;
// use std::rc::Rc;
// fn main() {
//     let multiplier = 2; // 外部变量，会被闭包捕获
//
//     let f = Rc::new(RefCell::new(None));
//     let g = f.clone();
//
//     *g.borrow_mut() = Some(Box::new(move |i: u32| {
//         if i <= 1 {
//             multiplier // 使用外部变量 multiplier
//         } else {
//             i * multiplier * (f.borrow().as_ref().unwrap().as_ref())(i - 1)
//         }
//     }));
//
//     let result = g.borrow().as_ref().unwrap()(4); // 4 * 2 * 3 * 2 * 2 = 96
//     println!("Result: {}", result);
// }

use std::cell::RefCell;
use std::rc::Rc;

fn main() {
    let f = Rc::new(RefCell::new(None));
    let g: Rc<RefCell<Option<Box<dyn Fn(u32) -> u32>>>> = f.clone();
    let mut test = 2;
    *g.borrow_mut() = Some(Box::new(move |i| {
        if i <= 1 {
            1
        } else {
            test * i * f.borrow().as_ref().unwrap()(i - 1);
            test
        }
    }));
    assert_eq!(g.borrow().as_ref().unwrap()(5), 120);
}
