use std::collections::HashSet;

struct Solution;
impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut count: i32 = 0;
        let set: HashSet<char> = jewels.chars().collect();
        for stone in stones.chars() {
            if set.contains(&stone) {
                count += 1;
            }
        }

        return count;
    }
}
fn main() {
    let jewels = String::from("aA");
    let stones = String::from("aAAbbbb");
    dbg!(&Solution::num_jewels_in_stones(jewels, stones));
}

/*
 * TIME COMPLEXITY: O(n+m)
 * SPACE COMPLEXITY: O(1)
 * */
/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have.
Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".


Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
*/

// O(m*n) solution
// impl Solution {
//     pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
//         let mut count: i32 = 0;
//         for stone in stones.chars() {
//             if jewels.contains(stone) {
//                 count += 1;
//             }
//         }
//
//         return count;
//     }
// }
