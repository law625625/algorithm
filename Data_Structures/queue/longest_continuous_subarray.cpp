//https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class Solution {
public:
   int longestSubarray(vector<int>& nums, int limit) {
  
    int n = nums.size();
      vector<int>qmax(n,0),qmin(n,0);
    // hh1, tt1 维护最大值队列（从大到小）
    // hh2, tt2 维护最小值队列（从小到大）
    int hh1 = 0, tt1 = -1, hh2 = 0, tt2 = -1;
    int res = 0;

    // j 是左边界，i 是右边界
    for (int i = 0, j = 0; i < n; i++) {
        // 1. 右边界 i 进队，维护 maxDeque
        while (hh1 <= tt1 && nums[qmax[tt1]] <= nums[i]) tt1--;
        qmax[++tt1] = i;

        // 2. 右边界 i 进队，维护 minDeque
        while (hh2 <= tt2 && nums[qmin[tt2]] >= nums[i]) tt2--;
        qmin[++tt2] = i;

        // 3. 如果当前窗口最大值 - 最小值 > limit，左边界 j 右移
        while (hh1 <= tt1 && hh2 <= tt2 && nums[qmax[hh1]] - nums[qmin[hh2]] > limit) {
            j++;
            // 检查队头下标是否已经滑出窗口 [j, i]
            if (qmax[hh1] < j) hh1++;
            if (qmin[hh2] < j) hh2++;
        }

        // 4. 更新答案
        res = max(res, i - j + 1);
    }

    return res;
}
};
