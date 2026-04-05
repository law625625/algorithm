#https://www.luogu.com.cn/problem/P1746
#include <iostream>
#include<algorithm>
#include<cstring>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N=1010;
char g[N][N];
bool st[N][N];
int dist[N][N];
int sx,sy,zx,zy;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
PII q[N*N];
int n;
int hh,tt;
void bfs()
{
    dist[sx][sy]=0;
    q[0]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt)
    {
    PII t=q[hh++];
    int ax=t.first,ay=t.second;
    for(int i=0;i<4;i++)
    {
       
        int bx=ax+dx[i],by=ay+dy[i];
      //  cout<<axx<<' '<<ayy<<' '<<bx<<' '<<by<<endl;
     //   if(bx==3&&by==2)cout<<"YES";
        if(bx<1||bx>n||by<1||by>n)continue;
        if(st[bx][by])continue;
        if(g[bx][by]=='1')continue;
        q[++tt]={bx,by};
        dist[bx][by]=dist[ax][ay]+1;
        st[bx][by]=true;
       
    }
    }
}
int main()
{
    cin>>n;
    memset(dist,-1,sizeof dist);
    memset(st,0,sizeof st);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    
    cin>>sx>>sy>>zx>>zy;
    
    bfs();
  
    cout<<dist[zx][zy];
}
