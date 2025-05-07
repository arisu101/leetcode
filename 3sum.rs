#[derive(Debug)]
struct Solution {
    nums: Vec<i32>,
}

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        num1.sort();
        let mut num1 = nums.clone();
        let nlen = num1.len();
        let mut result: Vec<Vec<i32>> = Vec::new();
        for i in 0..nlen {
            if i > 0 && num1[i] == num1[i - 1] {
                continue;
            }
            let mut l = i + 1;
            let mut r = nlen - 1;
            while l < r {
                let sum = num1[l] + num1[r] + num1[i];
                if (sum) == 0 {
                    result.push(vec![num1[i], num1[l], num1[r]]);
                    while l < r && num1[l] == num1[l + 1] {
                        l += 1;
                    }
                    while l < r && num1[r] == num1[r - 1] {
                        r -= 1;
                    }
                    l += 1;
                    r -= 1;
                } else if sum < 0 {
                    l += 1;
                } else {
                    r -= 1;
                }
            }
        }
        result
    }
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn test() {
        let nums = vec![-1, 0, 1, 2, -1, -4];
        let expected = vec![vec![-1, -1, 2], vec![-1, 0, 1]];
        let result = Solution::three_sum(nums);
        assert_eq!(result, expected);
    }
}
