#include <iostream>
using namespace std;
const int N=1e6+10;
int n;
int a[N];
int first,last;

void partition(int l,int r,int x)
{
	first=l,last=r;
	int i=l;
	while(i<=last)
	{
		if(a[i]<x)swap(a[i++],a[first++]);
		else if(a[i]>x)swap(a[i],a[last--]);
		else i++;
	}
}

void quick_sort(int l,int r)
{
	if(l>=r)return ;
	int x=a[l+r>>1];
	partition(l,r,x);
	int left=first;
	int right=last;
	quick_sort(l,left-1);
	quick_sort(right+1,r); 
	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	quick_sort(1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
 } 
