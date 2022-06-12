/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/06/07 07:21
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();

    // dp[i]: 表示 i 到 n -1 之间的最大值
    vector<double> dp(n);
    vector<double> preSum(n + 1);

    for (int i = 0; i < n; ++i) {
      preSum[i + 1] = preSum[i] + nums[i];
    }

    for (int i = n - 1; i >= 0; --i) {
      dp[i] = (preSum[n] - preSum[i]) / (n - i);
    }

    for (int j = 2; j <= k; ++j) {
      for (int i = 0; i < n; ++i) {
        for (int p = i + 1; p < n; p++) {
          dp[i] = max(dp[i], dp[p] + (preSum[p] - preSum[i]) / (p - i));
        }
      }
    }

    return dp[0];
  }
};