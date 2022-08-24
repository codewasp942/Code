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

const int maxn = 5e4 + 5;

struct node;
typedef node* pos;

struct node {
	int l, r, val;
	pos ls, rs;
};

vector<int> tree[maxn];
int dfn[maxn], dfn_cnt, son[maxn], siz[maxn], dep[maxn];
int n, m;

void dfs1(int u, int d) {
	dep[u] = d; siz[u] = 1;
	for (int v : tree[u]) {
		dfs1(v, d + 1);
		siz[u] += siz[v];
	}
}

void dfs2

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
	read(n); read(m);
	for (int i = 0; i < n; i++) {
		int u; read(u);
		tree[i].push_back(u);
	}

    return 0;
}