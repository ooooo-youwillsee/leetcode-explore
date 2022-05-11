/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/10 20:04
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &e1, const vector<int> &e2) {
      return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
    });

    int n = envelopes.size();
    vector<vector<int>> nums(n);

    int k = 0;
    nums[k++] = envelopes[0];

    for (int i = 1; i < n; ++i) {
      if (envelopes[i][0] > nums[k - 1][0] && envelopes[i][1] > nums[k - 1][1]) {
        nums[k++] = envelopes[i];
        continue;
      }

      auto it =
          lower_bound(nums.begin(), nums.begin() + k, envelopes[i], [&](const vector<int> &x, const vector<int> &y) {
            return x[1] < y[1];
          });

      if (it != nums.end()) {
        *it = envelopes[i];
      }
    }

    return k;
  }
};