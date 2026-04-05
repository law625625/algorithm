//https://www.luogu.com.cn/problem/P2895
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 310;
const int INF = 0x3f3f3f3f;

PII q[N * N];
int dist[N][N];
int fire[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int bfs() {
    // 特判起点：如果起点在 0 时刻就已经着火，直接返回 -1
    if (fire[0][0] <= 0) return -1;

    memset(dist, -1, sizeof dist); // 使用 -1 表示未访问
    q[0] = {0, 0};
    dist[0][0] = 0;
    
    int hh = 0, tt = 0;

    while (hh <= tt) {
        PII t = q[hh++];

        // 如果起点本身就是安全的（从未着火）
        if (fire[t.x][t.y] > 1e9) return dist[t.x][t.y];

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];

            // 边界检查：根据题目习惯，坐标通常不能为负
            if (a < 0 || b < 0) continue;
            // 避免重复访问
            if (dist[a][b] != -1) continue;
            // 核心判断：下一秒到达该点时，火是否已经烧到那里
            if (dist[t.x][t.y] + 1 >= fire[a][b]) continue;

            dist[a][b] = dist[t.x][t.y] + 1;
            q[++tt] = {a, b};

            // 终点判断：如果该点永远不会着火
            if (fire[a][b] > 1e9) return dist[a][b];
        }
    }
    return -1;
}

int main() {
    int m;
    cin>>m;
    
    memset(fire, 0x3f, sizeof fire);
    
    while (m--) {
        int x1, y1, t;
        cin>>x1>>y1>>t;
        // 更新中心点
        fire[x1][y1] = min(fire[x1][y1], t);
        // 更新四周受波及的点
        for (int i = 0; i < 4; i++) {
            int a = x1 + dx[i], b = y1 + dy[i];
            if (a >= 0 && b >= 0) { // 限制在第一象限或题目要求范围
                fire[a][b] = min(fire[a][b], t);
            }
        }
    }

    cout<<bfs();
    
    return 0;
}
