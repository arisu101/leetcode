struct Solution;

macro_rules! _MAX {
    ($a:expr, $b:expr) => {
        if $a > $b {
            $a
        } else {
            $b
        }
    };
}

impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        //let mut intervals: Vec<Vec<i32>> = intervals.clone();
        //intervals.sort();

        if intervals.is_empty() {
            return vec![];
        }

        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut output: Vec<Vec<i32>> = Vec::new();

        //output.push(intervals[0].to_vec());
        output.push(intervals[0].clone());

        //for interval in intervals.iter().skip(1) {
        for interval in intervals.into_iter().skip(1) {
            //let (start, end) = (interval[0], interval[1]);
            //let last_value = output[output_length - 1][1];
            let last_value = output.last_mut().unwrap();

            if last_value[1] >= interval[0] {
                last_value[1] = last_value[1].max(interval[1]);
            } else {
                output.push(interval);
            }
        }

        return output;
    }
}

fn main() {
    let intervals: Vec<Vec<i32>> = vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]];
    dbg!(Solution::merge(intervals));
}

// Example 1:
//
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//
// Example 2:
//
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// 1. Sort the intervals
// 2. loop through the vectors and find the intervals between nested vectors
//
//
// Constraints:
//
//     1 <= intervals.length <= 104
//     intervals[i].length == 2
//     0 <= starti <= endi <= 104
