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

const int maxn = 2e2 + 5, maxm = 2e3 + 5;

struct node {
	int v, step, w;
	node(int _v, int _w, int _step) {
		v = _v, w = _w, step = _step;
	}
	bool operator < (const node& x) const {
		return step != x.step ? step < x.step : w < x.w;
	}
};

int dis[maxn][maxm];
priority_queue<node> q;
int n, m;
vector<pair<int, int> > graph[maxn];
double ans;

int main() {
	freopen("calabash.in", "r", stdin);
	freopen("calabash.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		int u, v, w; 
		read(u); read(v); read(w);
		graph[u].emplace_back(v, w);
	}
	memset(dis, 0x3f, sizeof dis);
	dis[1][0] = 0;
	q.emplace(1, 0, 0);
	while (!q.empty()) {
		node u = q.top(); q.pop();
		for (pair<int, int> v : graph[u.v]) {
			if (dis[v.first][u.step + 1] == 0x3f3f3f3f) {
				dis[v.first][u.step + 1] = dis[u.v][u.step] + v.second;
				q.emplace(v.first, v.second, u.step + 1);
			}
		}
	}
	ans = 1e7;
	for (int i = 1; i <= m; i++) {
		ans = min(ans, double(dis[n][i]) / double(i + 1));
	}
	printf("%.3lf\n", ans);
	return 0;
}

