#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
ll geti(){
    ll ret=0;char ch=getchar(),k=1;
    while((ch<'0' || ch>'9') && ch!='-')ch=getchar();
    if(ch=='-')k=0,ch=getchar();
    while(ch>='0' && ch<='9')ret=ret*10+ch-'0',ch=getchar();
    return k?ret:-ret;
}
const int N = 100;
const int mo = 1e9 + 7;
int n,k;
ll f[N][N],g[N][N],c[N][N],inv2;
ll ksm (ll a, ll b){
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mo;
        a = a*a%mo; b>>=1;
    }
    return ret;
}
int main(){
    freopen("exam.in","r",stdin);
    freopen("exam.ans","w",stdout);
    n=geti(); k=geti();
    for(int i=0;i<=n;i+=1) {
        c[i][0] = 1;
        for(int j=1;j<=i;j+=1) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mo;
        }
    }
    g[0][0]=1;// f[1][0]=1;
    inv2 = ksm(2,mo-2);
    for(int i=1;i<=n;i+=1) {
        for(int j=0;j<=i/2;j+=1) {
            for(int k=0;k<=(i-1)/2;k+=1) {
                for(int s=0;s<=j;s+=1) {
                    int a = (k!=0?k:1);
                    int b = ((i-1-k)!=0?(i-1-k):1);
                    if(k!=i-1-k || k==0) {
                        f[i][j] += g[k][s]*g[i-1-k][j-s]%mo*a%mo*b%mo*c[i-1][k]%mo;
                    } else {
                        f[i][j] += g[k][s]*g[i-1-k][j-s]%mo*a%mo*b%mo*c[i-1][k]%mo*inv2%mo;
                    }
                    f[i][j] %= mo;
                    if(j-1-s>=0) {
                        if(k!=i-1-k){
                            g[i][j] +=
                                f[k][s]*g[i-1-k][j-1-s]%mo*a%mo*b%mo*c[i-1][k]%mo+
                                g[k][s]*f[i-1-k][j-1-s]%mo*a%mo*b%mo*c[i-1][k]%mo+
                                f[k][s]*f[i-1-k][j-1-s]%mo*a%mo*b%mo*c[i-1][k]%mo;
                            g[i][j] %= mo;
                        } else {
                            g[i][j] +=
                                (
                                 f[k][s]*g[i-1-k][j-1-s]%mo*a%mo*b%mo*c[i-1][k]%mo+
                                 g[k][s]*f[i-1-k][j-1-s]%mo*a%mo*b%mo*c[i-1][k]%mo+
                                 f[k][s]*f[i-1-k][j-1-s]%mo*a%mo*b%mo*c[i-1][k]%mo
                                 )*inv2%mo;
                            g[i][j] %= mo;
                        }

                    }
                }
            }
        }
    }
    cout << (f[n][k]+g[n][k])%mo;
    return 0;
}
