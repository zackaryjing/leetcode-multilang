// problem:
struct Solution;

use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashMap};

#[derive(Eq, PartialEq)]
struct Task(i32, i32, i32);

impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.2 < other.2 {
            Ordering::Less
        } else if self.2 > other.2 {
            Ordering::Greater
        } else {
            if self.1 < other.1 {
                Ordering::Less
            } else {
                Ordering::Greater
            }
        }
    }
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct TaskManager {
    tasklist: BinaryHeap<Task>,
    taskmap: HashMap<i32, Task>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TaskManager {
    fn new(tasks: Vec<Vec<i32>>) -> Self {
        let mut temp = Self {
            tasklist: BinaryHeap::new(),
            taskmap: HashMap::new(),
        };
        for task in tasks {
            temp.tasklist.push(Task(task[0], task[1], task[2]));
            temp.taskmap
                .insert(task[1], Task(task[0], task[1], task[2]));
        }
        temp
    }

    fn add(&mut self, user_id: i32, task_id: i32, priority: i32) {
        self.tasklist.push(Task(user_id, task_id, priority));
        self.taskmap
            .insert(task_id, Task(user_id, task_id, priority));
    }

    fn edit(&mut self, task_id: i32, new_priority: i32) {
        let old_task = self.taskmap.get_mut(&task_id).unwrap();
        let user_id = old_task.0;
        self.tasklist.push(Task(user_id, task_id, new_priority));
        *old_task = Task(user_id, task_id, new_priority);
    }

    fn rmv(&mut self, task_id: i32) {
        self.taskmap.remove(&task_id);
    }

    fn exec_top(&mut self) -> i32 {
        let mut user_id = -1;
        while !self.tasklist.is_empty() {
            let task = self.tasklist.pop().unwrap();
            if let Some(val) = self.taskmap.get_mut(&task.1) {
                // println!("{:?} ,{:?} ,{:?}", val.0, val.1, val.2);
                if val.2 == task.2 {
                    user_id = task.0;
                    self.rmv(task.1);
                    break;
                }
            }
        }
        user_id
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * let obj = TaskManager::new(tasks);
 * obj.add(userId, taskId, priority);
 * obj.edit(taskId, newPriority);
 * obj.rmv(taskId);
 * let ret_4: i32 = obj.exec_top();
 */

fn main() {
    let mut results = vec![];

    // 创建 TaskManager，并初始化任务
    let mut tm = TaskManager::new(vec![vec![1, 101, 10], vec![2, 102, 20], vec![3, 103, 15]]);
    results.push(None); // "TaskManager" 初始化，对应 null

    // add([4, 104, 5])
    tm.add(4, 104, 5);
    results.push(None);

    // edit(102, 8)
    tm.edit(102, 8);
    results.push(None);

    // execTop() -> 3
    let out = tm.exec_top();
    println!("execTop() => got: {}, expected: {}", out, 3);
    results.push(Some(out));

    // rmv(101)
    tm.rmv(101);
    results.push(None);

    // add([5, 105, 15])
    tm.add(5, 105, 15);
    results.push(None);

    // execTop() -> 5
    let out = tm.exec_top();
    println!("execTop() => got: {}, expected: {}", out, 5);
    results.push(Some(out));

    // Optional: 打印所有结果
    println!("Results: {:?}", results);
}

//
// Created by zhiya at 2025/5/13 19:07
//
