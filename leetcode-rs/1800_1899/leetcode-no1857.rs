// problem: https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/?envType=daily-question&envId=2025-05-26
struct Solution;
struct Solution_2;
use utils::vec_helper::print_matrix;

use std::cmp::max;
use std::collections::{HashMap, HashSet, VecDeque};


// time spent: 2:15:41
impl Solution {
    // [Pass] with the help of gpt...
    pub fn largest_path_value(colors: String, edges: Vec<Vec<i32>>) -> i32 {
        let n = colors.len();
        if n == 0 {
            return -1;
        }
        if edges.is_empty() {
            return 1;
        }
        let colors = colors.as_bytes();

        let mut graph: Vec<Vec<usize>> = vec![vec![]; n];
        let mut in_degree: Vec<usize> = vec![0; n];

        for edge in edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            graph[u].push(v);
            in_degree[v] += 1;
        }

        let mut queue = VecDeque::new();
        for i in 0..n {
            if in_degree[i] == 0 {
                queue.push_back(i);
            }
        }

        let mut paths = vec![[0i32; 26]; n];
        let mut count = 0;
        let mut ans = 0;

        while let Some(node) = queue.pop_front() {
            count += 1;
            let c = (colors[node] - b'a') as usize;
            paths[node][c] += 1;
            ans = max(ans, paths[node][c]);

            for &neigh in &graph[node] {
                for i in 0..26 {
                    paths[neigh][i] = max(paths[neigh][i], paths[node][i]);
                }
                in_degree[neigh] -= 1;
                if in_degree[neigh] == 0 {
                    queue.push_back(neigh);
                }
            }
        }
        if count != n {
            return -1;
        }
        ans
    }
}

impl Solution_2 {
    // [TLE] time exceeded, but should be correct ...
    pub fn largest_path_value(colors: String, edges: Vec<Vec<i32>>) -> i32 {
        if edges.is_empty() {
            if colors.len() > 0 {
                return 1;
            } else {
                return -1;
            }
        }
        let mut edge_set: HashSet<(i32, i32)> = HashSet::new();
        let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut in_degree: HashMap<i32, i32> = HashMap::new();
        for edge in edges {
            edge_set.insert((edge[0], edge[1]));
            graph.entry(edge[0]).or_default().push(edge[1]);
            in_degree.entry(edge[0]).or_default();
            *in_degree.entry(edge[1]).or_default() += 1;
        }

        let mut to_process: VecDeque<i32> = VecDeque::new();
        for (key, val) in &in_degree {
            if *in_degree.get(&key).unwrap() == 0 {
                to_process.push_back(*key);
            }
        }

        let mut res: Vec<i32> = Vec::new();
        while !to_process.is_empty() {
            // println!("to_process: {:?}", to_process);
            // println!("-------------");
            let node = to_process.pop_front().unwrap();
            res.push(node);
            // println!("rm : {:?}", node);
            in_degree.remove(&node);
            if let Some(list) = graph.get(&node) {
                for neighbour in list {
                    // println!("geting : {:?}", neighbour);
                    let ni = in_degree.get_mut(neighbour).unwrap();
                    *ni -= 1;
                    if *ni == 0 {
                        to_process.push_back(*neighbour);
                    }
                }
            }
        }

        if !in_degree.is_empty() {
            return -1;
        }
        // println!("{:?}", res);

        let colors = colors.as_bytes();
        let n = res.len();
        let mut paths: Vec<Vec<i32>> = vec![vec![0; 26]; n];
        let mut ans = 0;
        for i in 0..n {
            let color = colors[res[i] as usize] - b'a';
            for j in 0..i {
                if edge_set.contains(&(res[j], res[i])) {
                    for k in 0..26 {
                        paths[i][k] = max(paths[i][k], paths[j][k]);
                        ans = max(ans, paths[i][k]);
                    }
                }
            }
            paths[i][color as usize] += 1;
            // print_matrix(&paths);
            ans = max(ans, paths[i][color as usize]);
            // println!();
        }
        ans
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::largest_path_value(
            "abaca".to_string(),
            vec![vec![0, 1], vec![0, 2], vec![2, 3], vec![3, 4]]
        )
    );
    println!(
        "{:?}",
        Solution::largest_path_value("a".to_string(), vec![vec![0, 0]])
    );
}

//
// Created by zhiya at 2025/5/26 16:04
//
