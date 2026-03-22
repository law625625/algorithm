package basic_algorithm;
import java.util.Scanner;
import java.io.PrintWriter;
public class dfs_permutation_1706 {
    static int n;
    static int []a=new int[25];
    static boolean[] st=new boolean[25];
    static PrintWriter out=new PrintWriter(System.out);
    //枚举到了第x个位置
    public static void dfs(int x)
    {
        if(x>n)
        {
            for(int i=1;i<=n;i++)
            {
                out.printf("%5d",a[i]);
            }
            out.println();
            return ;
        }

        for(int i=1;i<=n;i++)
        {
            if(!st[i])
            {
                st[i]=true;
                a[x]=i;
                dfs(x+1);
                st[i]=false;
                a[x]=0;
            }
        }
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        dfs(1);
        out.flush();
        out.close();
        sc.close();
    }


    //state
}
