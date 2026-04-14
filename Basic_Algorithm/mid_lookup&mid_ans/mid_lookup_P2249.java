import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] a = new int[1000005];

    // 二分查找：找到第一个大于等于 x 的数的下标
    public static int compute(int x) {
        int l = 1, r = n;
        while (l < r) {
            // 在 Java 中，使用 l + (r - l) / 2 可以防止 l+r 溢出
            int mid = (l + r) >> 1;
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        // 检查找到的数字是否等于目标值
        if (a[l] != x) return -1;
        return l;
    }

    public static void main(String[] args) throws IOException {
        // 使用快速输入
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 使用快速输出
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // 读取数组
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        // 读取查询并执行
        st = new StringTokenizer(br.readLine());
        while (m-- > 0) {
            int x = Integer.parseInt(st.nextToken());
            out.print(compute(x) + " ");
        }

        // 刷新缓冲区并关闭
        out.flush();
        out.close();
    }
}