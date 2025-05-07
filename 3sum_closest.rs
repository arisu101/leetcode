//use std::char::MAX;
use std::time::Instant;

struct Solution;
impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();
        //let mut closest: i32 = MAX as i32;
        let len: usize = nums.len();
        let mut closest: i32 = nums[0] + nums[1] + nums[len - 1];
        for i in 0..len {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let (mut left, mut right) = (i + 1, len - 1);
            while left < right && left > 0 && right < len {
                let s = nums[i] + nums[left] + nums[right];
                if s == target {
                    return s;
                } else if (closest - target).abs() > (s - target).abs() {
                    closest = s;
                } else if s < target {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }
        return closest;
    }
}

fn main() {
    let start = Instant::now();
    let nums: Vec<i32> = vec![2, 5, 6, 7];
    let target: i32 = 16;
    dbg!(&Solution::three_sum_closest(nums, target));
    let duration = start.elapsed();
    println!("{:.3}", duration.as_secs_f32() * 1000.0);
}

/*
 * TIME COMPLEXITY : O(n^2)
 * SPACE COMPLEXITY : O(n)
 * */

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
//
//
// Example 1:
//
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
// Example 2:
// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
// Constraints:
//
//     3 <= nums.length <= 500
//     -1000 <= nums[i] <= 1000
//     -104 <= target <= 104
