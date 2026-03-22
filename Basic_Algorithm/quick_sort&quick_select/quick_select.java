package basic_algorithm;


class Solution {


    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        // 注意：第 k 大等价于升序排序后的第 n-k+1 小
        return quickSelect(nums, 0, n - 1, n - k + 1);
    }
    public void swap(int []a,int i,int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    public int quickSelect(int[] a, int l, int r, int k) {
        if (l >= r) return a[r];

        // 随机选择基准值 (Pivot) 以防止最坏情况 O(n^2)
        int x = a[l+r>>1];
        int i = l - 1, j = r + 1;

        // 双指针分区 (Hoare partition scheme)
        while (i < j) {
            do i++; while (a[i] < x);
            do j--; while (a[j] > x);
            if (i < j) {
                swap(a,i,j);
            }
        }

        // 确定第 k 小元素在哪个区间
        int leftLength = j - l + 1;
        if (leftLength >= k) {
            return quickSelect(a, l, j, k);
        } else {
            return quickSelect(a, j + 1, r, k - leftLength);
        }
    }
}
