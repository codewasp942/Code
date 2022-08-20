#include<cstdlib>
#include<cstdio>
#include<ctime>
int main(){
	system("g++ rand.cpp -o rand -O2 -std=c++14");
	system("g++ Alice.cpp treasure.cpp -o Alice -O2 -std=c++14");
	system("g++ Bob.cpp treasure.cpp -o Bob -O2 -std=c++14");
	system("./rand");
	int t1 = clock();
	puts("Alice:");
	system("./Alice >treasure.tmp <in.tmp");
	puts("Bob:");
	system("./Bob <treasure.tmp");
	int t2 = clock();
	printf("%d\n", t2 - t1);
	return 0;
}
