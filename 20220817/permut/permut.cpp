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

const int mod = 1e4, maxn = 1e3 + 5;

int t;
int dp[maxn][maxn], sdp[maxn][maxn];

int main() {
	freopen("permut.in", "r", stdin);
	freopen("permut.out", "w", stdout);
	dp[1][0] = 1;
	for (int i = 2; i <= 1000; i++) {
		sdp[i - 1][0] = dp[i - 1][0];
		for (int j = 1; j <= 1000; j++) sdp[i - 1][j] = (sdp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		for (int j = 0; j <= min(i * (i - 1) / 2, 1000); j++) {
			if (j - i + 1 <= 0) dp[i][j] = sdp[i - 1][j];
			else dp[i][j] = (sdp[i - 1][j] + mod - sdp[i - 1][j - i]) % mod;
		}
	}
	read(t);
	while (t--) {
		int n, k;
		read(n); read(k);
		write(dp[n][k]);
	}
	return 0;
}

