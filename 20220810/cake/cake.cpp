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
		char write_buf[55], *pos = write_buf;
		if (w == 0) { putchar(48); putchar(end); return; }
		if (w < 0) { putchar(45); w = -w; }
		while (w) {
			*(pos++) = w % 10 + '0';
			w /= 10;
		}
		while (pos != write_buf) putchar(*(--pos));
		putchar(end);
	}
};
using namespace io;

const int maxn = 5e3 + 5;

int t, n, m, x, y;

int main() {
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	read(t);
	while (t--) {
		read(n), read(m);
		read(x), read(y);
		int ans = (x + 1) * (y + 1), cntx = 0, cnty = 0;
		for (int i = 1; i <= x; i++) {
			int tmp; read(tmp);
			if (tmp >= -m && tmp <= m) cntx++;
		}
		for (int i = 1; i <= y; i++) {
			int tmp; read(tmp);
			if (tmp >= -m && tmp <= m) cnty++;
		}
		if (cntx + cnty != 0) ans -= (cntx - 1) * (cnty - 1);
		write(ans);
	}
	return 0;
}

