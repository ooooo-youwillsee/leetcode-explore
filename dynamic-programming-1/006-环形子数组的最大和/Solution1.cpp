/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/13 06:59
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int n = nums.size();

    vector<int> dpMin(n, 0), dpMax(n, 0);
    dpMin[0] = dpMax[0] = nums[0];

    int sum = nums[0];
    int minSum = dpMin[0], maxSum = dpMax[0];
    for (int i = 1; i < n; ++i) {
      dpMax[i] = nums[i] + max(0, dpMax[i - 1]);
      dpMin[i] = nums[i] + min(0, dpMin[i - 1]);

      maxSum = max(maxSum, dpMax[i]);
      minSum = min(minSum, dpMin[i]);
      sum += nums[i];
    }

    // maxSum < 0 说明这个数组都是负数， 这是相当于求数组中每个值的最大值
    return maxSum < 0 ? maxSum : max(maxSum, sum - minSum);
  }
};