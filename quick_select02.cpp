//https://leetcode.cn/problems/xx4gT2/
class Solution {
public:
   int first ,last;
    void partition(vector<int>&a,int l,int r,int x)
    {
        first=l,last=r;
        int i=l;
        while(i<=last)
        {
            if(a[i]==x)i++;
            else if(a[i]<x)swap(a[first++],a[i++]);
            else swap(a[i],a[last--]);
        }

    }
    int quick_select(vector<int>&a,int l,int r,int k)
    {
        if(l>=r)return a[l];
        int x=a[l+rand()%(r-l+1)];
        partition(a,l,r,x);
        int left_size=first-l;
        int mid_size=last-first+1;
        if(k<=left_size)return quick_select(a,l,first-1,k);
        else if(k<=left_size+mid_size)return x;
        else return quick_select(a,last+1,r,k-(left_size+mid_size));

    }

    
    int findKthLargest(vector<int>& nums, int k) {
       int n=nums.size();
       return quick_select(nums,0,n-1,n-k+1);

    }

};
