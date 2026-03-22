package basic_algorithm;
import java.util.Scanner;
public class quick_sort01 {
    static int []a=new int[100010];
    public static void main(String[] args) {
      Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      for(int i=1;i<=n;i++)a[i]=sc.nextInt();

      quick_sort(1,n);
      for(int i=1;i<=n;i++){
          System.out.print(a[i] + (i == n ? "" : " "));
      }
    }
    public static void  quick_sort(int l,int r)
    {
        if(l>=r)return ;
        int mid=partition(l,r);
        quick_sort(l,mid-1);
        quick_sort(mid+1,r);

    }
    public static int partition(int l,int r)
    {
        int x=a[(l+r)>>1];
        int idx=-1;
        int i=l;
        for(int j=l;j<=r;j++)
        {
            if(a[j]<=x)
            {
               int tmp=a[i];
               a[i]=a[j];
               a[j]=tmp;


               if(a[i]==x)idx=i;
               i++;
           }

        }
        int tmp=a[idx];
        a[idx]=a[i-1];
        a[i-1]=tmp;
        return i-1;
    }

}
