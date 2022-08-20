#include "treasure.h"
#include <bits/stdc++.h>

namespace myA {
	const int maxn = 1e6 + 5;	
	vector<int> graph[maxn];
	queue<int> q;
	int dis[maxn];
}

void Alice(const int testid, const int n, const int m, const int
x, const int u[], const int v[], bool dir[]) {
	for (int i = 0; i < m; i++) {
		myA::graph[u[i]].push_back(v[i]);
		myA::graph[v[i]].push_back(u[i]);
	}
	memset(myA::dis, -1, sizeof myA::dis);
	myA::q.push(x);
	myA::dis[x] = 0;
	while (!myA::q.empty()) {
		int now = myA::q.front(); myA::q.pop();
		//cerr << now << ' ' << myA::dis[now] << '\n';
		for (int nxt : myA::graph[now]) {
			if (myA::dis[nxt] != -1) continue;
			myA::dis[nxt] = myA::dis[now] + 1;
			myA::q.push(nxt);
		}
	}
	for (int i = 0; i < m; i++) {
		dir[i] = myA::dis[u[i]] < myA::dis[v[i]];
	}
	return;
}

namespace myB {
	mt19937 myrand(time(NULL));
	inline int ri(int n) {
		return myrand() % n;
	}
}

int Bob(const int testid, const int n) {
	vector<pair<int, bool> > tmp;
	int now = myB::ri(n);
	tmp = discover(now);
	while (true) {
		bool flag = true;
		for (pair<int, bool> p : tmp) {
			if (p.second == false) {
				now = p.first;
				flag = false;
				break;
			}
		}
		if (flag) break;
		tmp = discover(now);
	}
	return now;
}
