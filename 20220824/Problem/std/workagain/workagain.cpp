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

const int maxn = 1e2 + 5;

double dp[maxn][maxn], v[maxn], tmp[maxn];
int n, m;
int t[maxn], w[maxn];

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		read(t[i]);
		t[i] += t[i - 1];
	}
	for (int i = 1; i <= n; i++) scanf("%lf", v + i);
	for (int i = 1; i <= n; i++) read(w[i]);
	for (int i = 1; i <= m; i++) dp[0][i] = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= min(j, w[i]); k++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + v[i] * double(t[j] - t[j - k]));
			}
			// printf("%.2lf%c", dp[i][j], " \n"[j == m]);
		}
	}
	printf("%.2lf\n", dp[n][m]);
    return 0;
}