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

const int n[13] = {10, 15, 50, 100, 100, 100, 500, 800, 800, 1000, 1000, 1000, 1000};
const int m[13] = {50, 75, 500, 1000, 1000, 2000, 10000, 50000, 50000, 100000, 100000, 200000, 200000};
const int bro[13] = {20, 30, 100, 0, 200, 200, 500, 10000, 20000, 200000, 300000, 400000, 500000};
const int maxb = 1e6 + 0;

char name[50];

int main() {
	random_device seed;
	mt19937_64 rd(seed());
    for (int i = 0; i < 13; i++) {
		sprintf(name, "%s%d.in", i < 3 ? "sample" : "data", i < 3 ? i : i - 3);
		freopen(name, "w", stdout);
		write(n[i], ' ');
		write(m[i]);
		for (int j = 1; j <= bro[i]; j++) {
			int u = rd() % n[i] + 1, v = rd() % n[i] + 1;
			while (u == v) v = rd() % n[i] + 1;
			write(u, ' '); write(v, ' '); write(0);
		}
		for (int j = 1; j <= m[i] - bro[i]; j++) {
			int u = rd() % n[i] + 1, v = rd() % n[i] + 1;
			while (u == v) v = rd() % n[i] + 1;
			int b = rd() % maxb + 1, a = rd() % (b - 1) + 1;
			write(u, ' '); write(v, ' '); write(1, ' ');
			write(a, ' '); write(b, ' ');
		}
		fclose(stdout);
	}
    return 0;
}