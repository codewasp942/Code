#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
	r = 0; char c = getchar(); bool f = false;
	while (c < 48 || c > 57) { if (c == 45) f ^= 1; c = getchar(); }
	while (c >= 48 && c <= 57) { r = (r << 1) + (r << 3) + c - 48; c = getchar();}
	if (f) r = -r;
}

const int maxn = 5e5 + 5, maxm = 2e6 + 5;

int n, m;
vector<int> tree[maxn];
int uu[maxn], vv[maxn], s[maxm], t[maxm], w[maxm], in[maxn], out[maxn], cnt;
int book[maxm], tbook[maxm];

void dfs(int u, int f) {
	in[u] = ++cnt;
	for (int v : tree[u]) {
		if (v == f) continue;
		dfs(v, u);
	}
	out[u] = ++cnt;
}

inline bool is_son(int u, int v) {
	return (in[u] <= in[v]) && (out[u] >= out[v]);
}

int main() {
	freopen("T3.in", "r", stdin);
	freopen("T3.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i < n; i++) {
		read(uu[i]); read(vv[i]);
		tree[uu[i]].push_back(vv[i]);
		tree[vv[i]].push_back(uu[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(s[i]); read(t[i]); read(w[i]);
		book[w[i]]++;
	}
	dfs(1, 1);
	for (int i = 1; i < n; i++) {
		memset(tbook, 0, sizeof tbook);
		int ans = 1, u = uu[i], v = vv[i];
		if (is_son(v, u)) swap(u, v);
//		printf("Edge #%d: %d -> %d\n", i, u, v);
		for (int j = 1; j <= m; j++) {
//			printf("Path #%d: %d ->...-> %d\n", j, s[j], t[j]);
//			printf("%d %s %d's father.", v, is_son(v, s[j]) ? "is" : "isn't", s[j]);
//			printf("%d %s %d's father.\n", v, is_son(v, t[j]) ? "is" : "isn't", t[j]);
			if (is_son(v, s[j]) ^ is_son(v, t[j])) tbook[w[j]]++;
		}
//		putchar('\n');
		while (book[ans] > tbook[ans]) ans++;
		printf("%d\n", ans);
//		putchar('\n');
	}
	return 0;
}
