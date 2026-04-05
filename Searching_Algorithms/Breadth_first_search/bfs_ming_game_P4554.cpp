//https://www.luogu.com.cn/problem/P4554
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>


#define x first
#define y second

using namespace std;

const int N = 510;
typedef pair<int, int> PII;

int n, m;
char g[N][N];
int x1, y1, x2, y2;
deque<PII> q;
int dist[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs(int sx, int sy) {
    q.push_back({sx, sy});
    dist[sx][sy] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop_front();
        
        // 记录当前格子的字符，用于判断移动代价
        char ch = g[t.x][t.y];

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];

            // 越界检查
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            // 如果已经访问过且找到更短路径则跳过
            if (dist[a][b] >= 0) continue;

            if (g[a][b] == ch) {
                // 相同类型，边权为 0，放入队头
                dist[a][b] = dist[t.x][t.y];
                q.push_front({a, b});
            } else {
                // 不同类型，边权为 1，放入队尾
                dist[a][b] = dist[t.x][t.y] + 1;
                q.push_back({a, b});
            }

            // 搜到目标点直接返回
            if (a == x2 && b == y2) return dist[x2][y2];
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        
        memset(dist, -1, sizeof dist);
        q.clear();
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 特判：起点终点重合
        if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
            continue;
        }

        cout << bfs(x1, y1) << endl;
    }
    return 0;
}
