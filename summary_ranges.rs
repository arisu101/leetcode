struct Solution;
impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut result: Vec<String> = vec![];
        let mut i = 0;
        while i < nums.len() {
            let start = nums[i];
            while i < nums.len() - 1 && nums[i] + 1 == nums[i + 1] {
                i += 1;
            }
            if start != nums[i] {
                result.push(format!("{}->{}", start, nums[i]));
            } else {
                result.push(start.to_string());
            }
            i += 1;
        }
        return result;
    }
}

fn main() {
    let nums: Vec<i32> = vec![0, 1, 2, 4, 5, 7];
    dbg!(Solution::summary_ranges(nums));
}
