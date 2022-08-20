#include <bits/stdc++.h>
using namespace std;

char ch;

template <class T> 
void read(T &r) {
        r = 0; ch = getchar(); bool f = false;
        while (ch < 48 || ch > 57) { if (ch == 45) f ^= 1; ch = getchar(); }
        while (ch >= 48 && ch <= 57) { r = (r << 1) + (r << 3) + ch - 48; ch = getchar(); }
        if (f) r = -r;
}

void read_s(string &s) {
	s = ""; ch = getchar(); 
	while ((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z') && (ch < '0' || ch > '9')) ch = getchar();
	while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) { s += ch; ch = getchar(); } 
	//cerr << endl;
}

#define double long double

const int maxn = 1010;
vector<string> passage[maxn], query;
map<string, int> cnt[maxn], tot, qcnt;
int id, n, m;
const double k1 = 1.2, k3 = 2.0, b = 0.75;
double lave = 0.0;

inline double f1(string q) {
	double df = tot[q];
	return log((n - df + 0.5) / (df + 0.5));
}

inline double f2(string q) {
	double ld = passage[id].size(), tftd = cnt[id][q];
	return (k1 + 1) * tftd / (k1 * (1 - b + b * ld / lave) + tftd);
}

inline double f3(string q) {
	double tftq = qcnt[q];
	return (k3 + 1) * tftq / (k3 + tftq);
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		string x; read_s(x); passage[i].push_back(x); 
		if (!(cnt[i][x]++)) tot[x]++;
		while (ch != '\n' && ch != '\r') {
			read_s(x);
			passage[i].push_back(x);
			if (!(cnt[i][x]++)) tot[x]++;
		}
		lave += passage[i].size();
	}
	lave /= (double)n;
	for (int i = 1; i <= m; i++) {
		read(id);
		query.clear(); qcnt.clear();
		string x; read_s(x); query.push_back(x); qcnt[x]++;
		while (ch != '\n' && ch != '\r') {
			read_s(x);
			query.push_back(x);
			qcnt[x]++;
		}
		double ans = 0.0;
		for (string t : query) {
			ans += f1(t) * f2(t) * f3(t);
		}
#undef double
		double anss = ans;
		printf("%.4lf\n", anss);
	}
	return 0;
}
