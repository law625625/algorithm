//https://leetcode.cn/problems/sum-of-subarray-minimums/ 
class Solution {
public:
    static const int mod=1e9+7;
    int monotonic_stack(vector<int >&a,int n)
    {
        int tt=0;
        long long ans=0;
        vector<int >stk(n+10,0),l(n+10,0),r(n+10,0);
        a.push_back(-2);
        for(int i=0;i<=n;i++)
        {
            while(tt>0&&a[stk[tt]]>=a[i])
            {
                 
                 if(tt>1)l[stk[tt]]=stk[tt-1];
                 else l[stk[tt]]=-1;
                 r[stk[tt]]=i;
                   int cur=stk[tt];
                   long long left=cur-l[cur],right=i-cur,sum=left*right*a[cur];
                   ans+=sum%mod;
                   ans%=mod;
                   tt--;
            }
            stk[++tt]=i;
        }
      

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        return monotonic_stack(arr,n);
    }
};
