#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10010;

int n;
int arr[N];
int res = 0;
int nums[10010] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};  //存火柴棍

void dfs(int x, int sum) {
    if(sum > n) return ;
    
    if(x > 3) {
        if(arr[1] + arr[2] == arr[3] && sum == n) {
            res ++;
        }
        return ;
    }
    
    for(int i = 0; i <= 1000; i ++) {
        arr[x] = i;
        dfs(x + 1, sum + nums[i]);
        arr[x] = 0;  //恢复现场
    }
}

int main() {
    cin>>n; 
    n -= 4;
    //递推出后10 ~ 1000需要用到的火柴棍
    for(int i = 10; i <= 1000; i ++) {
        nums[i] = nums[i % 10] + nums[i / 10];
    }
    dfs(1, 0);
    cout<<res<<endl;
    return 0;
}
