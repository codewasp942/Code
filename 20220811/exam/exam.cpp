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

const int maxn = 5e2 + 5;
const long long mod = 1e9 + 7;

int n, k;
long long dp[maxn][maxn][2]; //0不参与，1参与
long long s[maxn];

int main() {
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
	read(n); read(k);
	s[1] = 1;
	for (int i = 2; i <= n; i++) s[i] = (i * s[i - 1]) % mod;
	dp[0][0][1] = 1;
	dp[1][0][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int ls = 0; ls <= (i - 1) / 2; ls++) {
				int rs = i - 1 - ls;
				for (int lsk = 0; lsk <= (ls == rs ? j / 2 : j); lsk++) {
					int rsk = j - lsk;
					dp[i][j][0] += dp[ls][lsk][1] * dp[rs][rsk][1];
					dp[i][j][0] %= mod;
				}
			}
			for (int ls = 0; ls <= i - 2; ls++) {
				int rs = i - 1 - ls;
				for (int lsk = 0; lsk <= j - 1; lsk++) {
					int rsk = j - 1 - lsk;
					dp[i][j][1] += (dp[ls][lsk][1] + dp[ls][lsk][0]) * dp[rs][rsk][0];
					dp[i][j][1] %= mod;
				}
			}
		}
	}
	write((dp[n][k][0] + dp[n][k][1]) * s[n - 1] % mod);
	return 0;
}

