#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min_price = prices[0];
    int max_profit = 0;
    for (int price : prices) {
      if (min_price > price) {
        min_price = price;
      }
      int profit = price - min_price;
      if (profit > max_profit) {
        max_profit = profit;
      }
    }
    return max_profit;
  }
};
;
int main(int argc, char *argv[]) {

  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << Solution().maxProfit(prices) << endl;

  return 0;
}
