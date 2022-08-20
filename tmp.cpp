#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200010];

void dfs(int u) {
    for (int v : tree[u]) {
        dfs(v);
    }
}

int n,a[200010],bel[200010],step[200010],to[200010],sz,m,l[460],r[460];
int main(){
    scanf("%d",&n);sz=sqrt(n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);bel[i]=(i-1)/sz+1;if(bel[i]!=bel[i-1])r[bel[i-1]]=i-1,l[bel[i]]=i;}r[bel[n]]=n;
    for(int i=n;i;i--){
        if(i+a[i]>r[bel[i]])to[i]=i+a[i],step[i]=1;
        else to[i]=to[i+a[i]],step[i]=step[i+a[i]]+1;
        printf("%d\n", i);
    }  
    scanf("%d",&m);
    int opt,x,y;
    while(m--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d",&x);
            int ans=0;
            for(int i=x+1;i<=n;i=to[i])ans+=step[i];
            printf("%d\n",ans);
        }
        else{
            scanf("%d%d",&x,&y);a[++x]=y;
            for(int i=x;i>=l[bel[x]];i--){
                if(i+a[i]>r[bel[x]])to[i]=i+a[i],step[i]=1;
                else to[i]=to[i+a[i]],step[i]=step[i+a[i]]+1;
            }
        }
    }
    return 0;
}
