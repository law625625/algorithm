#include <iostream>
#include <random>

using namespace std;
const int N=1e5+10;
int a[N];

int n;


void quick_sort(int l,int r)
{
	if(l>=r)return ;
	int mid=a[l+r>>1],i=l-1,j=r+1;
	while(i<j)
	{
		do i++;while(a[i]<mid);
		do j--;while(a[j]>mid);
		if(i<j) swap(a[i],a[j]);
	}
	quick_sort(l,j),quick_sort(j+1,r);
 } 
int main()
{
	
 	cin>>n;//scanf("%lld",&n)
 	for(int i=1;i<=n;i++)cin>>a[i];
 	quick_sort(1,n);
 	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
 
 //	quick_sort()
} 
