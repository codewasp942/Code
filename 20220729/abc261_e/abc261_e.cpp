#include <bits/stdc++.h>
using namespace std;

namespace io {
    template <class T> bool read(T &r) {
        r = 0; static char ch = getchar(); static bool f = false;
        while (ch < 48 || ch > 57) { if (ch == EOF) return true; if (ch == 45) f ^= 1; ch = getchar(); }
        while (ch >= 48 && ch <= 57) { r = (r << 1) + (r << 3) + ch - 48; ch = getchar(); }
        if (f) r = -r; return false;
    }
    template <class T> void write(T w, char end = '\n') {
        static char write_buf[55], *pos = write_buf;
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
using io::read;
using io::write;

const int maxn = 2e5 + 5;

struct node {
	bitset<32> val;
	char t;
};

node a[maxn];
bool ans[maxn][2];
int n, c;
bitset<32> res[maxn];

int main() {
	read(n); read(c); 
	res[0] = bitset<32>(c);
	for (int i = 1; i <= n; i++) {
		read(a[i].t); int x; read(x);
		a[i].val = bitset<32>(x);
	}
	for (int i = 0; i < 32; i++) {
		ans[0][0] = 0; ans[0][1] = 1;
		for (int j = 1; j <= n; j++) {
			ans[j][0] = ans[j - 1][0];
			ans[j][1] = ans[j - 1][1];
			if (a[j].t == 1) {
				ans[j][0] &= a[j].val[i];
				ans[j][1] &= a[j].val[i];
			}
			else if (a[j].t == 2) {
				ans[j][0] |= a[j].val[i];
				ans[j][1] |= a[j].val[i];
			}
			else {
				ans[j][0] ^= a[j].val[i];
				ans[j][1] ^= a[j].val[i];
			}
			res[j][i] = ans[j][res[j - 1][i]];
		}
	}
	for (int i = 1; i <= n; i++) {
		write(res[i].to_ulong());
	}
	return 0;
}

