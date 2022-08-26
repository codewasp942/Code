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

const int maxn = 2e5 + 5;
const long long mod = 998244353;

int n, m, t;
vector<int> graph[maxn];
priority_queue<int, vector<int>, less<int> > q;
int cnt[maxn];
long long po[maxn], ans;

int main() {
    // freopen("number.in", "r", stdin);
    // freopen("number.out", "w", stdout);
	read(n); read(m); read(t);
	for (int i = 1; i <= m; i++) {
		int u, v; read(u); read(v);
		graph[u].push_back(v);
		cnt[v]++;
	}
	po[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) q.push(i);
		po[i] = (po[i - 1] * n) % mod;
	}
	int tot = n;
	while (!q.empty()) {
		int u = q.top(); q.pop();
		ans += 1LL * u * po[tot--] % mod;
		ans %= mod;
		for (int v : graph[u]) if (!(--cnt[v])) q.push(v);
	}
	if (tot) write(-1);
	else write(ans);
    return 0;
}