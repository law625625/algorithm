//https://www.luogu.com.cn/problem/P1443
#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N=450;
int n,m,sx,sy;
int dist[N][N];
int dx[]={-1,-2,-1,-2,1,2,1,2};
int dy[]={2,1,-2,-1,2,1,-2,-1};
PII q[N*N];
int hh,tt;
void bfs()
{
    while(hh<=tt)
    {
        PII t=q[hh++];
        for(int i=0;i<8;i++)
        {
            int ax=t.x+dx[i],ay=t.y+dy[i];
            if(ax<1||ax>n||ay<1||ay>m)continue;
            if(dist[ax][ay]!=-1)continue;
            dist[ax][ay]=dist[t.x][t.y]+1;
            q[++tt]={ax,ay};
        }
    }
}
int main()
{
    cin>>n>>m>>sx>>sy;
    memset(dist,-1,sizeof dist);
    dist[sx][sy]=0;
     q[0]={sx,sy};
    bfs();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dist[i][j]<<' ';
        }
        cout<<endl;
    }
    
}

