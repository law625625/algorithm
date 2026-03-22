//https://leetcode.cn/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> monotonic_queue(vector<int>& a,int k,int n)
    {
        vector<int>ans,q(n+10,0);
        int hh=0,tt=-1;
        for(int i=0;i<n;i++)
        {
            // 窗口范围是 [i - k + 1, i]，如果队头下标小于左边界，则出队
            if(hh<=tt&&q[hh]<i-k+1)hh++;
            while(hh<=tt&&a[q[tt]]<=a[i])tt--;
            q[++tt]=i;
            if(i>=k-1)ans.push_back(a[q[hh]]);
        }
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        return monotonic_queue(nums,k,n);
    }
};
