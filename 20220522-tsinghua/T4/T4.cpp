#include <bits/stdc++.h>
using namespace std;

char ch;

template <class T> 
void read(T &r) {
        r = 0; ch = getchar(); bool f = false;
        while (ch < 48 || ch > 57) { if (ch == 45) f ^= 1; ch = getchar(); }
        while (ch >= 48 && ch <= 57) { r = r * 10 + ch - 48; ch = getchar(); }
        if (f) r = -r;
}

const int maxn = 1010;

double n;
vector<int> graph[maxn];
double pr[maxn], tpr[maxn];
const double d = 0.9, ex = 0.000001;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; read(x);
			if (x) graph[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		pr[i] = 1.0 / n;
	}
	while (true) {
		for (int u = 1; u <= n; u++) {
			double l = graph[u].size();
			for (int v : graph[u]) {
				tpr[v] += pr[u] / l * d;	
			}
			tpr[u] += (1 - d) / n;
		}
		bool flag = true;
		for (int u = 1; u <= n; u++) {
			if (abs(pr[u] - tpr[u]) >= ex) flag = false;
			pr[u] = tpr[u];
			tpr[u] = 0;
			//printf("%.6lf\n", pr[u]);
		}
		//putchar('\n');
		if (flag) break;
	}
	for (int i = 1; i <= n; i++) {
		printf("%.6lf\n", pr[i]);
	}
	return 0;
}
