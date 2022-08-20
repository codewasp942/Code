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

const int maxn = 3e5 + 5;

struct node {
	int x, c;
};

node a[maxn], b[maxn];
int n, cnt[maxn];
long long ans;

void merge_sort(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	for (int i = l; i <= mid; i++) b[i] = a[i], cnt[b[i].c]++;
	for (int i = mid + 1; i <= r; i++) b[i] = a[i];
	int i = l, j = mid + 1, pos = l;
	while (i <= mid && j <= r) {
		if (b[i].x > b[j].x) {
			a[pos++] = b[j];
			ans += (mid - i + 1) - cnt[b[j++].c];
		}
		else {
			a[pos++] = b[i];
			cnt[b[i++].c]--;
		}
	}
	while (i <= mid) a[pos++] = b[i], cnt[b[i++].c]--;
	while (j <= r) a[pos++] = b[j++];
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].c);
	}
	for (int i = 1; i <= n; i++) {
		read(a[i].x);
	}
	merge_sort(1, n);
	write(ans);
	return 0;
}

