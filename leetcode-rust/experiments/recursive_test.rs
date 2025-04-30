use std::cell::RefCell;
use std::rc::Rc;

struct Solution;

fn y<'a, A, O>(f: impl Fn(&dyn Fn(A) -> O, A) -> O + 'a) -> impl Fn(A) -> O + 'a {
    fn real_y<'a, A, O>(f: &'a dyn Fn(&dyn Fn(A) -> O, A) -> O) -> impl Fn(A) -> O + 'a {
        move |a| f(&real_y(f), a)
    }
    move |a| real_y(&f)(a)
}

fn test() {
    let fact = y(|f, n| if n == 0 { 1 } else { n * f(n - 1) });
    fact(10);
}

impl Solution {
    fn test1() {
        struct Temp<'a> {
            better: &'a mut i32,
        }
        impl<'a> Temp<'a> {
            fn inner(&mut self, val: i32) {
                if val * *self.better < 200 {
                    *self.better += 1;
                    println!("{:?}, {:?}", val, self.better);
                    self.inner(val + 1);
                }
            }
        }
        let mut good = 1;
        let mut temp = Temp { better: &mut good };
        temp.inner(10);
    }

    fn test2() {
        let mut good = Rc::new(RefCell::new(1));
        let test = Rc::new(RefCell::new(None));
        let make_test: Rc<RefCell<Option<Box<dyn Fn(i32)>>>> = test.clone();
        *make_test.borrow_mut() = Some(Box::new({
            let good = good.clone();
            move |mut val| {
                if val * *good.borrow() < 200 {
                    *good.borrow_mut() += 1;
                    println!("{:?}, {:?}", val, *good.borrow());
                    test.borrow().as_ref().unwrap()(val + 1);
                }
            }
        }));
        println!("{:?}", good.borrow());
        make_test.borrow().as_ref().unwrap()(1);
    }

    fn test3() {
        let good = Rc::new(RefCell::new(1));
        let test = Rc::new(RefCell::new(None));
        let make_test: Rc<RefCell<Option<Box<dyn Fn(i32)>>>> = test.clone();

        *make_test.borrow_mut() = Some(Box::new({
            let good = good.clone();
            move |val: i32| {
                if val * *good.borrow() < 200 {
                    *good.borrow_mut() += 1;
                    println!("{:?}, {:?}", val, *good.borrow());
                    test.borrow().as_ref().unwrap()(val + 1);
                }
            }
        }));

        make_test.borrow().as_ref().unwrap()(1);
        println!("{:?}", good);
    }
}

fn main() {
    Solution::test1();
    Solution::test2();
    Solution::test3();
    ()
}
