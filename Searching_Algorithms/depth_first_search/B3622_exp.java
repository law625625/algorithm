package basic_algorithm;
import java.util.Scanner;
public class B3622_exp {
      static int n;
      static int []st=new int [25];
      //等于0代表还没做选择，等于1代表我选这个数字，等于2代表我不选这个数字
      //当前枚举到了第x个位置
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
          st[x]=1;
          dfs(x+1);
          st[x]=0;

          st[x]=2;
          dfs(x+1);
          st[x]=0;

      }
      public  static void main(String[]args)
      {
          Scanner sc=new Scanner(System.in);
          n=sc.nextInt();
          dfs(1);
          sc.close();
      }
}
