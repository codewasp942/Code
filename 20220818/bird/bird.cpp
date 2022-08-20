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

const int maxn = 4e1 + 5, maxm = 1e2 + 5, maxp = 8e2 + 5;

struct node {
	int wait, tp, tim, bel, turns;
	bool operator < (const node &x) const {
		return tim < x.tim;
	}
};

node bird[maxp];
int t[maxn][maxm];
int ti[maxm];
int n, m, cnt;
long long ans;

int main() {
	freopen("bird.in", "r", stdin);
	freopen("bird.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		int p; read(p);
		while (p--) {
			cnt++;
			bird[cnt].tp = i;
			bird[cnt].wait = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(t[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= cnt; j++) bird[j].tim = t[bird[j].tp][i];
		stable_sort(bird + 1, bird + cnt + 1);
		int tmp = 0;
		for (int j = 1; j <= cnt; j++) {
			if (bird[j].tim + ti[i] < bird[j].wait) {
				for (int k = 1; k <= cnt; k++)
					if (bird[j].bel == bird[k].bel && bird[j].turns < bird[k].turns)
						bird[k].wait -= t[bird[j].tp][bird[j].bel];
				ti[bird[j].bel] -= t[bird[j].tp][bird[j].bel];
				bird[j].bel = i;
				bird[j].wait = bird[j].tim + ti[i];
				ti[i] += bird[j].tim;
				bird[j].turns = ++tmp;
			}
		}
	}
	for (int i = 1; i <= cnt; i++) ans += bird[i].wait;
	write(ans);
	return 0;
}

