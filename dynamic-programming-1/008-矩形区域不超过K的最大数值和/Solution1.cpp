/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/20 07:29
 */


#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT32_MIN;

    for (int i = 0; i < m; ++i) {
      vector<int> cols(n, 0);
      for (int j = i; j < m; ++j) {

        int preSum = 0;
        set<int> s_;
        s_.insert(0);

        for (int l = 0; l < n; ++l) {
          cols[l] += matrix[j][l];
          int sum = preSum + cols[l];

          auto it = s_.lower_bound(sum - k);
          if (it != s_.end()) {
            ans = max(ans, sum - *it);
          }
          s_.insert(sum);
          preSum = sum;
        }
      }
    }

    return ans;
  }
};