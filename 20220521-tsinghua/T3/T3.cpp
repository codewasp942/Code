#include "treasure.h"
#include <bits/stdc++.h>

const int maxn = 1e6 + 5;

namespace myA {
	struct edge {
		int v, id;
		bool f;
		edge(int _v, int _id, bool _f) {
			v = _v, id = _id;
			f = _f;
		}
	};

	vector<edge> graph[maxn];
	queue<int> q;
	int dis[maxn];
}

void Alice(const int testid, const int n, const int m, const int
x, const int u[], const int v[], bool dir[]) {
	for (int i = 0; i < m; i++) {
		myA::graph[u[i]].push_back(myA::edge(v[i], i, true));
		myA::graph[v[i]].push_back(myA::edge(u[i], i, false));
		dir[i] = true;
	}
	memset(myA::dis, -1, sizeof myA::dis);
	myA::q.push(x);
	myA::dis[x] == 0;
	while (!myA::q.empty()) {
		int now = myA::q.front(); myA::q.pop();
		for (myA::edge e : myA::graph[now]) {
			if (myA::dis[e.v] != -1) continue;
			myA::dis[e.v] = myA::dis[now] + 1;
			myA::q.push(e.v);
			dir[e.id] = e.f;
		}
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
	int now = myB::ri();
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
