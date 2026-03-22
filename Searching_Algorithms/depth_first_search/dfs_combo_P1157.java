package basic_algorithm;
import java.util.*;
import java.io.PrintWriter;
public class dfs_combo_P1157 {
    static int n,m;
    static int []path=new int [25];
    static PrintWriter out=new PrintWriter(System.out);
    public static void dfs(int x,int start)
    {
        //x是填到了第几个位置，start当前位置从start开始
        if(x>m)
        {
            for(int i=1;i<=m;i++)
            {
                out.printf("%3d",path[i]);
            }
            out.println();
            return ;
        }
        for(int i=start;i<=n;i++)
        {
            path[x]=i;
            dfs(x+1,i+1);
            path[x]=0;
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        dfs(1,1);
        out.flush();
    }
}
