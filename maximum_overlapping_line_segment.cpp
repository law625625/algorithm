//https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e4+10;
int n;
vector<vector<int>>line(N,vector<int>(2));

int heap[N];
int cnt;

void down(int u)
{
    int t=u;
    if(2*u<=cnt&&heap[2*u]<heap[t])t=2*u;
    if(2*u+1<=cnt&&heap[2*u+1]<heap[t])t=2*u+1;
    if(u!=t)
    {
        swap(heap[u],heap[t]);
        down(t);
    }
}

void up(int u)
{
    while(u/2&&heap[u]<heap[u/2])
    {
        swap(heap[u],heap[u/2]);
        u/=2;
    }
}

void push(int x)
{
    heap[++cnt]=x;
    up(cnt);
}
void pop()
{
    swap(heap[1],heap[cnt--]);
    down(1);
}
int compute()
{
    cnt=0;
    sort(line.begin()+1,line.begin()+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int st=line[i][0],ed=line[i][1];
        while(cnt>0&&heap[1]<=st)pop();
        push(ed);
        ans=max(ans,cnt);
    }
    return ans;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>line[i][0]>>line[i][1];
    cout<<compute();
  
}
// 64 位输出请用 printf("%lld")
