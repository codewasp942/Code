#include <bits/stdc++.h>
using namespace std;

struct str {
	struct node {
		int val, cnt;
		bool operator < (node x) const {
			return val < x.val;
		}
		node(int v):val(v){}
	};
	vector<vector<node> > a;
	void insert(int v) {
		for (vector<node> &x : a) {
			vector<node>::iterator it = lower_bound(x.begin(), x.end(), node(v));
			if (it != x.end() && it -> val == v) return void(it -> cnt++);
		}
		vector<node> tmp(1, node(v));
		for (vector<node> &x : a) {
			if (!x.empty()) { for (node w : x) if (w.cnt) tmp.emplace_back(w); x.clear(); }
			else { x.swap(tmp); break; }
		}
		if (!tmp.empty()) a.emplace_back(tmp);
	}
	void remove(int v) {
		for (vector<node> &x : a) {
			vector<node>::iterator it = lower_bound(x.begin(), x.end(), node(v));
			if (it != x.end() && it -> val == v && it -> cnt) return void(it -> cnt--);
		}
	}
	int rk(int v) {
		int res = 1;
		for (vector<node> &x : a) {
			vector<node>::iterator it = lower_bound(x.begin(), x.end(), node(v));
			res += it - x.begin();
		}
		return res;
	}
	int pre(int v) {
		int res = INT_MIN;
		for (vector<node> &x : a) {
			vector<node>::iterator it = lower_bound(x.begin(), x.end(), node(v));
			do { if (it == x.begin()) goto nxt; it--; } while (it -> cnt == 0);
			res = max(res, it -> val);
			nxt:
		}
		return res;
	}
	int nxt(int v) {
		int res = INT_MAX;
		for (vector<node> &x : a) {
			vector<node>::iterator it = upper_bound(x.begin(), x.end(), node(v));
			if (it == x.end()) goto nxt;
			while (it -> cnt == 0) { it++; if (it == x.end()) goto nxt; }
			res = min(res, it -> val);
			nxt:
		}
		return res;
	}
};

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    return 0;
}