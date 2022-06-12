/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/06/06 21:08
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();

    vector<vector<double>> dp(n, vector<double>(k + 1));
    vector<double> preSum(n + 1);

    for (int i = 0; i < n; ++i) {
      preSum[i + 1] = preSum[i] + nums[i];
      dp[i][1] = preSum[i + 1] / (i + 1);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 2; j <= k; ++j) {
        for (int p = i - 1; p >= j - 2; p--) {
          dp[i][j] = max(dp[i][j], dp[p][j - 1] + (preSum[i + 1] - preSum[p + 1]) / (i - p));
        }
      }
    }

    return dp[n - 1][k];
  }
};