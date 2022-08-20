#include <bits/stdc++.h>
using namespace std;

#define FILE_IO
namespace io {
	#ifdef FILE_IO
	#define FREAD
	#define FWRITE
	#endif

	#ifdef FREAD
	static char buf[100000], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
	#endif
	
	#ifdef FWRITE
	static char obuf[100000], *p3 = obuf;
	#define putchar(x) ((p3 - obuf < 100000) ? (*p3++ = (x)) : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = (x)))
	struct flasher { ~flasher() { fwrite(obuf, p3 - obuf, 1, stdout); } }flash;
	#endif
	
	//读入失败返回true
	template <class T> bool read(T &r) {
		r = 0; char ch = getchar(); bool f = false;
		while (ch < 48 || ch > 57) { if (ch == EOF) return true; if (ch == 45) f ^= 1; ch = getchar(); }
		while (ch >= 48 && ch <= 57) { r = r * 10 + ch - 48; ch = getchar(); }
		if (f) r = -r; return false;
	}
	template <class T> void write(T w, char end = '\n') {
		static char write_buf[55];
		char *pos = write_buf;
		if (w == 0) { putchar('0'); putchar(end); return; }
		if (w < 0) { putchar('-'); w = -w; }
		while (w) {
			*(pos++) = w % 10 + '0';
			w /= 10;
		}
		while (pos != write_buf) putchar(*(--pos));
		putchar(end);
	}
};
using namespace io;

const int maxn = 1e5 + 5;

int n, m;
vector<int> graph[maxn], ans;
int dfn[maxn], dfn_cnt, low[maxn];
bool cut[maxn];

void tarjan(int u, int f) {
	low[u] = dfn[u] = ++dfn_cnt;
	int cnt = 0;
	for (int v : graph[u]) {
		if (v == f) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			cnt++;
			if (f == 0 && cnt >= 2) cut[u] = true;
			if (f != 0 && low[v] >= dfn[u]) cut[u] = true;
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		int u, v; read(u); read(v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	tarjan(1, 0);
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			write(1);
			write(i);
			return 0;
		}
		if (!cut[i] && m - graph[i].size() == n - 2) ans.push_back(i);
	}
	write(ans.size());
	for (int x : ans) write(x, " \n"[x == ans.back()]);
	return 0;
}

