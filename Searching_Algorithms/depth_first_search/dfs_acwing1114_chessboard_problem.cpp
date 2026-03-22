//https://www.acwing.com/file_system/file/content/whole/index/content/4184059/ 
#include <iostream>
using namespace std;
const int N=15;
int n,k;
int cnt=0;
char g[N][N];
bool col[N];
//遍历到了第x行，放了u颗棋子
void dfs(int x,int u)
{
    if(u==k)
    {
        cnt++;
        return ;
    }
    if(x>n)return ;
    for(int i=1;i<=n;i++)
    {
        if(!col[i]&&g[x][i]=='#')
        {
            col[i]=true;
           // cout<<x<<' '<<i<<' '<<u<<endl;
            dfs(x+1,u+1);
            col[i]=false;
            
        }
    }
    dfs(x+1,u);
}
int main()
{
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)return 0;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>g[i][j];
            }
        }
        dfs(1,0);
        cout<<cnt<<endl;
    }
}
