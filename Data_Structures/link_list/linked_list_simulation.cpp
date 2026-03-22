//https://www.luogu.com.cn/problem/B3631
#include<iostream> 
using namespace std;
const int N=1e6+10;
int n;
int e[N],ne[N],idx,head;
int pos[N];

void add_to_head(int x)
{
	e[idx]=x,ne[idx]=head,head=idx,pos[x]=idx++;
}
void add(int k,int x)
{
	e[idx]=x,ne[idx]=ne[k],ne[k]=idx,pos[x]=idx++;
}
void remove(int k)
{
	ne[k]=ne[ne[k]];
}

int main()
{
   head=-1;
   idx=1;
   add_to_head(1);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		int x,y;
		if(op==1)
		{
			
			cin>>x>>y;
			int k=pos[x];
			add(k,y);
		}
		else if(op==2)
		{
			cin>>x;
			int k=pos[x];
		    if(ne[k]==-1)cout<<0<<endl;
		    else cout<<e[ne[k]]<<endl;
		}
		else 
		{
			cin>>x;
			int k=pos[x];
			remove(k);
		}
	}
}
