package basic_algorithm;

import java.util.Scanner;

public class quick_sort {
    // 模拟 C++ 的全局数组，N = 1e5 + 10
    static int[] a = new int[100010];

    public static void main() {
        Scanner sc = new Scanner(System.in);

        // 读取输入
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        // 开始快排
        quickSort(1, n);

        // 输出结果
        for (int i = 1; i <= n; i++) {
            System.out.print(a[i] + (i == n ? "" : " "));
        }
    }

    // 对应你的 partition 逻辑：单向扫描法 (Lomuto Partition)
    public static int partition(int l, int r) {
        int x = a[(l + r) >> 1]; // 选中间值作为基准
        int idx = -1;
        int i = l;

        for (int j = l; j <= r; j++) {
            if (a[j] <= x) {
                // 交换 a[i] 和 a[j]
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                // 记录基准值最后一次交换到的位置
                if (a[i] == x) idx = i;
                i++;
            }
        }

        // 将基准值换到它最终该在的位置 (i-1)
        int temp = a[idx];
        a[idx] = a[i - 1];
        a[i - 1] = temp;

        return i - 1;
    }

    public static void quickSort(int l, int r) {
        if (l >= r) return;

        int mid = partition(l, r);

        // 递归处理左右两部分
        quickSort(l, mid - 1);
        quickSort(mid + 1, r);
        
    }
}