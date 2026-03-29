#https://leetcode.cn/problems/daily-temperatures/
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)

        r = [0] * n

        stk = [0] * (n + 1)
        tt = 0
        # 找的是比我大的，小压大
        for i in range(n):
            while tt > 0 and temperatures[i] > temperatures[stk[tt]]:
                idx = stk[tt];
                tt -= 1;
                r[idx] = i - idx;
            tt += 1
            stk[tt] = i
        return r
