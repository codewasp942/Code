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

const int maxn = 1e5 + 5;

int n, max1, max2;
int book1[maxn], book2[maxn];

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		if (i & 1) book1[x]++;
		else book2[x]++;
	}
	for (int i = 1; i <= 1e5; i++) {
		if (book1[i] > book1[max1]) max1 = i;
		if (book2[i] > book2[max2]) max2 = i;
	}
	if (max1 == max2) {
		int maxx1 = 0, maxx2 = 0;
		for (int i = 1; i <= 1e5; i++) {
			if (book1[i] > book1[maxx1] && i != max1) maxx1 = i;
			if (book2[i] > book2[maxx2] && i != max2) maxx2 = i;
		}
		if (book1[max1] - book1[maxx1] < book2[max2] - book2[maxx2]) write(n - book1[maxx1] - book2[max2]);
		else write(n - book1[max1] - book2[maxx2]);
	}
	else write(n - book1[max1] - book2[max2]);
    return 0;
}