//https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
class Solution {
public:
    static const int N=1000001;
     double  h[N];
    int cnt=0;
    void down(int u)
    {
        int t=u;
        if(u*2<=cnt&&h[u*2]>h[t])t=u*2;
        if(u*2+1<=cnt&&h[u*2+1]>h[t])t=u*2+1;
        if(u!=t)
        {
            swap(h[u],h[t]);
            down(t);
        }
    }
    int compute(vector<int>& heap,int n)
    {
        long long  ans=0;
        double sum=0;
        double s=0;
        for(int i=1;i<=n;i++)
        {
           h[i]=heap[i-1];
            s+=h[i];
        }
         cnt=n;
        for(int i=n/2;i>=1;i--)down(i);
        double target=s/2;
        while(sum<target)
        {
            double maxv=h[1];
            double halfv=maxv/2;
            sum+=halfv;
            h[1]=halfv;
            down(1);
            ans++;
        }
        return ans;
    }
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        return compute(nums,n);
    }
};
