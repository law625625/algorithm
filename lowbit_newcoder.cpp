//https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&ru=/exam/oj

class Solution {
public:
    int lowbit(int n)
    {
        return n&(~n+1);
    }
    int NumberOf1(int n) {
       int s=0;
       while(n)
       {
        s+=1;
        n-=lowbit(n);
       }
       return s;
    }
};
