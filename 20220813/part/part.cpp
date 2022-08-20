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

const int maxn = 1e3 + 5, d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, ans;
bool graph[maxn][maxn];

void dfs(int x, int y) {
	graph[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + d[i][0], ty = y + d[i][1];
		if (tx < 1 || tx > n || ty < 1 || ty > n || graph[tx][ty]) continue;
		dfs(tx, ty);
	}
}

int main() {
	freopen("part.in", "r", stdin);
	freopen("part.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			read(graph[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!graph[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	write(ans);
	return 0;
}

