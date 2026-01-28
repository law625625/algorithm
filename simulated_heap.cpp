//https://www.luogu.com.cn/problem/P3378
#include<iostream>
using namespace std;
const int N=1e6+10;
int n,m;
int h[N],cnt;
void down(int u)
{
    int t=u;
    if(u*2<=cnt&&h[u*2]<=h[t])t=u*2;
    if(u*2+1<=cnt&&h[u*2+1]<=h[t])t=u*2+1;
    if(u!=t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}
void up(int x)
{
    while(x>1&&h[x]<h[x/2])
    {
        swap(h[x],h[x/2]);
        x/=2;
    }
}
int main()
{

    cin>>m;
    while(m--)
    {
        int op,x;
        cin>>op;
      
        if(op==1)
        {
            cin>>x;
            h[++cnt]=x;
            up(cnt);
        }
        else if(op==2)
        {
            cout<<h[1]<<endl;
        }
        else
        {
            h[1]=h[cnt];
            cnt--;
            down(1);
        }
    }
}
 

