//www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
#include<iostream>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],tmp[N];
int n;
int merge(int l,int mid,int r)
{
	 int ans=0,sum=0;
	 int i=l,j=mid+1;
	 while(j<=r)
	 {
	    while(i<=mid&&a[i]<=a[j])	sum+=a[i++];
		ans+=sum;
		j++;
	 }
	 i=l,j=mid+1;
     int k=1;
	 while(i<=mid&&j<=r)
	 {
	 	if(a[i]<=a[j])tmp[k++]=a[i++];
	 	else tmp[k++]=a[j++];
	 }
     while(i<=mid)tmp[k++]=a[i++];
     while(j<=r)tmp[k++]=a[j++];
     for(int i=1,j=l;j<=r;j++,i++)a[j]=tmp[i];
     return ans;
	
}

int smallsum(int l,int r)
{
	if(l>=r)return 0;
	int mid=l+r>>1;
	return smallsum(l,mid)+smallsum(mid+1,r)+merge(l,mid,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<smallsum(1,n); 
}
