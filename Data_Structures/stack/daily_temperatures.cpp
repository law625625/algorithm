//https://leetcode.cn/problems/daily-temperatures/
class Solution {
public:
   

    vector<int>monotonic_stack(vector<int>&a,int n)
    {
        vector<int>ans(n,0),r(n+10,0),stk(n+10,0);
        int tt=0;
        a.push_back(200);
        for(int i=0;i<=n;i++)
       {
        while(tt>0&&a[stk[tt]]<=a[i])
           r[stk[tt--]]=i;
        stk[++tt]=i;
       }
         for(int i=n-1;i>=0;i--)
	    if(a[i]==a[r[i]])r[i]=r[r[i]];
       for(int i=0;i<n;i++)
       {
        if (r[i] >n-1) ans[i] = 0;
        else ans[i]=r[i]-i;
       }
       return ans;

       
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        return monotonic_stack(temperatures,n);
    }
};
