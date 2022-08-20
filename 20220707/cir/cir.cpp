#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 5;

struct node {
	int u, v;
	node(int _u, int _v) {
		u = _u, v = _v;
	}
};

int r, c;
vector<node> g0[maxn][maxn], g1[maxn][maxn];
deque<node> dq;
char s[maxn];
int dis[maxn][maxn];

int main() {
	freopen("cir.in", "r", stdin);
	freopen("cir.out", "w", stdout);
	int _;
	scanf("%d", &_);
	while (_--) {
		scanf("%d %d", &r, &c);
		memset(dis, -1, sizeof dis);
		dq.clear();
		for (int i = 1; i <= r + 1; i++) {
			for (int j = 1; j <= c + 1; j++) {
				g0[i][j].clear();
				g1[i][j].clear();
			}
		}
		for (int i = 1; i <= r; i++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= c; j++) {
				if (s[j] == '\\') {
					g0[i][j].emplace_back(i + 1, j + 1);
					g0[i + 1][j + 1].emplace_back(i, j);
					g1[i][j + 1].emplace_back(i + 1, j);
					g1[i + 1][j].emplace_back(i, j + 1);
				}
				else {
					g1[i][j].emplace_back(i + 1, j + 1);
					g1[i + 1][j + 1].emplace_back(i, j);
					g0[i][j + 1].emplace_back(i + 1, j);
					g0[i + 1][j].emplace_back(i, j + 1);
				}
			}
		}
		dq.emplace_back(1, 1);
		dis[1][1] = 0;
		while (!dq.empty()) {
			auto u = dq.front(); dq.pop_front();
			for (auto v : g0[u.u][u.v]) {
				if (dis[v.u][v.v] == -1) {
					dis[v.u][v.v] = dis[u.u][u.v];
					dq.push_front(v);
				}
			}
			for (auto v : g1[u.u][u.v]) {
				if (dis[v.u][v.v] == -1) {
					dis[v.u][v.v] = dis[u.u][u.v] + 1;
					dq.push_back(v);
				}
			}
		}
		printf("%d\n", dis[r + 1][c + 1]);
	}
	return 0;
}
