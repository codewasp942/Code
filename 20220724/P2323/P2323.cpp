#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5, maxm = 2e4 + 5;

namespace io {
    #ifdef FILE_IO
    #define FREAD
    #define FWRITE
    #endif

    #ifdef FREAD
    static char buf[1e5], *p1 = buf, *p2 = buf;
    #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1e5, stdin), p1 == p2) ? EOF : *p1++)
    #endif
    
    #ifdef FWRITE
    static char obuf[1e5], *p3 = obuf;
    #define putchar(x) ((p3 - obuf < 1e5) ? (*p3++ = (x)) : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = (x)))
    struct flasher { ~flasher() { fwrite(obuf, p3 - obuf, 1, stdout); } }flash;
    #endif
    //读入失败返回true
    template <class T> bool read(T &r) {
        r = 0; static char ch = getchar(); static bool f = false;
        while (ch < 48 || ch > 57) { if (ch == EOF) return true; if (ch == 45) f ^= 1; ch = getchar(); }
        while (ch >= 48 && ch <= 57) { r = (r << 1) + (r << 3) + ch - 48; ch = getchar(); }
        if (f) r = -r; return false;
    }
    template <class T> void write(T w, char end = '\n') {
        static char write_buf[55], *pos = write_buf;
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
using io::read;
using io::write;

#define FILE_IO
// or ...
// #define FREAD
// #define FWRITE

struct node {
	int u, v, w, id;
};

node a[maxm], b[maxm];
int n, k, m, anss = INT_MIN;
int fa[maxn];
vector<pair<int, int> > ans;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool compare(node a, node b) {
	return a.w < b.w;
}

int main() {
	read(n); read(k); read(m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i < m; i++) {
		int u, v, c1, c2;
		read(u); read(v); read(c1); read(c2);
		a[i].u = u, a[i].v = v, a[i].w = c1, a[i].id = i;
		b[i].u = u, b[i].v = v, b[i].w = c2, b[i].id = i;
	}
	sort(a + 1, a + m, compare);
	sort(b + 1, b + m, compare);
	int cnt = 0;
	for (int i = 1; i < m; i++) {
		int u = find(a[i].u), v = find(a[i].v);
		if (u != v) {
			anss = max(anss, a[i].w);
			fa[v] = u;
			ans.emplace_back(a[i].id, 1);
			if (++cnt == k) break;
		}
	}
	for (int i = 1; i < m; i++) {
		int u = find(b[i].u), v = find(b[i].v);
		if (u != v) {
			fa[v] = u;
			anss = max(anss, b[i].w);
			ans.emplace_back(b[i].id, 2);
			if (++cnt == n - 1) break;
		}
	}
	sort(ans.begin(), ans.end());
	write(anss);
 	for (auto x : ans) {
		write(x.first, ' ');
		write(x.second);
	}
	return 0;
}
