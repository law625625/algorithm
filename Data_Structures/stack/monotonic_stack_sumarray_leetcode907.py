#https://leetcode.cn/problems/sum-of-subarray-minimums/submissions/
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        mod = 10 ** 9 + 7

        a = arr + [-1]
        stk = [0] * (n + 2)
        l = [0] * (n + 1)
        tt = 0
        ans = 0

        for i in range(n + 1):
            while tt > 0 and a[stk[tt]] >= a[i]:
                cur = stk[tt]
                if tt > 1:
                    left_bound = stk[tt - 1]
                else:
                    left_bound = -1
                left = cur - left_bound
                right = i - cur
                sum = left * right * a[cur]
                ans = (ans + sum) % mod
                tt -= 1

            tt += 1
            stk[tt] = i
        return ans
