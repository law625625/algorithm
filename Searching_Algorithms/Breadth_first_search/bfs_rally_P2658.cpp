// https://www.luogu.com.cn/problem/P2658
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 505;

int m, n;
int high[N][N];
int flag[N][N];
int cnt_flag = 0;
int sx, sy;
PII q[N * N];
int st[N][N]; // 改用 int 避免 memset
int vis_tag = 0; // 访问标记计数器

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool check(int mid) {
    vis_tag++; // 每次 check 只需要增加标记，不需要清空数组
    int hh = 0, tt = 0;
    
    q[0] = {sx, sy};
    st[sx][sy] = vis_tag;
    int cnt = 1; // 起点本身就是路标

    while (hh <= tt) {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];

            // 边界检查
            if (a < 1 || a > m || b < 1 || b > n) continue;
            // 访问检查
            if (st[a][b] == vis_tag) continue;
            // 高度差检查
            int diff = high[t.first][t.second] - high[a][b];
            if (diff < 0) diff = -diff; // 手写 abs 往往更快
            if (diff > mid) continue;

            st[a][b] = vis_tag;
            if (flag[a][b]) cnt++;
            
            // 剪枝：如果已经找齐了所有路标，提前退出
            if (cnt == cnt_flag) return true;
            
            q[++tt] = {a, b};
        }
    }
    return cnt >= cnt_flag;
}

int main() {
    // 加速 IO
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> m >> n)) return 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> high[i][j];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> flag[i][j];
            if (flag[i][j] == 1) {
                cnt_flag++;
                sx = i, sy = j;
            }
        }
    }

    // 特判路标数量
    if (cnt_flag <= 1) {
        cout << 0 << endl;
        return 0;
    }

    int l = 0, r = 1e9+10;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;

    return 0;
}
