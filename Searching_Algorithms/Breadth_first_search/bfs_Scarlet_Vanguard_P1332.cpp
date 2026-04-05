//https://www.luogu.com.cn/problem/P1332
#include<iostream>
#include <cstring>
#include<vector>
#define x first
#define y second
using namespace std;
const int N=510;
typedef pair<int,int>PII;
PII q[N*N];
int dist[N][N];
int g[N][N];
int n,m,a,b;
int hh,tt=-1;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
void bfs()
{
    while(hh<=tt)
    {
        PII t=q[hh++];
        for(int i=0;i<4;i++)
        {
            int ax=t.x+dx[i],ay=t.y+dy[i];
            if(ax<1||ax>n||ay<1||ay>m)continue;
            if(dist[ax][ay]!=-1)continue;
            q[++tt]={ax,ay};
            dist[ax][ay]=dist[t.x][t.y]+1;
        }
        
    }
}

int main()
{
    cin>>n>>m>>a>>b;
    memset(dist,-1,sizeof dist);
    for(int i=1;i<=a;i++)
    {
       int ax,ay;
       cin>>ax>>ay;
       q[++tt]={ax,ay};
       dist[ax][ay]=0;
    }
    bfs();
    for(int i=1;i<=b;i++)
    {
        int sx,sy;
        cin>>sx>>sy;
        cout<<dist[sx][sy]<<endl;
    }
}
