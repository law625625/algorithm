//https://www.luogu.com.cn/problem/P2089 
#include <iostream>
using namespace std;
const int N=20;
const int M=6e4+10;
int n;
int a[N];
int res=0;
int ans[M][N];
//x表示当前枚举到了哪一位，sum表示当前已经选了调料的总质量
void dfs(int x,int sum)
{
    if(sum>n)return ;
    if(x>10)
    {
        if(sum==n)
        {
            res++;
            for(int i=1;i<=10;i++)ans[res][i]=a[i];
           
        }
         return ;
    }
    for(int i=1;i<=3;i++)
    {
        a[x]=i;
        dfs(x+1,sum+i);
        a[x]=0;
    }
}
int main()
{
    cin>>n;
    dfs(1,0);
    cout<<res<<endl;
    for(int i=1;i<=res;i++)
    {
       for(int j=1;j<=10;j++)
          cout<<ans[i][j]<<' ';
       cout<<endl;
    }
}
