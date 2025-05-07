struct Solution;
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        for i in 0..matrix.len() {
            for j in (i + 1)..matrix.len() {
                let temp;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for i in 0..matrix.len() {
            matrix[i].reverse();
        }
    }
}

fn main() {
    let mut matrix: Vec<Vec<i32>> = vec![
        vec![5, 1, 9, 11],
        vec![2, 4, 8, 10],
        vec![13, 3, 6, 7],
        vec![15, 14, 12, 16],
    ];
    //let mut matrix: Vec<Vec<i32>> = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    //let mut matrix = vec![vec![1]];
    Solution::rotate(&mut matrix);
    dbg!(&matrix);
}
/*
 * TIME COMPLEXITY: O(n^2)
 * SPACE COMPLEXITY: O(1)
 * */

//QUESTION:
/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
*You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

// 1   2   3
// 4   5   6
// 7   8   9

/*
 * for the matrx of nxn the element on position i,j will be moved to position (j,n-1-i) in the
 * rotated matrix
 * */
