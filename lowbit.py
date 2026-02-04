
#https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&ru=/exam/oj
class Solution:
    def lowbit(self, n: int) -> int:
        return n & (~n + 1)

    def NumberOf1(self, n: int) -> int:
        n &= 0xffffffff
        s = 0
        while (n):
            s += 1
            n -= self.lowbit(n)

        return s


