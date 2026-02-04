#经典快排的朴素版本
#https://www.luogu.com.cn/problem/P1177
#会TLE
#include <iostream>
#include <random>

using namespace std;
const int N=1e5+10;
int a[N];

int n;

int partition(int l,int r,int x)
{
	int idx=0;
	int i=l;
	for(int j=l;j<=r;j++)
	{
		if(a[j]<=x)
		{
			swap(a[i],a[j]);
			if(a[i]==x)idx=i;
			i++; 
		}
		
	 } 
	 swap(a[idx],a[i-1]);
	 return i-1;
	 
}
void quick_sort(int l,int r)
{
	if(l>=r)return ;
    int x=a[l+r>>1];
    int mid=partition(l,r,x);
    quick_sort(l,mid-1),quick_sort(mid+1,r);
		
}
int main()
{
	
 	cin>>n;//scanf("%lld",&n)
 	for(int i=1;i<=n;i++)cin>>a[i];
 	quick_sort(1,n);
 	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
 
 //	quick_sort()
} 


