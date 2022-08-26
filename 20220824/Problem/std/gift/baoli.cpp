#include <bits/stdc++.h>
using namespace std;

// #define FILE_IO
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

int fa[maxn], cnt[maxn];

int n, m;
vector<int> s;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    read(n); read(m);
    s.emplace_back(INT_MIN);
    s.emplace_back(INT_MAX);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i] = 1;
        s.emplace_back(1);
    }
    for (int i = 1; i <= m; i++) {
        int op;
        read(op);
        if (op == 1) {
            int u, v; read(u); read(v);
            u = find(u);
            v = find(v);
            if (u != v) {
                s.erase(lower_bound(s.begin(), s.end(), cnt[u]));
                s.erase(lower_bound(s.begin(), s.end(), cnt[v]));
                fa[v] = u;
                cnt[u] += cnt[v];
                s.insert(lower_bound(s.begin(), s.end(), cnt[u]), cnt[u]);
            }
        }
        else {
            int k; read(k);
            write(s[s.size() - k - 1]);
        }
    }
    return 0;
}