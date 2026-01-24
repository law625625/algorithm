// https://leetcode.cn/problems/xx4gT2/

class Solution {
public:
  
  
    int quick_select(vector<int>&a,int l,int r,int k)
    {
       if(l>=r)return a[r];
       int x=a[l+rand()%(r-l+1)],i=l-1,j=r+1;
       while(i<j)
       {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
       }
       if(j-l+1>=k)return quick_select(a,l,j,k);
       else return quick_select(a,j+1,r,k-(j-l+1));
    }

    
    int findKthLargest(vector<int>& nums, int k) {
       int n=nums.size();
       return quick_select(nums,0,n-1,n-k+1);

    }

};
