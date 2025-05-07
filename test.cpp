#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int test(vector<int> &prices) {
    int test = prices[0];
    return 1;
  }
};

int main(int argc, char *argv[]) {

  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << Solution().test(prices) << endl;

  return 0;
}
