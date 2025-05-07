struct Solution;
impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut answer: Vec<i32> = vec![];
        let mut prefix: Vec<i32> = vec![];
        let mut postfix: Vec<i32> = vec![];
        let mut left = 1;
        let mut right = 1;
        { 0..nums.len() }.for_each(|i| {
            let mut j = nums.len() - 1;
            left *= nums[i];
            prefix[i] = nums[i] * left;

            right *= nums[j];
            prefix[i] = nums[j] * right;
            j -= 1;
        });
        return answer;
    }
}

fn main() {
    let nums = vec![1, 2, 3, 4];
    dbg!(Solution::product_except_self(nums));
}
