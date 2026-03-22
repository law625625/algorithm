package basic_algorithm;
import java.util.Scanner;
public class mergesort {

    private static final int N=100010;
    private static int[] a=new int[N];
    private static int[] tmp=new int[N];
    public static void merge_sort(int l,int r)
    {
        if(l>=r)return;
        int mid=(l+r)>>1;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        int k=1,i=l,j=mid+1;
        while(i<=mid&&j<=r) {
            if (a[i] <= a[j]) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
            while(i<=mid)tmp[k++]=a[i++];
            while(j<=r)tmp[k++]=a[j++];
            for(int c=l,b=1;c<=r;c++,b++)a[c]=tmp[b];
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)a[i]=sc.nextInt();

        merge_sort(1,n);
        for(int i=1;i<=n;i++)
            System.out.print(a[i] + (i == n ? "" : " "));
    }

}
