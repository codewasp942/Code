#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 5;
const int d[3][4][3] = {
	{{-1, 0, 1}, {0, 1, 2}, {2, 0, 1}, {0, -2, 2}},
	{{-2, 0, 0}, {0, 1, 1}, {1, 0, 0}, {0, -1, 1}},
	{{-1, 0, 2}, {0, 2, 0}, {1, 0, 2}, {0, -1, 0}}
};

int n, m, x00, y00, xx, yy;
bool mp[maxn][maxn], vis[maxn][maxn][3]; // 0立1上2右

struct node {
	int x, y, op, cnt;
	node(int _x, int _y, int _op, int _cnt) {
		x = _x, y = _y, op = _op, cnt = _cnt;
	}
};

queue<node> q;

bool check(node x) {
	if (x.x < 1 || x.x > n || x.y < 1 || x.y > m) return false;
	if (vis[x.x][x.y][x.op]) return false;
	if (!mp[x.x][x.y]) return false;
	if (!x.op) return true;
	if (x.op == 1) {
		if (x.x - 1 < 1 || x.x - 1 > n || x.y < 1 || x.y > m) return false;
		if (!mp[x.x - 1][x.y]) return false;
		return true;
	}
	else {
		if (x.x < 1 || x.x > n || x.y + 1 < 1 || x.y + 1 > m) return false;
		if (!mp[x.x][x.y + 1]) return false;
		return true;
	}
}

int main() {
	freopen("bloxorz.in", "r", stdin);
	freopen("bloxorz.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; scanf("%d", &x);
			mp[i][j] = bool(x);
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (!mp[i][j] && mp[i - 1][j] && mp[i][j - 1] && mp[i - 1][j - 1] && mp[i - 1][j + 1] && mp[i][j + 1] && mp[i + 1][j + 1] && mp[i + 1][j] && mp[i + 1][j - 1]) { 
				xx = i, yy = j;
				mp[i][j] = true;
				goto nxt;
			}
		}
	}
nxt:
	//cerr << xx << ' ' << yy << endl;
	scanf("%d %d", &x00, &y00);
	q.push(node(x00, y00, 0, 0));
	vis[x00][y00][0] = true;
	while (!q.empty()) {
		node u = q.front(); q.pop();
		//cerr << u.x << ' ' << u.y << ' ' << u.op << ' ' << u.cnt << endl;
		for (int i = 0; i < 4; i++) {
			node v(u.x + d[u.op][i][0], u.y + d[u.op][i][1], d[u.op][i][2], u.cnt + 1);
			if (v.x == xx && v.y == yy && v.op == 0) {
				printf("%d\n", v.cnt);
				return 0;
			}
			if (check(v)) {
				q.push(v);
				vis[v.x][v.y][v.op] = true;
			}
		}
		//sleep(1);
	}
	printf("-1\n");
	return 0;
}
