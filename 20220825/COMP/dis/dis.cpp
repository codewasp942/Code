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

const long long mod = 998244353;

long long sum(long long x) {
	if (x < 0) return 0;
	return (x * (x + 1) / 2) % mod;
}

long long ssum(long long x) {
	if (x < 0) return 0;
	return (x * (x + 1) * (2 * x + 1) / 6) % mod;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
	// for (long long c = 1; c <= 1000; c++) {
	// 	long long ans = 0;
	// 	for (long long i = 1;i <= 10000; i++) {
	// 		ans += i * (i / c);
	// 		ans %= mod;
	// 		if (ans != (c * ssum(i / c - 1) * c + sum(c - 1) * sum(i / c - 1) + c * (i / c) * (i / c) * (i % c + 1) + (i / c) * sum(i % c)) % mod) {
	// 			write(i); write(c);
	// 			write(ans, ' ');
	// 			write((c * ssum(i / c - 1) + sum(c - 1) * sum(i / c - 1) + (i / c) * (i / c) * (i % c + 1) + (i / c) * sum(i % c)) % mod);
	// 			return 0;
	// 		}
	// 	}
	// }
	long long c, ans = 0;
	read(c);
	for (long long i = 1; i <= 50; i++) {
		// ans += i * (i % c);
		write(i * (i % c));
		// write(ans);
		// write(c * ssum(i / c - 1) * c + sum(c - 1) * sum(i / c - 1) + c * (i / c) * (i / c) * (i % c + 1) + (i / c) * sum(i % c));
		s=i^2,d=i*c 
		4 + 2c + 4c
		9
		16
		25
	}
    return 0;
}