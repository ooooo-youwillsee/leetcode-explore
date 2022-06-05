/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/30 07:01
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int n = s.size();

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (s[i] <= '9' && s[i] >= '1') {
        dp[i + 1] += dp[i];
      }
      if (s[i - 1] == '1' && s[i] <= '9' && s[i] >= '0') {
        dp[i + 1] += dp[i - 1];
      }
      if (s[i - 1] == '2' && s[i] <= '6' && s[i] >= '0') {
        dp[i + 1] += dp[i - 1];
      }
    }

    return dp[n];
  }
};
