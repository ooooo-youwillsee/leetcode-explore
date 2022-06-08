/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/06/06 08:00
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int help(vector<int> &slices, int l, int r, int k) {
    // dp[i][j]: 表示0到i，分到j个的最大值
    vector<vector<int>> dp(r + 2, vector<int>(k + 1));

    dp[l + 1][1] = slices[l];

    for (int i = l + 1; i <= r; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i + 1][j] = max(slices[i] + dp[i - 1][j - 1], dp[i][j]);
      }
    }

    return dp[r+1][k];
  }

  int maxSizeSlices(vector<int> &slices) {
    int n = slices.size();
    return max(help(slices, 0, n - 2, n / 3), help(slices, 1, n - 1, n/3));
  }

};