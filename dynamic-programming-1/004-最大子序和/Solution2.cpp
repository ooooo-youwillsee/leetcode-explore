/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/18 06:37
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 分治法
 */
class Solution {
 public:

  struct Node {
    // 包含左端点的最大连续数组和
    int lSum;
    // 包含右端点的最大连续数组和
    int rSum;
    // 中间的最大啊连续数组和
    int mSum;
    // 包含两个端点，总的数组和
    int tSum;
  };

  int maxSubArray(vector<int> &nums) {
    return merge(nums, 0, nums.size() - 1).mSum;
  }

  Node merge(vector<int> &nums, int l, int r) {
    if (l == r) {
      return {nums[l], nums[l], nums[l], nums[l]};
    }

    int mid = l + (r - l) / 2;
    Node lNode = merge(nums, l, mid);
    Node rNode = merge(nums, mid + 1, r);

    int lSum = max(lNode.lSum, lNode.tSum + rNode.lSum);
    int rSum = max(rNode.rSum, rNode.tSum + lNode.rSum);
    int mSum = max(max(lNode.mSum, rNode.mSum), lNode.rSum + rNode.lSum);
    int tSum = lNode.tSum + rNode.tSum;

    return {lSum, rSum, mSum, tSum};
  }

};
