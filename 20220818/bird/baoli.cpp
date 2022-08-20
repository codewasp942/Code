#include<iostream> 
#include<cmath> 
#include<cstdio> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
const int maxn=6600000,maxn1=802; 
int first[maxn],last[maxn],nxt[maxn],value[maxn],cost[maxn],d[maxn],dui[maxn],bz[maxn],a[maxn1][maxn1]; 
int n,m,num,x,i,t,j,k,l,ans,p,m1; 
void lian(int x,int y,int z,int z1){ last[++num]=y;value[num]=z;cost[num]=z1,nxt[num]=first[x];first[x]=num; } 
int pan(int x){ if (x%m) return x%m;return m; } 
int pan1(int x){ if (x%m) return x/m;return x/m-1; } 
int dg(int x,int sum){ if (x==n+m*maxn1+1){ ans+=d[0]*sum; return sum; } int t,k,q=sum,l; bz[x]=p; for (t=first[x];t;t=nxt[t]) if (bz[last[t]]!=p && d[x]==d[last[t]]+cost[t] && value[t]){ k=dg(last[t],min(q,value[t])); if (k){ value[t]-=k; value[dui[t]]+=k; if (last[t]==n+m*maxn1+1){ for (i=1;i<=n;i++){ l=a[i][pan(x-n)]*(pan1(x-n)+2); lian(i,x+m,1,l),lian(x+m,i,0,-l),dui[num]=num-1,dui[num-1]=num; } lian(x+m,n+m*maxn1+1,1,0),lian(n+m*maxn1+1,x+m,0,0),dui[num]=num-1,dui[num-1]=num; } q-=k; if (!q) break; } } return sum-q; } 
bool pan(){ if (!p) return true; int i,j,t,k=maxn,l; for (i=0;i<=n+m*maxn1+1;i++) if (bz[i]==p) for (t=first[i];t;t=nxt[t]) if (bz[last[t]]!=p && value[t]) k=min(k,d[last[t]]+cost[t]-d[i]); if (k==maxn) return false; for (i=0;i<=n+m*maxn1+1;i++) if (bz[i]==p) d[i]+=k; return true; } 
int main(){ 
	freopen("bird.in","r",stdin); 
	freopen("bird.ans", "w", stdout);
	scanf("%d%d",&n,&m); for (i=1;i<=n;i++) scanf("%d",&x),lian(0,i,x,0),lian(i,0,0,0),dui[num]=num-1,dui[num-1]=num; for (i=1;i<=n;i++) for (j=1;j<=m;j++){ scanf("%d",&x);a[i][j]=x; lian(i,n+j,1,x),lian(n+j,i,0,-x),dui[num]=num-1,dui[num-1]=num; } for (i=n+1;i<=n+m;i++) lian(i,n+m*maxn1+1,1,0),lian(n+m*maxn1+1,i,0,0),dui[num]=num-1,dui[num-1]=num; while (pan()){ p++; while (dg(0,maxn)) p++; } printf("%d\n",ans); 
}
