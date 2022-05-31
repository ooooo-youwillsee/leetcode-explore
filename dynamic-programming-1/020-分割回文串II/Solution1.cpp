/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/30 07:21
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCut(string s) {
    int n = s.size();

    // dp[i][j]: 表示i到j之间的字符，是否为回文串
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = i + 1 > j - 1 || dp[i + 1][j - 1];
        }
      }
    }

    // ans[i]: 表示0-i之间的有多少个回文串
    vector<int> ans(n + 1, n);
    ans[0] = 0;
    for (int i = 0; i < n; ++i) {
      // 加速计算
      if (dp[0][i]) {
        ans[i + 1] = 1;
        continue;
      }
      for (int j = i; j >= 0; --j) {
        if (dp[j][i]) {
          ans[i + 1] = min(ans[i + 1], ans[j] + 1);
        }
      }
    }

    return ans[n] - 1;
  }
};
