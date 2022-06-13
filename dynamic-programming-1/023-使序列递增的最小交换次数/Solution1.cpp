/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/06/06 20:47
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSwap(vector<int> &nums1, vector<int> &nums2) {
    int n = nums2.size();

    // dp[i][j]: 表示0到i，最少交换次数， j为0【表示当前元素不交换】，j为1【表示当前元素交换】
    vector<vector<int>> dp(n, vector<int>(2, n));

    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < n; ++i) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];

      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        dp[i][1] = min(dp[i][1], 1 + dp[i - 1][1]);
      }

      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
      }
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};