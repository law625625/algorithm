package basic_algorithm;
import java.io.*;
import java.util.*;
public class revese {
    static long []a;
    static long []tmp;

    public static void main(String[] args) throws IOException {
         Reader in = new Reader(System.in);
         int    n=in.nextInt();

         a=new long [n+1];
         tmp=new long [n+1];
         for (int i=1;i<=n;i++)
         {
             a[i]= in.nextLong();
         }
        System.out.println(revese(1,n));

    }
    static long revese(int l,int r)
    {
        if (l>=r)return 0;
        int mid=(l+r)/2;
        return revese(l,mid)+revese(mid+1,r)+merge(l,r,mid);
    }
    static long merge(int l,int r,int mid)
    {
        long  sum=0,ans=0;
        int i=l,j=mid+1;
        while(i<=mid)
        {
            while (j<=r&&a[i]>a[j])
            {
                j++;
                sum++;
            }
            i++;
            ans+=sum;
        }
        i=l;
        j=mid+1;
        int k=1;
        while(i<=mid&&j<=r)
        {
            if(a[i]<a[j])tmp[k++]=a[i++];
            else tmp[k++]=a[j++];
        }
        while(i<=mid)tmp[k++]=a[i++];
        while(j<=r)tmp[k++]=a[j++];

        for(int p=l,q=1;p<=r;q++,p++)a[p]=tmp[q];
        return ans;
    }
    static class Reader{
        BufferedReader reader;
        StringTokenizer tokenizer;

        Reader(InputStream input)
        {
            reader = new BufferedReader(new InputStreamReader(input));
            tokenizer=new StringTokenizer("");
        }
        String next() throws IOException
        {
            while(!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }
        int nextInt() throws IOException
        {
            return Integer.parseInt(next());
        }
        long nextLong()throws IOException{
            return Long.parseLong(next());
        }



    }
}

