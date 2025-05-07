use std::collections::HashSet;

struct Solution;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut s = HashSet::new();
        nums.into_iter().any(|n| s.insert(n) == false)
    }
}

fn main() {
    let nums = vec![1, 2, 3, 1];
    dbg!(&Solution::contains_duplicate(nums));
}
