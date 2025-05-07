use std::usize;

#[derive(Debug)]
struct Solution {
    height: Vec<i32>,
}
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        // let l: i32 = height[0];
        // let r: i32 = height[height.len()];
        let mut l: usize = 0;
        let mut r: usize = height.len() - 1;
        let mut area: usize = 0;
        let mut res: usize = 0;
        while l < r {
            res = std::cmp::max(area, res);
            area = (r - l) * (std::cmp::min(height[l] as usize, height[r] as usize));
            if height[l] < height[r] {
                l += 1;
            } else {
                r -= 1;
            }
        }
        res as i32
    }
}
fn main() {
    let height = vec![1, 8, 6, 2, 5, 4, 8, 3, 7];
    println!("{}", Solution::max_area(height));
}

/*
* give integer array height of length n
*
* n verticle lines drawn such that two endpoints of of ith line is (i,0) and (i,height[i])
*
* find two lines that together with x-axis form a container, such that the container contains the
* most water
* */
