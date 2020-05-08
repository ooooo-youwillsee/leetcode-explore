package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/8 12:21
 */
public class Solution1 {

  public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    int minLen = Integer.MAX_VALUE;
    for (String str : strs) {
      minLen = Math.min(str.length(), minLen);
    }
    for (int i = 0; i < minLen; i++) {
      char c = strs[0].charAt(i);
      for (int j = 1; j < strs.length; j++) {
        if (c != strs[j].charAt(i)) return strs[0].substring(0, i);
      }
    }
    return strs[0].substring(0, minLen);
  }

  private static void test(String[] strs) {
    Solution1 solution1 = new Solution1();
    System.out.println(solution1.longestCommonPrefix(strs));
  }

  public static void main(String[] args) {
    test(new String[]{"flower", "flow", "flight"});
    test(new String[]{"dog", "racecar", "car"});
  }
}
