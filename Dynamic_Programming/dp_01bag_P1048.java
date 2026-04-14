package basic_algorithm;
import java.util.*;
public class dp_01bag_P1048 {
    static int n,m;
    static int []v=new int [10001];
    static int []w=new int [10001];
    static int [][]mem=new int [1010][1010];
    static int [][]f=new int [1010][1010];
    static int res=0;
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        m=sc.nextInt();
        n=sc.nextInt();

        for(int i=1;i<=n;i++)
        {
            v[i]=sc.nextInt();
            w[i]=sc.nextInt();

        }
        for(int i=0;i<=1009;i++)
        {
            for(int j=0;j<=1008;j++)
            {
                mem[i][j]=-1;
                f[i][j]=0;
            }
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<=m;j++)
            {
                f[i][j]=f[i+1][j];
                if(j>=v[i])f[i][j]=Math.max(f[i][j],f[i+1][j-v[i]]+w[i]);
            }
        }
        System.out.println(f[1][m]);
    }
    public static int dfs1(int x,int spv)
    {
        if(mem[x][spv]!=-1)return mem[x][spv];
        if(x>n)return 0;
        int sum=0;
        if(spv<v[x])sum= dfs1(x+1,spv);
        else sum=Math.max(dfs1(x+1,spv),dfs1(x+1,spv-v[x])+w[x]);
        mem[x][spv]=sum;
        return mem[x][spv];
    }
    public static int dfs2(int x,int spv)
    {
        if(x>n)return 0;
        if(spv<v[x])return dfs2(x+1,spv);
        return Math.max(dfs2(x+1,spv),dfs2(x+1,spv-v[x])+w[x]);
    }
//    //f[i][j]是代表选第i个物品到最后，然后体积不超过v的物品的价值
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=0;j<=m;j++)
//             {
//                 f[i][j]=f[i-1][j];
//                 if(j>=v[i])f[i][j]=Math.max(f[i][j],f[i-1][j-v[i]]+w[i]);
//             }
//         }
//         System.out.println(f[n][m]);
//     }
//     public static int dfs1(int x,int spv)
//     {
//             if(mem[x][spv]!=-1)return mem[x][spv];
//             if(x<1)return 0;
//             int sum=0;
//             if(spv<v[x])sum= dfs1(x-1,spv);
//             else sum=Math.max(dfs1(x-1,spv),dfs1(x-1,spv-v[x])+w[x]);
//             mem[x][spv]=sum;
//             return mem[x][spv];
//     }
//     //从第x个物品开始，然后还剩spv个体积
//        public static int dfs2(int x,int spv)
//     {
//             if(x<1)return 0;
//             if(spv<v[x])return dfs2(x-1,spv);
//             return Math.max(dfs2(x-1,spv),dfs2(x-1,spv-v[x])+w[x]);
//     }

}
