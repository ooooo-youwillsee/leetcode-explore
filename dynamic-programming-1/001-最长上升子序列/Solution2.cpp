/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/07 07:44
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();

    int i = 0;
    vector<int> v(n, 0);
    v[i++] = nums[0];

    for (int j = 1; j < n; ++j) {
      if (nums[j] > v[i - 1]) {
        v[i++] = nums[j];
      } else {
        auto it = lower_bound(v.begin(), v.begin() + i, nums[j]);
        *it = nums[j];
      }
    }

    return i;
  }
};