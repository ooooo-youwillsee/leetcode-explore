/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/12 18:56
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }

    // dp[i][0]: 表示 第i天不偷的最大金额
    // dp[i][1]: 表示 第i天偷的最大金额
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = nums[0];

    for (int i = 1; i < n; ++i) {
      dp[i][1] = nums[i] + dp[i - 1][0];
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};