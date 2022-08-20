#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

string buf;
vector<string> path;

void read_tagend(string tag) {
	char ch = getchar();
	string tmp;
	while (ch != EOF) {
		if (ch == '<') {
			tmp = "";
			while (ch != ' ' && ch != '>') {
				tmp += ch;
				ch = getchar();
			}
			while (ch != '>') ch = getchar();
			if (tmp == '/' + tag) return;
		}
		ch = getchar();
	}
}

inline void write_s(string s) {
	while (s[0] == ' ' || s[0] == '\n' || s[0] == '\t' || s[0] == '\r') s = string(s.begin() + 1, s.end());
	while (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\n' || s[s.size() - 1] == '\t' || s[s.size() - 1] == '\r') s = string(s.begin(), s.end() - 1);
	bool flag = false;
        for (char c : s) {
                if (c == '\t' || c == ' ' || c == '\r' || c == '\n') {
                        if (!flag) {
                                putchar(' ');
                                flag = true;
                        }
                }
                else {
                        flag = false;
                        putchar(c);
                }
        }	
}

inline bool check(string s) {
	if (s == "") return false;
	for (char c : s) if (c != ' ' && c != '\t' && c != '\r' && c != '\n') return true;
	return false;
}

inline void write(string s) {
	if (!check(s)) return;
	for (int i = 0; i < path.size(); i++) {
		write_s(path[i]);
		if (i == path.size() - 1) putchar(':');
		else putchar('>');
	}
	write_s(s);
	putchar('\n');
}

int main() {
	char ch = getchar();
	while (ch != EOF) {
		if (ch == '<') {
			write(buf);
			//for (char c : buf) printf("%d ", (int)c);
			buf = ""; ch = getchar();
			while (ch != ' ' && ch != '>') {
				buf += ch;
				ch = getchar();
			}
			while (ch != '>') ch = getchar();
			if (buf == "style" || buf == "script") read_tagend(buf);
			else if (buf[0] == '/') path.pop_back();
			else if (buf != "img") path.push_back(buf);
			buf = "";
		}
		else buf += ch;
		ch = getchar();
	}
	return 0;
}
