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

const int maxn = 5e5 + 5;

int n;
int a[maxn];
long long sum;

bool next(int s, int t) {
	int i = t;
	while (true) {
		int i1, i2;
		i1 = i;
		if (a[--i] < a[i1]) {
			i2 = t;
			while (a[i] > a[--i2]);
			swap(a[i], a[i2]); sum++;
			reverse(a + i1, a + t);
			sum -= 1LL * (t - i1) * (t - i1 - 1) / 2;
			return true;
		}
		if (i == s) return false;
	}
}


int main() {
	freopen("music.in", "r", stdin);
	freopen("music.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	while (next(1, n + 1)) if (sum == 0) break;
	for (int i = 1; i <= n; i++) write(a[i], " \n"[i == n]);
	return 0;
}

