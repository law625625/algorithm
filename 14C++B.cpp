//https://www.lanqiao.cn/problems/3510/learning/
#include <iostream>
using namespace std;
int n;
int get(int a,int b)
{
  int l=1,r=1e9+10;
  while(l<r)
  {
    int mid=l+r>>1;
    if(a/mid<=b)r=mid;
    else l=mid+1;
  }
  return r;
}
int main()
{
  cin>>n;
  int v_min=1,v_max=1e9;
  while(n--)
  {
      int a,b;
      cin>>a>>b;
      //get返回的是符合当前a,b的最大值
      v_min=max(v_min,get(a,b));
      //getget返回是符合a,b-1的最大值
      v_max=min(v_max,get(a,b-1)-1);
  }
  cout<<v_min<<' '<<v_max<<endl;
  return 0;
}
