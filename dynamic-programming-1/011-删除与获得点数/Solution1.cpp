/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/19 07:15
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int deleteAndEarn(vector<int> &nums) {
    unordered_map<int, int> m;

    int maxSum = 1;
    for (auto num: nums) {
      m[num]++;
      maxSum = max(num, maxSum);
    }

    vector<int> dp(maxSum + 1, 0);
    dp[1] = 1 * m[1];

    for (int i = 2; i <= maxSum; ++i) {
      dp[i] = max(dp[i - 1], i * m[i] + dp[i - 2]);
    }

    return dp[maxSum];
  }
};