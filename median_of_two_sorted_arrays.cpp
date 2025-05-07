#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums1.size();
    vector<int> merged;
    int i = 0, j = 0;
    //
    // while (i < nums1.size() && j < nums2.size()) {
    //   if (nums1[i] < nums2[j]) {
    //     merged.push_back(nums1[i]);
    //     ++i;
    //   } else {
    //     merged.push_back(nums2[j]);
    //     ++j;
    //   }
    // }
    while (i < m) {
      merged.push_back(nums1[i]);
      ++i;
    }
    while (j < n) {
      merged.push_back(nums2[j]);
      ++j;
    }
    int sum = m + n;
    cout << merged.size() << '\n';
    double num = (double)(merged[sum / 2] + merged[sum / 2 - 1]) / 2;

    return ((m + n) % 2 == 0) ? num : merged[(m + n) / 2];
  }
};

int main(int argc, char *argv[]) {
  vector<int> ar1 = {1, 2};
  vector<int> ar2 = {3, 4};
  cout << Solution().findMedianSortedArrays(ar1, ar2);
  return 0;
}
