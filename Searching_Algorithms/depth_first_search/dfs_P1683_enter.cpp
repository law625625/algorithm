//https://www.luogu.com.cn/problem/P1683
#include <iostream>
//引入IO流
using namespace std;
//使用命名空间
const int N=30;//设定一个为30的常量
char g[N][N];
bool st[N][N];//state
//为真代表我们走过了，为假代表我们还没走 
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int n,m;
int res=1;
//瓷砖的个数 
void dfs(int x,int y)
{
	//当前走到了（x,y)这个位置
	for(int i=0;i<4;i++)
	{
		int a=x+dx[i],b=y+dy[i];
		if(a<1||a>n||b<1||b>m)continue;
		if(g[a][b]!='.')continue;
		if(st[a][b])continue;
		st[a][b]=true;
		res++;
		dfs(a,b);
	//	cout<<a<<' '<<b<<endl;
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>g[i][j];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]=='@')
			{
			   // cout<<i<<' '<<j<<endl;
				st[i][j]=true;
				dfs(i,j);
			}
		}
	}
	cout<<res;
}
