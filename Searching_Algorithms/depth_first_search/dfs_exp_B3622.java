package basic_algorithm;
import java.util.Scanner;
public class dfs_exp_B3622 {
    static int n;
    static int []st=new int [25];
    //0代表还没选择，1代表已选择，2代表已选择
    public static void dfs(int x)
    {
        if(x>n)
        {
            StringBuilder sb=new StringBuilder();
            for(int i=1;i<=n;i++)
            {
                if(st[i]==1)sb.append("Y");
                else sb.append("N");
            }
            System.out.println(sb.toString());
            return ;
        }
        st[x]=2;
        dfs(x+1) ;
        st[x]=0;

        st[x]=1;
        dfs(x+1);
        st[x]=0;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        dfs(1);
        sc.close();

    }
}


