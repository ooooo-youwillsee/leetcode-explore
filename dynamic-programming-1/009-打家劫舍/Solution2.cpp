/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/12 19:08
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

    // dp[i]: 表示第i天的最大金额
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);

    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[n - 1];
  }
};