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

struct node {
    long long x, y;
    vector<int> a, b;
    int end;
};

int n, b;
node a[maxn];
long long maxs;

void dfs(node &p, long long x, int t, bool flag) {
    long long v = 1LL << t;
    if (!flag) p.a.push_back(t);
    else p.b.push_back(t);
    if (v == x) {
        p.end = t;
        return;
    }
    else dfs(p, abs(v - x), t > 0 ? t - 1 : 0, flag ^ (v > x));
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i].x); read(a[i].y);
        maxs = max(maxs, a[i].x + a[i].y);
    }
    while (maxs) b++, maxs >>= 1;
    b--;
    for (int i = 1; i <= n; i++) {
        dfs(a[i], a[i].x + a[i].y, b, false);
        
    }
    return 0;
}