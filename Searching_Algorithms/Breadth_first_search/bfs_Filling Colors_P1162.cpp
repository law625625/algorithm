//https://www.luogu.com.cn/problem/P1162
#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N=450;
int n,m,sx,sy;
int st[N][N];
int g[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
PII q[N*N];
int hh,tt;
void bfs(int sx,int sy)
{
    q[0]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt)
    {
        PII t=q[hh++];
        for(int i=0;i<4;i++)
        {
            int ax=t.x+dx[i],ay=t.y+dy[i];
            if(ax<0||ax>n+1||ay<0||ay>n+1)continue;
            if(st[ax][ay]==true)continue;
            if(g[ax][ay]==1)continue;
            st[ax][ay]=true;
            q[++tt]={ax,ay};
        }
    }
}
int main()
{
    cin>>n;
    memset(st,0,sizeof st);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    bfs(0,0);
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(!st[i][j]&&g[i][j]==0)
           {
               g[i][j]=2;
           }
        }
    }
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }
    
   
}

