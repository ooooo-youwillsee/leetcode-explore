/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/25 07:31
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int shortestWay(string source, string target) {
    int n = target.size();
    int prev = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      // 每个字符都搜索一遍，如果返回-1，则说明没有这个字符
      int p = source.find(target[i]);
      if (p == -1) {
        return -1;
      }
      if (i == 0) {
        prev = p;
        continue;
      }

      int k = source.find(target[i], prev);
      if (k != -1) {
        dp[i] = dp[i - 1];
        prev = k + 1;
      } else {
        // 找不到，说明要用一个新的子序列
        dp[i] = dp[i - 1] + 1;
        prev = source.find(target[i]) + 1;
      }
    }

    return dp[n - 1];
  }
};
