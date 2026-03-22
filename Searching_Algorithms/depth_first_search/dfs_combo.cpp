#include<iostream>
#include<iomanip>
using namespace std;
const int N=30;
int a[N];
int n,m;
//当前枚举到了第x个位置,从start开始 

void dfs(int x,int start)
{
	if(x>m)
	{
		for(int i=1;i<=m;i++)
			cout<<setw(3)<<a[i];
		cout<<endl;	
		return ;
	}
	for(int i=start;i<=n;i++)
	{
		a[x]=i;
		dfs(x+1,i+1);
		a[x]=0;
		
	}
}
int main()
{
	cin>>n>>m;
	dfs(1,1);
}
