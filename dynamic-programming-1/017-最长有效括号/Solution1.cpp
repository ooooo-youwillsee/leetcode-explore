/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/27 06:51
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size();

    int ans = 0;
    vector<int> dp(n + 1, 0);

    for (int i = 1; i < n; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i + 1] = dp[i - 1] + 2;
        } else if (i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(') {
          dp[i + 1] = dp[i] + 2 + dp[i - dp[i] - 1];
        }
      }
      ans = max(ans, dp[i + 1]);
    }

    return ans;
  }
};
