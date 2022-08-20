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

const int maxn = 2e3 + 5;

int a[maxn], ans[maxn];

struct node;
typedef node* pos;

pos new_node(int l, int r);

struct node {
	int l, r, val;
	pos ls, rs;
	void push_up() { val = max(ls -> val, rs -> val); }
	void build() {
		if (l == r) {
			val = ans[l];
			return;
		}
		int mid = (l + r) >> 1;
		ls = new_node(l, mid); ls -> build();
		rs = new_node(mid + 1, r); rs -> build();
		push_up();
	}
	int ask(int ql, int qr) {
		if (ql <= l && r <= qr) return val;
		int mid = (l + r) >> 1, res = 0;
		if (mid >= ql) res = max(res, ls -> ask(ql, qr));
		if (mid + 1 <= qr) res = max(res, rs -> ask(ql, qr));
		return res;
	}
};

node buf[maxn * 2];
pos root, buf_pos = buf;

pos new_node(int l, int r) {
	pos p = ++buf_pos;
	p -> ls = p -> rs = buf;
	p -> l = l, p -> r = r;
	return p;
}

int n, q;
int sum[maxn], fst[maxn * 2], lst[maxn * 2];

int main() {
	freopen("beautiful.in", "r", stdin);
	freopen("beautiful.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		memset(sum, 0, sizeof sum);
		memset(fst, -1, sizeof fst);
		memset(lst, -1, sizeof lst);
		fst[0 + maxn] = lst[0 + maxn] = 0;
		for (int j = 1; j <= n; j++) {
			if (j < i) {
				if (a[j] > a[i]) sum[j] = sum[j - 1] + 1;
				else sum[j] = sum[j - 1] - 1;
			}
			else if (j > i) {
				if (a[j] >= a[i]) sum[j] = sum[j - 1] + 1;
				else sum[j] = sum[j - 1] - 1;
			}
			else sum[j] = sum[j - 1];
			if (fst[sum[j] + maxn] == -1) fst[sum[j] + maxn] = j;
			lst[sum[j] + maxn] = j;
		}
		for (int j = 0; j < maxn * 2; j++) if (fst[j] < i && lst[j] >= i) ans[i] = max(ans[i], lst[j] - fst[j]);
	}
	root = new_node(1, n);
	root -> build();
	read(q);
	while (q--) {
		int l, r;
		read(l); read(r);
		write(root -> ask(l, r));
	}
	return 0;
}

