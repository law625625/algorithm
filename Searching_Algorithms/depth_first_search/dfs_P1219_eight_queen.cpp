//https://www.luogu.com.cn/problem/P1219 
#include <iostream>
using namespace std;
const int N=20;
char g[N][N];
bool col[N],dg[N],udg[N];
int path[N];//每一行放的皇后的列编号
int cnt=0;
int n;
//当前遍历到第u行
void dfs(int u)
{
    if(u>n)
    {
        //第一个，只要输出前3个解
        //怎么统计所有的答案数量
        cnt++;
        if(cnt<=3)
        {
            for(int i=1;i<=n;i++)
            {
                cout<<path[i]<<' ';
            }
            cout<<endl;
        }
        return ;
    }
    //遍历每一列
   //当前遍历到了第u行第i列
    for(int i=1;i<=n;i++)
    {
        if(!col[i]&&!dg[u-i+n]&&!udg[u+i])
        {
            col[i]=dg[u-i+n]=udg[u+i]=true;
             path[u]=i;
             dfs(u+1);
             col[i]=dg[u-i+n]=udg[u+i]=false;
             path[u]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<cnt;
    
}
