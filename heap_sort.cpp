//https://www.luogu.com.cn/problem/P1177 
#include <iostream>
using namespace std;
int n,cnt;
const int N=1e6+10;
int h[N];
void down(int u)
{
	int t=u;
	if(2*u<=cnt&&h[2*u]<=h[t])t=2*u;
	if(2*u+1<=cnt&&h[2*u+1]<=h[t])t=2*u+1;
	if(t!=u)
	{
		swap(h[u],h[t]);
		down(t);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	cnt=n;
	for(int i=n/2;i;i--)down(i);
	while(n--)
	{
		cout<<h[1]<<' ';
		h[1]=h[cnt];
		cnt--;
		down(1);
	}
}
