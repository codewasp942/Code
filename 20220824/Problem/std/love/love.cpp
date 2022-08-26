#include <bits/stdc++.h>
using namespace std;

#define FILE_IO
namespace io {
	#ifdef FILE_IO
	#define FREAD
	#define FWRITE
	#endif

	#ifdef FREAD
	static char ibuf[100000], *p1 = ibuf, *p2 = ibuf;
	#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
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

const int maxn = 1e3 + 5;

struct frac {
    long long a, b;
    void fix() { if (a == 0) return void(b = 1); long long d = __gcd(a, b); a /= d; b /= d; }
    frac() { a = 0, b = 1; }
    frac(long long x) { a = x, b = 1; }
    frac(long long x, long long y) { a = x, b = y; }
    frac operator *= (frac x) { a *= x.a, b *= x.b; fix(); return *this; }
    bool operator < (frac x) const { return a * x.b < x.a * b; }
};

frac operator * (frac a, frac b) { return a *= b; }

struct node {
    int v, op;
    frac x;
};

vector<node> gra[maxn];
frac graph[maxn][maxn];
int n, m;
int cnt[maxn];
frac dis[maxn];
queue<int> q;
vector<int> turn;

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    read(n); read(m);
    for (int i = 1; i <= n; i++) graph[i][i] = frac(0);
    for (int i = 1; i <= m; i++) {
        int u; node x;
        read(x.v), read(u), read(x.op);
        if (x.op) read(x.x.a), read(x.x.b);
        cnt[x.v]++;
        gra[u].push_back(x);
    }
    q.push(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        turn.push_back(u);
        for (node e : gra[u]) {
            if (e.op) graph[e.v][u] = max(graph[e.v][u], e.x);
            else for (int i = 1; i <= n; i++) if (graph[u][i].a) graph[e.v][i].a = graph[e.v][i].b = 1;
            if (!--cnt[e.v]) q.push(e.v);
        }
    }
    dis[n] = frac(1);
    for (int u : turn) for (int i = 1; i <= n; i++) if (graph[u][i].a) dis[u] = max(dis[u], dis[i] * graph[u][i]);
    if (!dis[1].a) putchar('B'), putchar('E'), putchar('\n');
    else if (dis[1].a == dis[1].b) putchar('H'), putchar('E'), putchar('\n');
    else write(dis[1].a, '/'), write(dis[1].b);
    return 0;
}