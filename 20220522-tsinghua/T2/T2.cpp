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

const int maxn = 25;

stack<string> stk[maxn];
map<string, bool> vis;
map<string, vector<string> > graph;
vector<string> ans[maxn];
int n, m;

int main() {
	//printf("ok\n");
	read(m); read(n);
	for (int i = 1; i <= n; i++) {
		string s; read_s(s);
		stk[i].push(s);
	}
	for (int i = 1; i <= m; i++) {
		string u, v; read_s(u);
		//cout << u << "->";
		ch = getchar();
		ungetc(ch, stdin);
		while (ch != '\n' && ch != '\r') {
			read_s(v);
			//cout << v << ' ';
			graph[u].push_back(v);
		}
		//cout << endl;
	}
	while (true) {
		bool end = true;
		for (int i = 1; i <= n; i++) {
			while (!stk[i].empty() && vis[stk[i].top()]) stk[i].pop();
			if (stk[i].empty()) continue;
			end = false;
			string u = stk[i].top(); stk[i].pop();
			vis[u] = true;
			ans[i].push_back(u);
			for (string v : graph[u]) if (!vis[v]) stk[i].push(v);
		}
		if (end) break;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			for (char c : ans[i][j]) putchar(c);
			if (j < ans[i].size() - 1) putchar(',');
			else putchar('\n');
		}
	}
	return 0;
}
