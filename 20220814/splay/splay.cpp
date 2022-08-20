#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct node;
typedef node* pos;

pos new_node(int v);
pos null();

struct node {
	pos son[2];
#define ls son[0]
#define rs son[1]
	int siz, val, cnt;
	void push_up() { siz = ls -> siz + rs -> siz + cnt; }
	//rotate with son[x]
	pos rotate(int x) {
		pos p = son[x]; 
		son[x] = p -> son[x ^ 1];
		p -> son[x ^ 1] = this;
		push_up(); p -> push_up();
		return p;
	}
	bool equal(int x, int v) {
		if (x == 0) return v == val;
		else return v > ls -> siz && v <= ls -> siz + cnt;
	}
	int compare(int x, int v) {
		if (x == 0) return v > val;
		else return v > ls -> siz + cnt;
	}
	pos splay(int x, int v) {
		if (equal(x, v)) return this;
		int f1 = compare(x, v); if (son[f1] == null()) return this;
		int f2 = son[f1] -> compare(x, v);
		if (f1 == f2 && son[f1] -> son[f2] != null()) {
			son[f1] -> son[f2] = son[f1] -> son[f2] -> splay(x, v);
			son[f1] -> push_up(); pos p = rotate(f1);
			return p -> rotate(f2);
		}
		else {
			son[f1] = son[f1] -> splay(x, v);
			push_up(); return rotate(f1);
		}
	}
};

struct tree {
	pos root;
	tree() { root = null(); }
	void insert(int v) {
		if (root == null()) root = new_node(v);
		root = root -> splay(0, v);
		if (root -> val != v) {
			pos p = root;
			root = new_node(v);
			root -> son[root -> val > v] = p;
		}
		root -> cnt++; root -> siz++;
		root -> push_up();
	}
	void erase(int v) {
		if (root == null()) return;
		root = root -> splay(0, v);
		if (root -> val != v) return;
		if (root -> rs == null()) {
			root = root -> ls;
			return;
		}
		root -> rs = root -> rs -> splay(0, v);
		root -> rs -> ls = root -> ls;
		root = root -> rs;
		root -> push_up();
	}
	int kth(int k) {
		if (root == null()) return INT_MIN;
		root = root -> splay(1, k);
		if (root -> equal(1, k)) return root -> val;
		else return INT_MIN;
	}
	int rk(int v) {
		insert(v);
		int ans = root -> ls -> siz + 1;
		erase(v);
		return ans;
	}
	int pre(int v) {
		insert(v);
		if (root -> ls == null()) return INT_MIN;
		root -> ls -> splay(0, v);
		int ans = root -> ls -> val;
		erase(v);
		return ans;
	}
	int nxt(int v) {
		insert(v);
		if (root -> rs == null()) return INT_MIN;
		root -> rs -> splay(0, v);
		int ans = root -> rs -> val;
		erase(v);
		return ans;
	}
}st;

node buf[maxn];
pos buf_pos = buf, root = buf;

pos null() { return buf; }
pos new_node(int v) {
	pos p = ++buf_pos;
	p -> ls = p -> rs = null();
	p -> siz = p -> cnt = 0;
	p -> val = v;
	return p;
}

int n;

int main() {
	freopen("splay.in", "r", stdin);
	freopen("splay.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int opt, x;
		scanf("%d %d", &opt, &x);
		switch(opt) {
			case 1: st.insert(x); break;
			case 2: st.erase(x); break;
			case 3: printf("%d\n", st.rk(x)); break;
			case 4: printf("%d\n", st.kth(x)); break;
			case 5: printf("%d\n", st.pre(x)); break;
			case 6: printf("%d\n", st.nxt(x)); break;
		}
	}
	return 0;
}

