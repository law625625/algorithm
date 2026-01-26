#include <iostream>
using namespace std;
const int N=1e6+10;
int a[N];
int tmp[N];
int n;
void merge_sort(int l,int r)
{
	if(l>=r)return ; 
	int mid=l+r>>1;
	merge_sort(l,mid),merge_sort(mid+1,r);
	int k=1,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])tmp[k++]=a[i++];
		else tmp[k++]=a[j++];
	}
	while(i<=mid)tmp[k++]=a[i++];
	while(j<=r)tmp[k++]=a[j++];
	//a l-r,tmp 1-x
	for(int i=l,j=1;i<=r;i++,j++)a[i]=tmp[j]; 
}
int main()
{
	
 	cin>>n;//scanf("%lld",&n)
 	for(int i=1;i<=n;i++)cin>>a[i];
 	merge_sort(1,n);
 	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
 
 //	quick_sort()
}
