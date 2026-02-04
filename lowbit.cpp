#include <iostream>
using namespace std;
int x;
int lowbit(int x)
{
	return x&(~x+1);
}
int main()
{
	cin>>x;
	int ans=0;
	while(x)
	{
		x-=lowbit(x);
		ans+=1;
	}
	cout<<ans;
	
}
