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

const int maxn = 1e6 + 5;

int n, x, p;
int s[maxn << 2];
long long ans;

int main() {
    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);
    read(n); read(x); read(p);
	for (int i = 1; i <= n; i++) {
		int t; read(t);
		t = (t - 1) % (x + p) + 1;
		s[t]++;
		s[t + x + p]++;
	}
	int cnt_in = 0;
	long long sum = 0;
	for (int i = 1; i <= x + p; i++) {
		if (i <= x) cnt_in += s[i];
		else sum += 1LL * s[i] * (x + p - i + 1);
	}
	ans = sum;
	for (int i = 2; i <= x + p; i++) {
		cnt_in += s[i + x - 1];
		cnt_in -= s[i - 1];
		sum -= 1LL * s[i + x - 1] * p;
		sum += n - cnt_in;
		ans = min(ans, sum);
	}
	write(ans);
	return 0;
}