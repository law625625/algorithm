//https://www.luogu.com.cn/problem/B3616
#include <iostream>
using namespace std;
const int N=1e6+10;
int q[N];
int n;
int hh;
int tt=-1;

int main()
{
    
    cin>>n;
    while(n--)
    {
          int op;
          cin>>op;
          if(op==1)
          {
              int x;
              cin>>x;
              q[++tt]=x;
          }
          else if(op==2)
          {
              if(hh<=tt) hh++;
              else puts("ERR_CANNOT_POP");
          }
          else if(op==3)
          {
              if(hh<=tt)cout<<q[hh]<<endl;
              else puts("ERR_CANNOT_QUERY");
          }
          else 
          {
              cout<<tt-hh+1<<endl;
          }
     //     cout<<q[hh]<<' '<<hh<<' '<<tt<<endl;
    }
}
