package basic_algorithm;

import java.util.Scanner;

public class quick_sort02 {
    // 算法竞赛习惯：开一个比题目范围稍大一点的静态数组
    static int[] a = new int[100010];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 读入 n
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();

        // 读入数组（保持你 C++ 中从 1 开始存储的习惯）
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        // 调用快排
        quickSort(1, n);

        // 输出结果
        for (int i = 1; i <= n; i++) {
            System.out.print(a[i] + (i == n ? "" : " "));
        }
    }

    public static void quickSort(int l, int r) {
        // 递归出口
        if (l >= r) return;

        // 选取基准值 mid
        // 注意：如果你递归使用的是 (l, i-1) 和 (i, r)，这里必须上取整，防止死循环
        int mid = a[l + r + 1 >> 1];
        int i = l - 1, j = r + 1;

        while (i < j) {
            do i++; while (a[i] < mid);
            do j--; while (a[j] > mid);
            if (i < j) {
                // Java 交换两个数需要手动写 temp
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // 递归处理两边
        quickSort(l, i - 1);
        quickSort(i, r);
    }
}