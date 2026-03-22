//https://www.luogu.com.cn/problem/P5788
#include<iostream>
using namespace std;
const int N=3e6+10;
int n;
int stk[N],a[N],tt;
int l[N],r[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[n + 1] = 0x3f3f3f3f;
    for(int i=1;i<=n+1;i++)
    {
            while(tt>0&&a[stk[tt]]<=a[i])
            {
                //此时要把下标为stk[tt]弹出去，结算stk[tt]的答案
                //右边就是a[i],左边是stk[tt-1]
                if(tt>1)l[stk[tt]]=stk[tt-1];
                else l[stk[tt]]=-1;
                r[stk[tt]]=i;
                tt--;
            }
            stk[++tt]=i;
    }
   
   for(int i=n;i>=1;i--) if(a[i]==a[r[i]])r[i]=r[r[i]];
    for(int i=1;i<=n;i++)
    {
        if(r[i]==-1||r[i]>n)cout<<0<<' ';
        else cout<<r[i]<<' ';
    }
}
