struct Solution;
impl Solution {
    pub fn spiral_order(matrix: &Vec<Vec<i32>>) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();
        let (mut left, mut right) = (0, matrix[0].len());
        let (mut top, mut bottom) = (0, matrix.len());
        while left < right && top < bottom {
            //go left to right and get every i in top row
            for i in left..right {
                result.push(matrix[top][i]);
            }
            top += 1;
            //go top to bottom and get every i in right column
            for i in top..bottom {
                result.push(matrix[i][right - 1]);
            }
            right -= 1;
            if !(left < right && top < bottom) {
                break;
            }
            //go right to left and get every i in bottom row
            for i in (left..right).rev() {
                result.push(matrix[bottom - 1][i]);
            }
            bottom -= 1;
            //go bottom to top and get every i in left column
            for i in (top..bottom).rev() {
                result.push(matrix[i][left]);
            }
            left += 1;
        }

        result
    }
}

fn main() {
    let matrix: Vec<Vec<i32>> = vec![vec![1, 2, 3, 4], vec![5, 6, 7, 8], vec![9, 10, 11, 12]];
    dbg!(&Solution::spiral_order(&matrix));
}

/*
 * Time Complexity : O(m*n)
 * Space Complexity : O(1)
 * */

/*
 * 1. first make the new vector and push the element of matrix[0] to new vector
 * 2. now iterate over the last element up to matrix.len() - 1 place and push to the matrix and
 *    remove those element from the matrix
 * 3. now add the last element of matrix i.e matrix[len-1] to the vector in reverse order
 * 4. after doing that remove the first and last column of the matrix
 * 5. after doing all of the above the matrix of (m-2)*(n-1) will remain
 * */

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// 1   2   3   4   5
// 6   7   8   9   10
// 11  12  13  14  15
// 16  17  18  19  20
// This is 4x5 matrix
//so the down starts after 4 th
//left starts after 7
//up starts after 11
// [1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12]
// [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20]]
//
// [[6,7,8,9],[11,12,13,14]]

/*let [r,c] be the current cell, then next cell is given as : [r!,c!] = [r+dr,c+dc], where dr and
 * dc are the respective change in rows and column
 * */

// Index	Direction	dr	dc
// 0	    Right	    0	  1
// 1     Down	      1	  0
// 2	    Left	    0	  -1
// 3	    Up	     -1	   0
