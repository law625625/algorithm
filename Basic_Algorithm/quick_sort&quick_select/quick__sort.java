package basic_algorithm;
import java.util.Scanner;
public class quick__sort {
    static int[] a=new int [100010];
    public static void quick_sort(int l,int r)
    {
        if(l>=r)return ;
        int mid=a[l+r>>1];
        int i=l-1,j=r+1;
        while(i<j)
        {
            do i++;while(a[i]<mid);
            do j--;while(a[j]>mid);
            if(i<j)
            {
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
        quick_sort(l,j);
        quick_sort(j+1,r);
    }
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       int n=sc.nextInt();
       for(int i=1;i<=n;i++)a[i]=sc.nextInt();
       quick_sort(1,n);
       for(int i=1;i<=n;i++){
           System.out.print(a[i] + (i == n ? "" : " "));
       }
    }

}
