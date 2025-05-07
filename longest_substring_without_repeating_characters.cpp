#include <iostream>
#include <set>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int l = 0;
    int longest = 0;
    int w;
    set<char> myset;
    for (int i = 0; i < s.size(); i++) {
      while (myset.find(s[i]) != myset.end()) {
        myset.erase(s[l]);
        l++;
      }
      w = (i - l) + 1;
      longest = (longest > w) ? longest : w;
      myset.insert(s[i]);
    }
    return longest;
  }
};

int main(int argc, char *argv[]) {

  string test;
  cin >> test;
  cout << Solution().lengthOfLongestSubstring(test);
  return 0;
}

// Time : o(n)
// space : o(n)
