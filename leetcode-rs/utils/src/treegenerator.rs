use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::collections::VecDeque;

pub fn string_to_tree_node(data: &str) -> Option<Rc<RefCell<TreeNode>>> {
    let data = data.trim();
    if data.len() <= 2 {
        return None;
    }
    // 去掉 [ ]
    let inner = &data[1..data.len() - 1];
    if inner.trim().is_empty() {
        return None;
    }
    let vals: Vec<&str> = inner.split(',').map(|s| s.trim()).collect();

    let root_val: i32 = vals[0].parse().unwrap();
    let root = Rc::new(RefCell::new(TreeNode::new(root_val)));
    let mut queue = VecDeque::new();
    queue.push_back(root.clone());
    let mut i = 1;

    while !queue.is_empty() && i < vals.len() {
        let node = queue.pop_front().unwrap();
        // left
        if i < vals.len() && vals[i] != "null" {
            let left_val: i32 = vals[i].parse().unwrap();
            let left_node = Rc::new(RefCell::new(TreeNode::new(left_val)));
            node.borrow_mut().left = Some(left_node.clone());
            queue.push_back(left_node);
        }
        i += 1;
        // right
        if i < vals.len() && vals[i] != "null" {
            let right_val: i32 = vals[i].parse().unwrap();
            let right_node = Rc::new(RefCell::new(TreeNode::new(right_val)));
            node.borrow_mut().right = Some(right_node.clone());
            queue.push_back(right_node);
        }
        i += 1;
    }
    Some(root)
}

pub fn tree_node_to_string(root: &Option<Rc<RefCell<TreeNode>>>) -> String {
    if root.is_none() {
        return "[]".to_string();
    }
    let mut output: Vec<String> = Vec::new();
    let mut queue = VecDeque::new();
    queue.push_back(root.clone());

    while !queue.is_empty() {
        let node_opt = queue.pop_front().unwrap();
        if let Some(node_rc) = node_opt {
            let node_ref = node_rc.borrow();
            output.push(node_ref.val.to_string());
            queue.push_back(node_ref.left.clone());
            queue.push_back(node_ref.right.clone());
        } else {
            output.push("null".to_string());
        }
    }

    // 去掉末尾的 null
    while output.last().map_or(false, |s| s == "null") {
        output.pop();
    }

    format!("[{}]", output.join(","))
}

pub fn pretty_print_tree(node: &Option<Rc<RefCell<TreeNode>>>, prefix: String, is_left: bool) {
    if let Some(node_rc) = node {
        let node_ref = node_rc.borrow();
        if node_ref.right.is_some() {
            pretty_print_tree(
                &node_ref.right,
                prefix.clone() + if is_left { "│   " } else { "    " },
                false,
            );
        }
        println!(
            "{}{}{}",
            prefix,
            if is_left { "└── " } else { "┌── " },
            node_ref.val
        );
        if node_ref.left.is_some() {
            pretty_print_tree(
                &node_ref.left,
                prefix + if is_left { "    " } else { "│   " },
                true,
            );
        }
    } else {
        println!("Empty tree");
    }
}
