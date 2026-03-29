#https://www.luogu.com.cn/problem/P5788
import sys

def solve():
    input_data=sys.stdin.read().split()
    n=int(input_data[0])
    #下标从1开始，多一个1。要放置哨兵，多一个1
    a=[0]*(n+2)
    for i in range(1,n+1):
        a[i]=int(input_data[i])
    a[n+1]=float('inf')#哨兵
    r=[0]*(n+1)
    stk=[]
    for i in range(1,n+2):
        while stk and a[stk[-1]]<a[i]:
            top_idx=stk.pop()
            r[top_idx]=i
        stk.append(i)

    output=[]
    for i in range(1,n+1):
        if r[i]>n:
            output.append("0")
        else:
            output.append(str(r[i]))

    sys.stdout.write(" ".join(output))
if __name__ == '__main__':
    solve()