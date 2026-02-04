//https://www.luogu.com.cn/problem/P2249
#include <iostream>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int compute(int x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(a[mid]>=x)r=mid;
		else l=mid+1;
	}
	if(a[l]!=x)return -1;
	return l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(m--)
	{
		int x;
		cin>>x;
		cout<<compute(x)<<' ';
	}
}

