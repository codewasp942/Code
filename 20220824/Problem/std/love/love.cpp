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

const int maxn = 1e6 + 5;

struct frac {
    long long a, b;
    void fix() { if (a == 0) return void(b = 1); long long d = __gcd(a, b); a /= d; b /= d; }
    frac() { a = 0, b = 1; }
    frac(long long x) { a = x, b = 1; }
    frac(long long x, long long y) { a = x, b = y; }
    frac operator += (frac x) { a = a * x.b + x.a * b, b *= x.b; fix(); return *this; }
    frac operator -= (frac x) { a = a * x.b - x.a * b, b *= x.b; fix(); return *this; }
    frac operator *= (frac x) { a *= x.a, b *= x.b; fix(); return *this; }
};

frac operator + (frac a, frac b) { return a += b; }
frac operator - (frac a, frac b) { return a -= b; }
frac operator * (frac a, frac b) { return a *= b; }

struct node {
    int v, op;
    frac x;
};

vector<node> graph[maxn];
int n, m;
int cnt[maxn];
frac dis[maxn];
queue<int> q;
vector<int> turn;
bool vis[maxn];

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u; read(u);
        node x; read(x.v);
        read(x.op);
        if (x.op) read(x.x.a), read(x.x.b);
        graph[u].push_back(x);
        cnt[x.v]++;
    }
    q.push(1);
    
    for (int i = 1; i <= n; i++) if (!cnt[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        turn.push_back(u);
        for (node e : graph[u]) if (!--cnt[e.v]) q.push(e.v);
    }

    return 0;
}