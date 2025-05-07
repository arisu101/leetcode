#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    int minLength = 200;
    for (const auto &s : strs) {
      minLength = min(minLength, (int)s.size());
    }
    int i = 0;

    while (i < minLength) {
      for (const auto &s : strs) {
        if (s[i] != strs[0][i]) {
          return strs[0].substr(0, i);
        }
      }
      i++;
    }
    return NULL;
  }
};

int main(int argc, char *argv[]) { return 0; }
