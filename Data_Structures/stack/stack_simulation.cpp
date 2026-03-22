//https://www.luogu.com.cn/problem/B3614
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
const int N=1e6+10;
ULL stk[N];
int T;

int main()
{
    cin>>T;
   while(T--)
   {
       int n;
     cin>>n;
   	int tt=0;
   	while(n--)
   	{
   		string op;
   		cin>>op;
   		if(op=="push")
   		{
   			ULL x;
   			cin>>x;
   			stk[++tt]=x;
		   }
		   else if(op=="pop")
		   {
		   	   if(tt>0)tt--;
		       else puts("Empty");
		   }
		   else if(op=="query")
		   {
		   	if(tt>0)cout<<stk[tt]<<endl;
		   	else puts("Anguei!");
		   }
		   else cout<<tt<<endl;
   		
	   }
   }
   
}
